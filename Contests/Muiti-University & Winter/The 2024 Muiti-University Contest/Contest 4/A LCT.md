# LCT

Note the **unusual memory limit** for this problem.

Given a rooted tree with $n$ nodes and $n-1$ edges. The $i$-th edge can be described by $(a_i, b_i)$, which represents an edge connecting node $a_i$ and node $b_i$, where node $a_i$ is the parent of node $b_i$.

There are $n-1$ queries. The $i$-th query contains an integer $c_i$, asking for the length of the longest simple path starting from node $c_i$ in the graph (forest) formed by the first $i$ edges. **It is guaranteed that there does not exist $j$ such that $1 \leq j \leq i$ and $b_j = c_i$, i.e., $c_i$ is the root of a tree in the forest.**

## 输入描述:

```
Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^5$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($2 \leq n \leq 10^6$), representing the number of nodes in the tree.

The next $n-1$ lines each contain three integers $a_i, b_i, c_i$ ($1 \leq a_i, b_i, c_i \leq n, a_i \neq b_i$), representing that the parent of node $b_i$ is $a_i$, and the $i$-th query is $c_i$.

It is guaranteed that:

- For each test case, the $n-1$ edges form a rooted tree.
- For each test case, for any $1 \leq i \leq n-1$, there does not exist $j$ such that $1 \leq j \leq i$ and $b_j = c_i$.
- The sum of $n$ over all test cases does not exceed $10^6$.
```

## 输出描述:

```
For each test case, output $n-1$ integers in one line. The $i$-th integer represents your answer to the $i$-th query.
```

## 样例输入

```plain
6
4
3 4 1
2 3 1
1 2 1
4
3 4 3
2 1 2
3 2 3
4
1 2 1
3 4 3
2 3 1
4
2 3 1
2 4 2
1 2 1
2
1 2 1
2
2 1 2
```

## 样例输出

```plain
0 0 3
1 1 2
1 1 3
0 1 2
1
1
```

## 示例2

### 输入

```plain
2
5
1 2 3
1 3 4
3 4 1
1 5 1
15
10 14 10
5 8 5
1 3 1
4 7 10
2 5 2
1 2 1
3 4 1
9 10 9
11 13 11
5 6 1
10 12 9
8 9 1
11 15 11
7 11 1
```

### 输出

```plain
0 0 2 2
1 1 1 1 2 3 3 2 1 3 2 6 1 6
```