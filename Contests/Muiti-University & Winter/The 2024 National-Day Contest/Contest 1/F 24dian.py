from itertools import product, combinations_with_replacement, permutations
cnt = 0
n, m = map(int, input().split())
ans = []

def evaluate_expression(exp, order):
    # 将表达式转换为操作数和操作符的列表
    def parse_expression(exp):
        tokens = []
        num = ''
        for char in exp:
            if char.isdigit():
                num += char
            else:
                if num:
                    tokens.append(int(num))
                    num = ''
                tokens.append(char)
        if num:
            tokens.append(int(num))
        return tokens

    tokens = parse_expression(exp)

    # 基于给定的优先级顺序进行计算
    def apply_operator(tokens, op):
        result = []
        i = 0
        while i < len(tokens):
            if tokens[i] == op:
                left = result.pop()  # 弹出上一个操作数
                right = tokens[i + 1]
                if op == '+':
                    result.append(left + right)
                elif op == '-':
                    result.append(left - right)
                elif op == '*':
                    result.append(left * right)
                elif op == '/':
                    result.append(left / right)  # 使用浮点除法
                # 跳过操作符和右侧操作数
                i += 2
            else:
                result.append(tokens[i])
                i += 1
        return result

    # 根据优先级顺序计算表达式
    for op_index in order:
        operators = ['*', '/', '-', '+']
        operator = operators[op_index - 1]  # 获取对应的操作符
        tokens = apply_operator(tokens, operator)

    return tokens[0]  # 返回最终的结果
'''
def can_eval(exp):
    for order in permutations(range(n - 1)):
        if evaluate_expression(exp, order) == m:
            return True
    return False
for values in combinations_with_replacement(range(1, 14), n):
    for ops in product('+-*/',repeat = n - 1):
        exp = ""
        for i in range(n - 1):
            exp += str(values[i]) + ops[i]
        exp += str(values[-1])
        #print(exp)
        if can_eval(exp) == True:
            ans.append(sorted(values))

ans = sorted(ans)
print(len(ans))
for exp in ans:
    print(" ".join(map(str, exp)))
'''
print(evaluate_expression("1+2*3-4", [1, 2, 0]))  # 3

expression = "8/4+1-1*1"
order = [3, 2, 4, 1]  # 指定的运算顺序：先乘法与除法，再减法，再加法
result = evaluate_expression(expression, order)
print(f"结果: {result}")