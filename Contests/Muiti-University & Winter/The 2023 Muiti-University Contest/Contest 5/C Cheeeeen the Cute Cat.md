# Cheeeeen the Cute Cat

## 题目描述

*本题于2023/8/1增强了数据，之前提交的代码不重测。

Chen loves bipartite graph matching problems. As a cat, Chen also loves playing with woolen balls. So she thinks the graph should be dense.

And here's The Cute Cat Matching Problem:
Given a bipartite graph with $2n$ nodes and $\frac{n(n-1)}{2}$ edges, guaranteed that there are no edges between nodes ${1,2,\dots,n}$. There are no edges between nodes ${n+1,n+2,\dots,2n}$ too. Also, there's no edge between $i$ ($1\le i\le n$) and $i+n$. If there's an edge between $i$ ($1\le i,j\le n$) and $j+n$, then there will be no edge between $j$ and $i+n$. That means the given graph guarantees that there'll be exactly one edge between $(i,j+n)$ and $(i+n,j)$.

Help Chen find the maximum matching of the given graph.

## 输入描述

The first line contains one integer $n$ ($2\le n\le 3000$), meanings the graph has $2n$ node.
For the next $n$ lines, each line while contain $n$ $01$s, forms a $01$ matrix $e$ ($e_{i,j}\in{0,1}$). If $e_{i,j}=1$, there will be an edge between node $i$ and $n+j$.

## 输出描述

One integer, means the maximum matching of the given graph.

## 示例1

### 输入

```
2
0 1
0 0
```

### 输出

```
1
```

## 示例2

### 输入

```
3
0 1 0
0 0 1
1 0 0
```

### 输出

```
3
```

## 备注

In the first sample, match node $1$ and $4$.
In the second sample, match node $1$ and $5$, $2$ and $6$, $3$ and $4$.