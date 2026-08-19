# Double Strings

## 题目描述

Given two strings $A, B_{}$, and little H wants to choose a subsequence from $\{1, 2, \cdots, |A|\}$(call it $a_{}$) and from $\{1, 2, \cdots, |B|\}$(call it $b_{}$) respectively. A scheme is called good iff $|a| = |b_{}|$ and $\exists i \in \{1, 2, \cdots, |a|\}, A_{a_i} < B_{b_i}, \forall j \in \{1, 2, \cdots, i-1\}, A_{a_j} = B_{b_j}$. Print the number of good schemes modulo $10^9+7$.

## 输入描述

The first line contains a string $A~(1\le |A| \le 5000)$.

The second line contains a string $B~(1\le |B| \le 5000)$.

It's guaranteed that $A_{}$ and $B_{}$ only contain lowercase letters.

## 输出描述

Output one line only containing one integer, denoting the answer.

## 示例1

### 输入

```
ib
coe
```

### 输出

```
5
```

### 说明

For the first case, the 5 good schemes are:

$A = \{1\}~(i), B = \{2\}~(o)_{}$

$A = \{2\}~(b), B = \{1\}~(c)_{}$

$A = \{2\}~(b), B = \{2\}~(o)_{}$

$A = \{2\}~(b), B = \{3\}~(e)_{}$

$A = \{1, 2\}~(ib), B = \{2, 3\}~(oe)_{}$

## 示例2

### 输入

```
banana
apple
```

### 输出

```
273
```