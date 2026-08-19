# Satyam and Counting

Satyam is given $n$ distinct points on the 2D coordinate plane. It is guaranteed that $0 \leq y_i \leq 1$ for all given points $(x_i, y_i)$.  
How many different nondegenerate right triangles∗ can be formed from choosing three different points as its vertices?

Two triangles $a$ and $b$ are different if there is a point $v$ such that $v$ is a vertex of $a$ but not a vertex of $b$.

∗ A nondegenerate right triangle has positive area and an interior $90^\circ$ angle.

## Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains an integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the number of points.

The following $n$ lines contain two integers $x_i$ and $y_i$ ($0 \le x_i \le n$, $0 \le y_i \le 1$) — the $i$'th point that Satyam can choose from. It is guaranteed that all $(x_i, y_i)$ are pairwise distinct.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

Output an integer for each test case, the number of distinct nondegenerate right triangles that can be formed from choosing three points.

## Sample

```input
3
5
1 0
1 1
3 0
5 0
2 1
3
0 0
1 0
3 0
9
1 0
2 0
3 0
4 0
5 0
2 1
7 1
8 1
9 1
```

```output
4
0
8
```

## Note

The four triangles in question for the first test case:

![triangles](https://espresso.codeforces.com/fa3d2396b9917bde3bc09a850f594ce163b55803.png)