# Challenge NPC 2

## 题目描述

You are given a forest. Find a Hamiltonian path for its complement graph or determine if it does not contain any Hamiltonian path.

A forest is a graph with no cycles.

A Hamiltonian path is a path which visits every vertex exactly once.

A graph $G$'s complement graph is a graph $H$ on the same vertices such that two distinct vertices of $H$ are adjacent if and only if they are not adjacent in $G$.

## 输入描述:

The first line contains one integer $T$ ($1\le T \le 10^5$), representing the number of test cases.

For each test case, the first line contains two integers $n,m$ ($2\le n \le 5 \cdot 10^5$, $0 \le m \le n - 1$), representing the number of vertices and the number of edges.

The following $m$ lines each contain two integers $u,v$ ($1\le u,v \le n$, $u \neq v$), representing an edge.

It is guaranteed that the given graph is a forest, and $\sum n \le 10^6$.

## 输出描述:

For each test case, if it is impossible to find a Hamiltonian path on the graph's complement, output $-1$ in a single line.

Otherwise, output $n$ distinct integers $p_{1},p_{2} \dots p_{n}$ ($1\le p_{i} \le n$) in a line, where edge $(p_{i},p_{i+1})$ ($1\le i < n$) is in $G$'s complement graph. If there are multiple answers, output any.

## 样例输入输出

### 示例1

输入：

```plain
5
3 2
1 2
2 3
2 0
4 3
1 2
2 3
2 4
5 2
1 5
2 3
5 4
1 2
1 3
2 4
2 5
```

输出：

```plain
-1
1 2
-1
2 1 4 3 5
1 5 4 3 2
```