# Puzzle: Wagiri

*If you can't remember which character corresponds to which rule, remember that "輪" contains a loop, and "切" doesn't!*

*--- Lavaloid*

Grammy is a puzzle master. Today, she is playing a variant of "Wagiri" puzzle.

The puzzle consists of a simple connected graph with $n$ vertices with some Chinese characters on it. Each edge has a "Lun" or "Qie" symbol on it.

The goal is to delete some of the edges to form a **connected** subgraph (including all of the vertices) such that:
- Each remaining edge with the character ``Lun'' on it must be on at least one cycle formed by the remaining edges.
- Each remaining edge with the character ``Qie'' on it must not be on any cycle formed by the remaining edges.

![图片](https://uploadfiles.nowcoder.com/images/20240801/0_1722453420965/0564D4EC4885448FC55B26B11C1AE743)![图片](https://uploadfiles.nowcoder.com/images/20240801/0_1722453430874/4A47A0DB6E60853DEDFCFDF08A5CA249)

For example, the picture on the left illustrates an unsolved puzzle, and the picture on the right shows a solution to the puzzle, in which the highlighted edges are chosen in the final subgraph.

Grammy wants to find a solution to the puzzle. Please help Grammy find a solution, or report that no solution exists.

## 输入描述:

The first line contains 2 integers $n,m$ ($1 \leq n \leq 10^5, n-1 \leq m \leq 2\times 10^5$), denoting the number of vertices and the number of edges.

Each of the next $m$ lines contains 2 integers $u_i,v_i$ ($1 \leq u_i,v_i \leq n$) and a string $t_i$ ($t_i \in \{$"Lun","Qie"$\}$), denoting that there is an edge between $u_i$ and $v_i$, and the type of this edge is $t_i$.

It is guaranteed that the given graph is a simple connected graph, that is, there are no self-loops or multiple edges, and all vertices are directly or indirectly connected by edges.

## 输出描述:

If the solution does not exist, output "NO" on a single line.

Otherwise, output "YES" on the first line, then output a single integer $m'$ ($0 \leq m' \leq m$) on the second line, followed by $m'$ lines, each of which contains two integers $u_i,v_i$, denoting a remaining edge in your solution. If there are multiple solutions, output any.

## 示例1

输入

```
4 5
1 2 Lun
1 3 Lun
1 4 Qie
2 3 Lun
3 4 Qie
```

输出

```
YES
4
1 2
1 3
2 3
1 4
```

## 示例2

输入

```
4 5
1 2 Lun
1 3 Qie
1 4 Qie
2 3 Lun
3 4 Qie
```

输出

```
NO
```