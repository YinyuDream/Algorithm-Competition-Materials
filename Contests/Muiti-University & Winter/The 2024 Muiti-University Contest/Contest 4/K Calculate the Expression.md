# Calculate the Expression

*As everyone knows, Mr. Chicken is a master of artificial intelligence. Unfortunately, the AI he trained, Little Chicken, is not very skilled. Especially in mathematics, Little Chicken cannot even correctly solve elementary arithmetic problems.*

*To improve Little Chicken’s abilities, Mr. Chicken plans to provide it with a large number of arithmetic expressions for training. Due to Little Chicken’s poor skills, Mr. Chicken will only give it expressions containing only addition and multiplication to solve.*

*However, Mr. Chicken doesn’t want to manually generate a large number of expressions. Instead, he uses a lazy method. He generates a string-stored expression and then extracts a substring from it where both ends are numbers (such a substring is guaranteed to be a valid expression). He chooses this substring as the training data for Little Chicken.*

*Of course, always extracting substrings from a fixed expression doesn’t seem very effective for training, so Mr. Chicken will occasionally modify the characters in the expression. Mr. Chicken ensures that the modified expression remains valid.*

*Now, Mr. Chicken needs your help to calculate the value of the expression to verify Little Chicken’s answers.*

Formally, Mr. Chicken provides you with a string $s$ of length $n$, containing only digits, plus signs, and multiplication sign, forming a valid expression$^{\dagger}$. Mr. Chicken will also provide a sequence of operations of the following types:

- $1$ $l$ $r$: Queries the value of the substring from the $l$-th to the $r$-th character. The substring is guaranteed to be a valid expression.
- $2$ $x$ $c$: Modifies the $x$-th character of the original expression to $c$. It is guaranteed that the modified expression $s$ remains valid.

For each query operation, output the result modulo $998,244,353$.

$^{\dagger}$ A valid expression should satisfy the following conditions:
- It contains only the digits 0-9 and the operators + and *.
- No two operators are adjacent.
- Operators do not appear at the beginning or end of the expression.

Please note that under this definition, numbers **may have leading zeros**.

## 输入描述:

```
The first line contains an integer $q$ ($1 \leq q \leq 5 \times 10^5$), representing the number of operations.

The second line contains a string $s$ ($|s| \leq 5 \times 10^5$, $s_i \in \{0 \sim 9,+,*\}$).

The next $q$ lines each contain an operation. The first number of each line is $o$, representing the type of operation:

- If $o=1$, it is followed by two integers $l$ and $r$ ($1 \leq l \leq r \leq n$), representing a query.
- If $o=2$, it is followed by an integer $x$ and a character $c$ ($1 \leq x \leq n$, $c \in \{0 \sim 9,+,*\}$), representing a modification.

It is guaranteed that all query strings and the string $s$ at any time are valid expressions.
```

## 输出描述:

```
For each query operation, output a single integer representing the result modulo $998,244,353$.
```

## 样例输入输出

### 示例1

**输入**

```
5
1+2*3
1 1 5
1 3 5
2 2 4
1 1 5
1 2 5
```

**输出**

```
7
6
426
126
```