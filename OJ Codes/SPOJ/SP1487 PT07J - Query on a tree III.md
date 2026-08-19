# Query on a tree III

## 题目描述

You are given a node-labeled rooted tree with $n$ nodes.

Define the query $(x, k)$: Find the node whose label is $k$-th largest in the subtree of the node $x$. Assume no two nodes have the same labels.

## 输入格式

The first line contains one integer $n$ ($1 \le n \le 10^5$). The next line contains $n$ integers $l_i$ ($0 \le l_i \le 10^9$) which denotes the label of the $i$-th node.

Each line of the following $n - 1$ lines contains two integers $u, v$. They denote there is an edge between node $u$ and node $v$. Node 1 is the root of the tree.

The next line contains one integer $m$ ($1 \le m \le 10^4$) which denotes the number of the queries. Each line of the next $m$ contains two integers $x, k$. ($k \le$ the total node number in the subtree of $x$.)

## 输出格式

For each query $(x, k)$, output the index of the node whose label is the $k$-th largest in the subtree of the node $x$.

## 样例输入

```
5
1 3 5 2 7
1 2
2 3
1 4
3 5
4
2 3
4 1
3 2
3 2
```

## 样例输出

```
5
4
5
5
```
