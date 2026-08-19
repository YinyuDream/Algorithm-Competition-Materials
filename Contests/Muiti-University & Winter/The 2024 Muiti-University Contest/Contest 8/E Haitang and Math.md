# Haitang and Math

## 题目描述

Haitang defines the $S(m)$ of a positive integer $m$ as the sum of digits in $m$.

For example, $S(154)=1+5+4=10$, $S(147)=1+4+7=12$.

Given a positive integer $n$, count the number of positive integers $m\le n$ such that $n\bmod m=S(m)$.

## 输入描述

```
Each test contains multiple test cases. The first line contains an integer $T$ ($1\leq T\leq 100$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains an integer $n$ ($1\leq n\leq 10^{12}$).
```

## 输出描述

```
For each test case, print one line containing an integer — the answer.
```

## 样例输入

```plain
8
11
45
14
191
9810
20061130
20080520
998244353
```

## 样例输出

```plain
1
3
0
3
17
10
3
15
```