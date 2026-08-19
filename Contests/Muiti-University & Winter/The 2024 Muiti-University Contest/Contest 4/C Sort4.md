# Sort4

## 题目描述

Given a permutation$^\dagger$ of length $n$. In one operation, you can choose **at most** four elements from the permutation and swap their positions arbitrarily. What is the minimum number of operations required to sort the permutation in ascending order?

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

## 输入描述

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^5$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^6$), indicating the length of the permutation.

The second line contains a permutation $a_1, a_2, \ldots, a_n$.

It is guaranteed that the sum of $n$ across all test cases does not exceed $10^6$.

## 输出描述

For each test case, output a single integer, indicating the minimum number of operations required to sort the permutation.

## 样例输入

```plain
4
4
4 2 1 3
6
4 2 5 1 3 6
8
5 4 6 3 1 8 2 7
10
1 2 9 10 3 6 8 4 5 7
```

## 样例输出

```plain
1
1
3
2
```