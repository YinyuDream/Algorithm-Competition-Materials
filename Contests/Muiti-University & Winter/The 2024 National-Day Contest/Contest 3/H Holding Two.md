# Holding Two

## 题目描述

Given $n,m$, construct a matrix $A$ of size $n\times m$, whose entries are all either 0 or 1, and no three distinct entries $A_{i_1,j_1}, A_{i_2,j_2}, A_{i_3,j_3}$ satisfying that $A_{i_1,j_1} = A_{i_2,j_2} = A_{i_3,j_3}, -1\le i_1-i_2=i_2-i_3\le 1, -1\le j_1-j_2=j_2-j_3\le 1$. If multiple solutions exist, print any one of them. If no solution, print "-1" in one line.

## 输入描述:

Input only one line containing two integers $n, m~(1\le n,m \le 1000)$.

## 输出描述:

If solutions exist, print $n$ lines each containing a $01$-string of length $m$, denoting the matrix you construct. If no solution, print "-1" in one line.

## 示例1

### 输入

```
3 3
```

### 输出

```
110
001
100
```