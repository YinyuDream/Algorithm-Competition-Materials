# Ama no Jaku

## 题目描述

*Let me tell you the things that I have been thinking for a long time.*

You are given an $n \times n$ matrix $A$ with each number in $A$ either $0$ or $1$.

You can do the following operation on $A$ any number of times (possibly zero):

- Choose a row or a column from $A$, and flip it (i.e. all the $0$s in that row or column become $1$s, and all the $1$s become $0$s).

Define $r_i$ as $(\overline{A_{i1}A_{i2}\dots A_{in}})_2$, which means writing all the number in the $i$-th row from left to right, forming a binary number $r_i$.

Define $c_j$ as $(\overline{A_{1j}A_{2j}\dots A_{nj}})_2$, which means writing all the number in the $j$-th column from top to bottom, forming a binary number $c_j$.

Note that $r_i$ and $c_j$ may change after operations.

Determine whether you can achieve $\min(r_i)\geq \max(c_j)$ by operations. If so, find out the minimal number of operations needed.

## 输入描述

The first line contains a positive integer $n$ ($1\leq n\leq 2000$), denoting the size of matrix $A$.

Each of the following $n$ lines contains a string consisting of $n$ 0and1s, denoting each row of matrix $A$.

## 输出描述

If it is possible to achieve $\min(r_i)\geq \max(c_j)$, print the minimal number of operations in a single line. Otherwise, print $-1$.

## 示例1

### 输入

```text
3
100
010
001
```

### 输出

```text
-1
```

## 示例2

### 输入

```text
5
00100
00100
11011
00100
00100
```

### 输出

```text
2
```