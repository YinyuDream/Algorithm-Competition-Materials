# Collinear Exception

## 题目描述

Do you know what is challenging for a geometry problem? Epsilons, NaNs, and even subnormal numbers that may affect your World Finals journey! (See ``Subnormal behavior'' section in ACM ICPC World Finals 2013 Solution sketches, Page 2)

So you dislike these floating-point issues in geometry problems. You decided to generate data containing only integral points, and moreover, ensured that no three points are collinear to avoid some divide-by-zero issues. How considerate of you!

However, everything comes with a price. It is frustrating to create a large dataset constrained within a small range --- quite often, they end up with multiple collinear triples. Therefore, you give up and use a simple greedy strategy.

Consider an $n \times n$ grid where the coordinates along both the $x$-axis and the $y$-axis range from $1$ to $n$. Within this grid, a permutation of all $n \times n$ integral points is given. Our objective is to greedily construct a maximal set $S$ using the given permutation, so that no three points in $S$ are collinear. We begin with an empty set and process each point in sequence. If the current point does not lie on any line formed by any two existing points in the set, it is added to the set; otherwise, it is skipped.

The approach is clear, but it still requires some coding work to get the job done. You need to write a program to report whether each insertion is successful.

## 输入描述

The first line contains a single integer $n~ (1 \leq n \leq 1000)$.

For the next $n \times n$ lines, each contains two integers $x_i, y_i ~ (1 \leq x_i, y_i \leq n)$, indicating the $i$-th point.

It is guaranteed that the set of points includes each point from the set $\{1, \dots, n\} \times \{1, \dots, n\}$ exactly once.

## 输出描述

Output a $\texttt{01}$ string of length $n \times n$, where the $i$-th character is $\texttt{1}$ indicates whether the $i$-th point was successfully inserted into the set.

## 样例输入

```plain
3
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2
3 3
```

## 样例输出

```plain
110110000
```