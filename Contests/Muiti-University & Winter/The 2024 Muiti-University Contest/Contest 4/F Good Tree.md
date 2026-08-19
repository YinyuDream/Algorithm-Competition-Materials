# Good Tree

## 题目描述

Given a tree where all edge weights are $1$, define $f(u)=\sum_v dis(u,v)$, where $v$ represents all nodes in the tree, and $dis(u,v)$ is the length of the simple path between node $u$ and node $v$.

A tree is called “good” if there exist two nodes $u$ and $v$ such that $f(u)-f(v)=x$. Given integer $x$, determine the minimum number of nodes required for the tree to be “good”.

## 输入描述

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^5$). The description of the test cases follows.

Each test case contains an integer $x(1\le x\le 10^{18})$, representing the value for which you need to determine the minimum number of nodes required for the tree to be “good”.

## 输出描述

For each test case, output a single integer, representing the minimum number of nodes required for the tree to be “good”.

It can be shown that the answer always exists.

## 样例输入输出

### 样例输入

```
3
2
3
114514
```

### 样例输出

```
4
5
678
```