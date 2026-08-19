# Intervals

## 题目描述

You are given $n$ closed integer intervals $[a_i, b_i]$ and $n$ integers $c_1, \ldots, c_n$.

Write a program that:

- reads the number of intervals, their endpoints and integers $c_1, \ldots, c_n$ from the standard input,
- computes the minimal size of a set $Z$ of integers which has at least $c_i$ common elements with interval $[a_i, b_i]$, for each $i = 1, 2, \ldots, n$,
- writes the answer to the standard output.

## 输入格式

The input begins with the integer $t$, the number of test cases. Then $t$ test cases follow.

For each test case the first line of the input contains an integer $n$ ($1 \le n \le 50000$) — the number of intervals. The following $n$ lines describe the intervals. Line $(i+1)$ of the input contains three integers $a_i, b_i$ and $c_i$ separated by single spaces and such that $0 \le a_i \le b_i \le 50000$ and $1 \le c_i \le b_i - a_i + 1$.

## 输出格式

For each test case the output contains exactly one integer equal to the minimal size of set $Z$ sharing at least $c_i$ elements with interval $[a_i, b_i]$, for each $i = 1, 2, \ldots, n$.

## 样例输入

```
1
5
3 7 3
8 10 3
6 8 1
1 3 1
10 11 1
```

## 样例输出

```
6
```

## 提示

Warning: enormous Input/Output data, be careful with certain languages.
