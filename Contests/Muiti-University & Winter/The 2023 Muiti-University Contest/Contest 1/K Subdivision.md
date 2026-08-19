# K-Subdivision

## 题目描述

You are given a graph with $n$ vertices and $m$ undirected edges of length $1$. You can do the following operation on the graph for arbitrary times:

> Choose an edge $(u,v)$ and replace it by two edges, $(u,w)$ and $(w,v)$, where $w$ is a newly inserted vertex. Both of the two edges are of length $1$.

You need to find out the maximum number of vertices whose minimum distance to vertex $1$ is no more than $k$.

## 输入描述

The first line contains three integers $n\ (1\leq n\leq 10^5)$, $m\ (0 \leq m \leq 2\cdot 10^5)$ and $k\ (0\leq k\leq 10^9)$.
Each of the next $m$ lines contains two integers $u$ and $v\ (1\leq u,v\leq n)$, indicating an edge between $u$ and $v$. It is guaranteed that there are no self-loops or multiple edges.

## 输出描述

Output an integer indicating the maximum number of vertices whose minimum distance to vertex $1$ is no more than $k$.

## 样例输入

```plain
5 4 2
1 2
2 3
3 1
4 5
```

## 样例输出

```plain
5
```

## 样例输入

```plain
8 9 3
1 2
1 3
1 5
3 4
3 6
4 5
5 6
6 7
7 8
```

## 样例输出

```plain
15
```

## 样例输入

```plain
114 0 514
```

## 样例输出

```plain
1
```

## 备注

Here is the illustration for the second example.

![image](https://uploadfiles.nowcoder.com/images/20230717/0_1689574090396/EDC585D199EEEC167C6B17F17085A1FA)