# MST

## 题目描述

Sajin has recently delved into the study of minimum spanning trees and now he has mastered the algorithm of MST.

He is eager to assess your grasp of minimum spanning tree concepts through a series of queries.

You are confronted with an weighted undirected graph that encompasses $n$ vertices and $m$ edges without any self-loops.

Sajin presents $q$ inquiries. For each, a vertex set $S$ is given. Your objective is to determine the **induced subgraph** of $S$ and find the weight of its minimum spanning tree.

A minimum spanning tree (MST) is a subset of the edges of a connected, edge-weighted graph that connects all the vertices together without any cycles and with the minimum possible total edge weight.

In the mathematical field of graph theory, an **induced subgraph** of a graph is another graph, formed from a subset of the vertices of the graph and all of the edges, from the original graph, connecting pairs of vertices in that subset.

If the **induced subgraph** of $S$ is disconnected, output -1.

## 输入描述:

The first line contains $3$ integers $n$, $m$, $q$ ($2 \le n \le 10^5,1 \le m, q \le 10^5$), — the number of points, the number of edges, and the number of queries.

Then $m$ lines follow, each line contains three integers $u_i$, $v_i$, $w_i$($1 \le u_i, v_i \le n$, $u_i \ne v_i$, $1 \le w_i \le 10^9$), — the two endpoints of the $i$-th edge and the edge weight.

Next $q$ lines, each line first contains an integer $k_i$ ($1 \le k_i \le n$) — the size of the vertex set $S$ for the $i$-th query.

Then followed by $k_i$ **distinct** integers $s_{i,j}$($1 \le s_{i,j} \le n$) — the numbers of the vertex set $S$ for the $i$-th query.

It is guaranteed that the sum of $k_i$ over all queries does not exceed $10^5$.

## 输出描述:

For each query, output one integer representing the answer.

## 样例输入

```plain
5 10 5
1 2 1
1 3 1
1 4 1
1 5 1
2 3 2
2 4 2
2 5 2
3 4 3
3 5 3
4 5 4
5 1 2 3 4 5
4 2 3 4 5
3 3 4 5
2 4 5
1 5
```

## 样例输出

```plain
4
6
6
4
0
```

## 样例输入

```plain
3 2 1
1 2 1
2 3 1
2 1 3
```

## 样例输出

```plain
-1
```