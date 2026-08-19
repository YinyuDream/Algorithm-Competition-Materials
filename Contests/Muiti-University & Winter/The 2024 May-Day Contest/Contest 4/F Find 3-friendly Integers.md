# Find 3-friendly Integers

## 题目描述

A positive integer is 3-friendly if and only if we can find a continuous substring in its decimal representation, and the decimal integer represented by the substring is a multiple of $3$.

For instance:

1. $104$ is 3-friendly because "0" is a substring of "104" and $0 \mod 3 = 0$.
2. $124$ is 3-friendly because "12" is a substring of "124" and $12 \mod 3 = 0$. "24" is also a valid substring.
3. $17$ is not 3-friendly because $1 \mod 3 \ne 0, ~7 \mod 3 \ne 0, ~17 \mod 3 \ne 0$.

Note that the substring with leading zeros is also considered legal.

Given two integers $L$ and $R$, you are asked to tell the number of positive integers $x$ such that $L \le x \le R$ and $x$ is 3-friendly.

## 输入描述

There are multiple test cases. The first line of the input contains an integer $T(1 \le T \le 10000)$, indicating the number of test cases. For each test case:

The only line contains two integers $L,R(1 \le L \le R \le 10^{18})$, indicating the query.

## 输出描述

For each test case output one line containing an integer, indicating the number of valid $x$.

## 示例

### 输入

```text
3
4 10
1 20
1 100
```

### 输出

```text
3
11
76
```