# 入

## 题目描述

There is an undirected graph where each vertex has a unique weight $a_i$.

Initially, a chess piece is placed on a vertex. In each move, the piece moves to the adjacent vertex with the smallest weight. If all adjacent vertices have weights greater than the current vertex, the movement stops immediately.

You can freely assign weights $a_i$ to the vertices (ensuring they are all unique) and choose the initial position of the chess piece. Your goal is to maximize the number of vertices visited by the chess piece.

## 输入描述:

The first line contains two positive integers $n, m$.

The next $m$ lines each contain two positive integers $u, v$, indicating an edge in the graph.

## 输出描述:

Output a single integer, which is the maximum number of vertices visited by the chess piece.

## 样例输入

```plain
4 5
3 4
2 4
1 4
1 2
1 3
```

## 样例输出

```plain
3
```

## 样例输入

```plain
6 8
4 6
1 6
4 5
5 6
2 5
2 4
2 6
3 5
```

## 样例输出

```plain
4
```

## 备注:

$1 \leq n \leq 40, 1 \leq m \leq \binom{n}{2}, 1\leq u, v \leq n$.