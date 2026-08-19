# Koraidon, Miraidon and DFS Shortest Path

## 题目描述

One day, Koraidon gave Miraidon a **directed** graph with $n$ vertices and $m$ edges. The weights of all edges are $1$. Koraidon asked Miraidon to calculate the shortest path from vertex $1$ to each vertex. It is guaranteed that vertex $1$ can reach all other vertices through the edges.

However, Miraidon just forgot the BFS algorithm. He tried to use the DFS algorithm as a replacement. The algorithm looks like:

![DFS algorithm](https://uploadfiles.nowcoder.com/images/20230723/0_1690079247802/280FE03A8FA32265066418938742C817)

In line $4$, Miraidon tried to use a random shuffle function to get a correct answer. The shuffles in different recursive calls of DFS are mutually independent.

Koraidon judged the answer given by Miraidon very strictly. He would consider the algorithm correct if and only if the algorithm gives correct answers on all possible random shuffle results.

Please help Miraidon check whether his DFS algorithm is correct on the given graph.

## 输入描述

Each test contains multiple test cases.

The first line contains an integer $T$ ($1 \le T \le 5 \times 10^{5}$) – the number of test cases.

For each test case:

The first line contains two integers $n,m$ ($1 \le n,m \le 5 \times 10^{5}$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u,v \le n$), denoting a directed edge from $u$ to $v$. The graph is **not** guaranteed to be a simple directed graph. But it is guaranteed that vertex $1$ can reach all other vertices through the edges.

It is guaranteed that the sum of $n$ and the sum of $m$ over all test cases do not exceed $5 \times 10^{5}$.

## 输出描述

For each test case, print "Yes" if the algorithm is correct on this graph, and "No" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## 示例

### 输入

```
2
3 3
1 2
2 3
3 1
3 3
1 2
1 3
2 3
```

### 输出

```
Yes
No
```

## 备注

For the first example, there is only one possible DFS order, which is $1 \to 2 \to 3$. The distance from vertex $1$ to vertex $1, 2, 3$ are $0, 1, 2$, respectively. They are exactly the shortest paths. So the algorithm is correct on this graph.

For the second example, consider the following DFS order: $1 \to 2 \to 3$. The distance of vertex $3$ is $2$, while the shortest path has length $1$ ($1 \to 3$). So the algorithm is wrong on this graph.