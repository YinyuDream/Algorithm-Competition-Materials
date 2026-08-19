# Until the Blue Moon Rises

## 题目描述

You are given an array $A = (A_1, A_2, \dots, A_n)$ of $n$ positive integers.

You can do the following operation any number of times (possibly, zero) on $A$:

- Choose two **distinct** indices $i, j$ ($1 \leq i, j \leq n$), then let $A_i = A_i + 1, A_j = A_j - 1$.

Determine whether you can make all the integers in the array $A$ prime numbers by applying the operations.

Recall that a prime number is a positive integer greater than $1$ that is not a product of two smaller positive integers.

## 输入描述

The first line contains an integer $n$ ($1 \leq n \leq 1000$) — the length of array $A$.

The second line contains $n$ positive integers $A_1, A_2, \dots, A_n$ ($1 \leq A_i \leq 10^9$) — the integers in $A$.

## 输出描述

If it is possible to make all the integers in the array $A$ prime numbers, print 'Yes' in a single line (without quotes). Otherwise, print 'No' (without quotes).

## 示例1

### 输入

```
5
10 8 2 3 5
```

### 输出

```
Yes
```