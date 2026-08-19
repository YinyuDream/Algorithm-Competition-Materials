# Beautiful Sequence

## 题目描述

Students from Antarctic Penguin Language School are studying sequence.

We call a sequence $A=(A_1, A_2, \dots, A_n)$ of length $n$ beautiful when all the following conditions are true:

- $A_1 \le A_2 \le \dots \le A_n$
- For each $A_i$ ($1\le i\le n$), $0\le A_i<2^{30}$
- For each $1\le i<n$, $A_i\oplus A_{i+1}=B_i$, where $B$ is a given sequence, and $\oplus$ represents bitwise XOR.

You need to find the $k$-th smallest lexicographically legal beautiful sequence $A$.

## 输入描述

Each test contains multiple test cases. The first line contains the number of test cases $T$. The description of the test cases follows.

The first line contains two integers $n$, $k$ ($1\le n\le 10^6$, $1\le k\le 2^{30}$).

The second line contains $n-1$ integers $B_1, B_2, \dots, B_{n-1}$ ($0\le B_i < 2^{30}$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

## 输出描述

For each test case, output your operations in the following format.

If the number of beautiful sequences is less than $k$, output one line containing an integer $-1$.

Otherwise, output one line containing $n$ integers $A_1, A_2, \dots, A_n$ separated by spaces — the $k$-th smallest lexicographically legal beautiful sequence.

## 示例

### 输入

```input
3
3 3
1 2
5 1
1 2 1 2
2 1
0
```

### 输出

```output
8 9 11
-1
0 0
```