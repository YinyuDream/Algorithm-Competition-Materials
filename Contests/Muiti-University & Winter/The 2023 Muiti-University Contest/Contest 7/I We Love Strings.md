# We Love Strings

## 题目描述

We have n strings $s_i$ which only contain `01?`. `?` means it can match either $0$ or $1$.

You need to find how many $01$ strings are there which matches at least one of these strings.

## 输入描述

The first line contains one integer $n(1\leq n\leq 400)$.

The next $n$ lines, the $i$-th line contains a string $s_i(1\leq \sum|s_i|\leq 400)$.

## 输出描述

Output the answer modulo $998244353$ in one line.

## 示例1

### 输入

```text
3
10?
?0?
?11
```

### 输出

```text
6
```