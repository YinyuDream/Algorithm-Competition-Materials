# Equalize by Divide

## Problem Description

You are given an array $a_1, a_2, \ldots, a_n$ of positive integers.

You can make this operation multiple (possibly zero) times:

- Choose two indices $i$, $j$ ($1 \le i, j \le n$, $i \neq j$).
- Assign $a_i := \lceil \frac{a_i}{a_j} \rceil$. Here $\lceil x \rceil$ denotes $x$ rounded up to the smallest integer $\ge x$.

Is it possible to make all array elements equal by some sequence of operations (possibly empty)? If yes, print any way to do it in at most $30n$ operations.

It can be proven, that under the problem constraints, if some way exists to make all elements equal, there exists a way with at most $30n$ operations.

## Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. Descriptions of test cases follow.

The first line of each test case description contains a single integer $n$ ($1 \le n \le 100$).

The second line of each test case description contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

It is guaranteed, that the sum of $n$ for all test cases does not exceed $1000$.

## Output

For each test case print a single integer $q$ ($-1 \le q \le 30n$). If $q = -1$, there is no solution, otherwise $q$ is equal to the number of operations.

If $q \ge 0$, on the next $q$ lines print two integers $i$, $j$ ($1 \le i, j \le n$, $i \neq j$) — descriptions of operations.

If there are multiple solutions, you can print any.

## Sample

```input
10
1
100
3
1 1 1
2
2 1
2
5 5
3
4 3 2
4
3 3 4 4
2
2 100
5
5 3 6 7 8
6
3 3 80 3 8 3
4
19 40 19 55
```

```output
0
0
-1
0
2
1 3
2 1
4
3 1
4 2
1 3
2 4
6
2 1
2 1
2 1
2 1
2 1
2 1
2 1
8
5 2
4 2
3 2
1 3
1 3
2 1
4 1
5 1
4
5 1
3 1
3 1
3 1
9
4 2
2 1
1 2
1 2
3 2
3 2
1 4
2 4
3 4
```

## Note

In the first and second, fourth test cases all numbers are equal, so it is possible to do nothing.

In the third test case, it is impossible to make all numbers equal.

In the fifth test case: $[\color{red}{4}, 3, \color{blue}{2}] \to [\color{blue}{2}, \color{red}{3}, 2] \to [2, 2, 2]$.

In the sixth test case: $[\color{blue}{3}, 3, \color{red}{4}, 4] \to [3, \color{blue}{3}, 2, \color{red}{4}] \to [\color{red}{3}, 3, \color{blue}{2}, 2] \to [2, \color{red}{3}, 2, \color{blue}{2}] \to [2, 2, 2, 2]$.

Here the red numbers are $i$ indices (that will be assigned), blue numbers are $j$ indices.