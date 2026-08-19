# Distance

## 题目描述

For the two multisets $A$ and $B$, In an operation, we can choose one between the following two operations:

1. Update an element $a_i$ in the multiset $A$, to $a_i=a_i+1$

2. Update an element $b_i$ in the multiset $B$, to $b_i=b_i+1$

We define $C(A,B)$ as the minimum number of operations to make the multisets $A$ and $B$ identical, meaning that both multisets have the same elements. If there is no way to transform multisets $A$ and $B$ into the same multiset, then $C(A,B)=0$.

Now you have two multisets $S$ and $T$, and calc the value of $\sum\limits_{A\subseteq S}\sum\limits_{B\subseteq T}C(A,B)$ modulo $998244353$.

Note: Subsets in the multiset are allowed to duplicate values, that is, the number of solutions selected from each of the two sets $S$ and $T$ is $(2^{|S|}-1)(2^{|T|}-1)$.

## 输入描述

The first line contains a positive integer $n\ (1\leq n\leq 2\times 10^3)$, representing the size of the multiset $S$ and the multiset $T$.

The second line contains a line of $n$ positive integers $s_i \ (1\leq s_i\leq 10^5)$, representing the multiset $S$.

The third line contains a line of $n$ positive integers $t_i\ (1\leq t_i\leq 10^5)$, representing the multiset $T$.

The input sequence is not guaranteed to be ordered.

## 输出描述

Output a line with a integer representing the answer, modulo $998244353$.

## 示例1

### 输入

```
2
1 2
1 1
```

### 输出

```
3
```

### 说明

```
A={2} B={1} C(A,B)=1
A={2} B={1} C(A,B)=1
A={1 2} B={1 1} C(A,B)=1
```

## 示例2

### 输入

```
3
1 2 2
1 1 3
```

### 输出

```
22
```