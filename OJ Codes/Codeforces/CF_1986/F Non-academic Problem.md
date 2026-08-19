# Non-academic Problem

## Problem Description

You are given a connected undirected graph, the vertices of which are numbered with integers from $1$ to $n$. Your task is to minimize the number of pairs of vertices $1 \leq u < v \leq n$ between which there exists a path in this graph. To achieve this, you can remove exactly one edge from the graph.

Find the smallest number of pairs of vertices!

## Input

Each test consists of several sets of input data. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of sets of input data. Then follows their description.

The first line of each set of input data contains two integers $n$ and $m$ ($2 \leq n \leq 10^5$, $n - 1 \leq m \leq \min(10^5, \frac{n \cdot (n - 1)}{2})$) — the number of vertices in the graph and the number of edges.

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \leq u, v \leq n, u \neq v$), indicating that there is an undirected edge in the graph between vertices $u$ and $v$.

It is guaranteed that the given graph is connected and without multiple edges.

It is guaranteed that the sum of $n$ and the sum of $m$ over all sets of input data does not exceed $2 \cdot 10^5$.

## Output

For each set of input data, output the smallest number of pairs of reachable vertices, if exactly one edge can be removed.

## Sample

```input
6
2 1
1 2
3 3
1 2
2 3
1 3
5 5
1 2
1 3
3 4
4 5
5 3
6 7
1 2
1 3
2 3
3 4
4 5
4 6
5 6
5 5
1 2
1 3
2 3
2 4
3 5
10 12
1 2
1 3
2 3
2 4
4 5
5 6
6 7
7 4
3 8
8 9
9 10
10 8
```

```output
0
3
4
6
6
21
```

## Note

In the first set of input data, we will remove the single edge $(1, 2)$ and the only pair of vertices $(1, 2)$ will become unreachable from each other.

In the second set of input data, no matter which edge we remove, all vertices will be reachable from each other.

In the fourth set of input data, the graph looks like this initially.

![Graph](https://espresso.codeforces.com/374872f585ce28149acd3b381875efadf03e3f9f.png)

We will remove the edge $(3, 4)$ and then the only reachable pairs of vertices will be $(1, 2)$, $(1, 3)$, $(2, 3)$, $(4, 5)$, $(4, 6)$, $(5, 6)$.

![Graph after removal](https://espresso.codeforces.com/adb68230f3dce64b691c34d8c62b1aae1d001832.png)

In the sixth set of input data, the graph looks like this initially.

![Graph](https://espresso.codeforces.com/af198d53b65fc93300eea0a58cf54fbbf3f62159.png)

After removing the edge $(2, 4)$, the graph will look like this. Thus, there will be $21$ pairs of reachable vertices.

![Graph after removal](https://espresso.codeforces.com/c6412c8719740b67fbeec45ec0428b1bf6adc5c4.png)