import sys
import re
from math import inf
from itertools import combinations

class Table:
    def __init__(self, name, alias, is_base=True, base_rows=0, columns=None, subquery=None):
        self.name = name
        self.alias = alias
        self.is_base = is_base
        self.base_rows = base_rows
        self.columns = columns if columns else {}
        self.subquery = subquery
        self.filtered_rows = base_rows
        self.cost = 0.0
        self.conditions = []

class Condition:
    def __init__(self, left, right, condition_type):
        self.left = left  # table.column
        self.right = right  # table.column or constant or subquery
        self.type = condition_type  # 'join', 'filter', 'sublink'

class QueryOptimizer:
    def __init__(self, tables_info, sql):
        self.tables_info = tables_info
        self.sql = sql
        self.tables = []
        self.conditions = []
        self.table_map = {}
        self.parse_sql()
    
    def parse_sql(self):
        sql = self.sql.upper()
        
        # Extract FROM clause
        from_match = re.search(r'FROM\s+(.*?)(?:\s+WHERE|\s*;)', self.sql, re.IGNORECASE | re.DOTALL)
        if not from_match:
            return
        
        from_clause = from_match.group(1).strip()
        
        # Parse tables in FROM clause
        table_strs = self.split_by_comma(from_clause)
        for table_str in table_strs:
            table_str = table_str.strip()
            if table_str.startswith('('):
                # Subquery
                end_idx = table_str.rfind(')')
                subquery_sql = table_str[1:end_idx].strip()
                alias_part = table_str[end_idx+1:].strip()
                alias = self.parse_alias(alias_part)
                
                # Recursively optimize subquery
                subquery_optimizer = QueryOptimizer(self.tables_info, subquery_sql)
                subquery_rows, subquery_cost = subquery_optimizer.optimize()
                
                # For simplicity, assume all columns from subquery have NDV = subquery_rows
                columns = {f"col_{i}": subquery_rows for i in range(10)}  # Approximation
                
                table = Table(alias, alias, False, subquery_rows, columns, subquery_optimizer)
                table.filtered_rows = subquery_rows
                table.cost = subquery_cost
                
            else:
                # Base table
                parts = table_str.split()
                if len(parts) == 1:
                    name = alias = parts[0]
                else:
                    if parts[1].upper() == 'AS':
                        name = parts[0]
                        alias = parts[2]
                    else:
                        name = parts[0]
                        alias = parts[1]
                
                if name in self.tables_info:
                    base_rows, columns = self.tables_info[name]
                    table = Table(name, alias, True, base_rows, columns)
                else:
                    # Table not found in info, use defaults
                    table = Table(name, alias, True, 1000, {})
            
            self.tables.append(table)
            self.table_map[table.alias] = table
        
        # Extract WHERE clause
        where_match = re.search(r'WHERE\s+(.*?);', self.sql, re.IGNORECASE | re.DOTALL)
        if where_match:
            where_clause = where_match.group(1).strip()
            condition_strs = self.split_by_and(where_clause)
            
            for condition_str in condition_strs:
                condition_str = condition_str.strip()
                if 'SELECT COUNT(*)' in condition_str.upper():
                    # Sublink condition
                    match = re.match(r'(.*?)\s*=\s*\(\s*SELECT\s+COUNT\(\*\)\s+FROM\s+(.*?)\s+WHERE\s+(.*?)\s*\)', condition_str, re.IGNORECASE)
                    if match:
                        left = match.group(1).strip()
                        subquery_from = match.group(2).strip()
                        subquery_where = match.group(3).strip()
                        
                        # Simple check for correlation
                        is_correlated = any(table.alias in subquery_where for table in self.tables)
                        
                        condition = Condition(left, f"SELECT COUNT(*) FROM {subquery_from} WHERE {subquery_where}", 'sublink')
                        self.conditions.append(condition)
                        
                        # Add to corresponding table
                        table_alias = left.split('.')[0]
                        if table_alias in self.table_map:
                            self.table_map[table_alias].conditions.append(condition)
                else:
                    # Regular condition
                    parts = condition_str.split('=')
                    if len(parts) == 2:
                        left = parts[0].strip()
                        right = parts[1].strip()
                        
                        # Check if it's a join or filter
                        left_parts = left.split('.')
                        right_parts = right.split('.')
                        
                        if len(left_parts) == 2 and len(right_parts) == 2:
                            # Both are table.column - join condition
                            condition = Condition(left, right, 'join')
                        else:
                            # One side is constant - filter condition
                            condition = Condition(left, right, 'filter')
                        
                        self.conditions.append(condition)
                        
                        # Add to corresponding table
                        table_alias = left.split('.')[0]
                        if table_alias in self.table_map:
                            self.table_map[table_alias].conditions.append(condition)
    
    def split_by_comma(self, s):
        result = []
        current = ""
        paren_count = 0
        
        for char in s:
            if char == '(':
                paren_count += 1
            elif char == ')':
                paren_count -= 1
            elif char == ',' and paren_count == 0:
                result.append(current.strip())
                current = ""
                continue
            current += char
        
        if current.strip():
            result.append(current.strip())
        
        return result
    
    def split_by_and(self, s):
        result = []
        current = ""
        paren_count = 0
        
        for char in s:
            if char == '(':
                paren_count += 1
            elif char == ')':
                paren_count -= 1
            elif char.upper() == 'A' and paren_count == 0:
                # Check for AND
                if s[s.index(char):s.index(char)+3].upper() == 'AND':
                    result.append(current.strip())
                    current = ""
                    continue
            current += char
        
        if current.strip():
            result.append(current.strip())
        
        return result
    
    def parse_alias(self, s):
        s = s.strip()
        if s.upper().startswith('AS '):
            return s[3:].strip()
        return s
    
    def compute_table_costs(self):
        for table in self.tables:
            if table.is_base:
                # Compute filtered rows and cost for base table
                filtered_rows = table.base_rows
                cost = table.base_rows * 0.1  # Base scan cost
                
                # Apply filter conditions
                for condition in table.conditions:
                    if condition.type == 'filter':
                        # Simple equality filter
                        col_name = condition.left.split('.')[1]
                        if col_name in table.columns:
                            ndv = table.columns[col_name]
                            filtered_rows /= ndv
                    
                    elif condition.type == 'sublink':
                        # Sublink condition - treat as filter on the column
                        col_name = condition.left.split('.')[1]
                        if col_name in table.columns:
                            ndv = table.columns[col_name]
                            filtered_rows /= ndv
                        
                        # Add sublink cost
                        subquery_sql = condition.right
                        subquery_optimizer = QueryOptimizer(self.tables_info, subquery_sql)
                        subquery_rows, subquery_cost = subquery_optimizer.optimize()
                        
                        # Check if correlated
                        is_correlated = any(t.alias in subquery_sql for t in self.tables)
                        
                        if is_correlated:
                            cost += table.base_rows * subquery_cost
                        else:
                            cost += subquery_cost
                
                table.filtered_rows = filtered_rows
                table.cost = cost
    
    def compute_join_selectivity(self, set1, set2, dp):
        selectivity = 1.0
        
        for condition in self.conditions:
            if condition.type == 'join':
                left_table = condition.left.split('.')[0]
                right_table = condition.right.split('.')[0]
                
                left_in_set1 = any(table.alias == left_table for table in set1)
                right_in_set2 = any(table.alias == right_table for table in set2)
                
                left_in_set2 = any(table.alias == left_table for table in set2)
                right_in_set1 = any(table.alias == right_table for table in set1)
                
                if (left_in_set1 and right_in_set2) or (left_in_set2 and right_in_set1):
                    # This join condition applies
                    left_col = condition.left.split('.')[1]
                    right_col = condition.right.split('.')[1]
                    
                    # Find NDVs
                    left_ndv = 1
                    right_ndv = 1
                    
                    for table in self.tables:
                        if table.alias == left_table and left_col in table.columns:
                            left_ndv = table.columns[left_col]
                        if table.alias == right_table and right_col in table.columns:
                            right_ndv = table.columns[right_col]
                    
                    selectivity *= 1.0 / max(left_ndv, right_ndv)
        
        return selectivity
    
    def optimize(self):
        self.compute_table_costs()
        
        n = len(self.tables)
        if n == 0:
            return 0.0, 0.0
        
        # DP table: dp[bitmask] = (rows, cost)
        dp = [None] * (1 << n)
        
        # Initialize with single tables
        for i in range(n):
            dp[1 << i] = (self.tables[i].filtered_rows, self.tables[i].cost)
        
        # Enumerate all subsets
        for mask in range(1, 1 << n):
            if dp[mask] is None:
                continue
            
            # Try to extend the current subset
            for i in range(n):
                if mask & (1 << i):
                    continue
                
                new_mask = mask | (1 << i)
                new_table = self.tables[i]
                
                # Calculate join properties
                left_rows, left_cost = dp[mask]
                right_rows, right_rows_base = new_table.filtered_rows, new_table.filtered_rows
                right_cost = new_table.cost
                
                # Compute selectivity
                left_tables = [self.tables[j] for j in range(n) if mask & (1 << j)]
                right_tables = [new_table]
                selectivity = self.compute_join_selectivity(left_tables, right_tables, dp)
                
                join_rows = left_rows * right_rows * selectivity
                
                # Calculate costs for both join methods
                hash_cost = (left_cost + right_cost + 
                           right_rows * 1.5 + left_rows * 3.5 + 
                           join_rows * 0.1)
                
                nested_loop_cost = (left_cost + right_cost + 
                                  left_rows * right_rows * 1.0 + 
                                  join_rows * 0.1)
                
                total_cost = min(hash_cost, nested_loop_cost)
                
                # Update DP table
                if dp[new_mask] is None or total_cost < dp[new_mask][1]:
                    dp[new_mask] = (join_rows, total_cost)
        
        return dp[(1 << n) - 1]

def main():
    data = sys.stdin.read().splitlines()
    if not data:
        return
    
    # Parse table information
    n = int(data[0].strip())
    tables_info = {}
    index = 1
    
    for _ in range(n):
        parts = data[index].split()
        index += 1
        table_name = parts[0]
        col_count = int(parts[1])
        row_count = int(parts[2])
        
        columns = {}
        for _ in range(col_count):
            col_parts = data[index].split()
            index += 1
            col_name = col_parts[0]
            ndv = int(col_parts[1])
            columns[col_name] = ndv
        
        tables_info[table_name] = (row_count, columns)
    
    # Parse SQL query
    sql_lines = []
    while index < len(data):
        line = data[index].strip()
        if not line:
            index += 1
            continue
        sql_lines.append(line)
        if line.endswith(';'):
            break
        index += 1
    
    sql = ' '.join(sql_lines)
    
    # Optimize query
    optimizer = QueryOptimizer(tables_info, sql)
    final_rows, total_cost = optimizer.optimize()
    
    # Output result
    print(f"{final_rows:.2f} {total_cost:.2f}")

if __name__ == "__main__":
    main()