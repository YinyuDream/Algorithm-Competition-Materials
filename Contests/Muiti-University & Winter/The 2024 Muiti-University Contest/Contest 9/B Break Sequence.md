# Break Sequence

## 题目描述

Given a sequence $a$ length $n$ and a set $S$ size $m$.

Count the number of sequence $0=p_0<p_1<p_2<\dots<p_k<p_{k+1}=n$ such that:
For any $0\leq i\leq k$, $x\in S$ and $1\leq j\leq n$, $\sum_{l=p_i+1}^{p_{i+1}}[a_l=j]\neq x$.

## 输入描述

```
Line 1: Two integers $n,m$.
Line 2: $n$ integers, indicating sequence $a$.
Line 3: $m$ integers, indicating set $S$.
```

## 输出描述

```
Line 1: An integer, the answer, modulo $998244353$.
```

## 样例输入

```plaintext
5 1
1 2 3 1 3
2
```

## 样例输出

```plaintext
11
```

## 样例输入

```plaintext
25 2
2 1 1 3 5 1 4 3 3 1 1 1 4 5 3 4 4 3 2 3 5 2 1 3 1
5 4
```

## 样例输出

```plaintext
16411172
```

## 备注

$1\leq n\leq 2\times10^5$.

$0\leq m\leq 10$.

$1\leq a_i\leq n$.

All integers in set $S$ are between $1$ and $n$.