# C. Symmetrical Polygons

## Statement

You are given $n$ sticks, where the $i$-th stick has a length of $a_i$. You want to choose a non-empty subset of these sticks and use them as the sides of a polygon. Each selected stick must be used entirely as a single side of the polygon. It is **not** allowed for two or more sticks to be joined end-to-end in parallel to form a longer side.

Your goal is to form a polygon that is symmetrical, strictly convex, and non-degenerate:

- **Symmetrical**: there exists a line of symmetry such that when the polygon is folded along this line, the two halves coincide exactly.
- **Strictly convex**: all its internal angles are strictly less than $180^\circ$.
- **Non-degenerate**: no two consecutive sides coincide at least partially, no side has zero length, and no angle equals $180^\circ$.

Among all such polygons that you can form with the sticks, find the maximum possible perimeter. If no valid polygon exists, output $0$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$).

The first line of each test case contains a single integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the number of sticks.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the lengths of the sticks.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer representing the maximum possible perimeter of a non-degenerate, symmetrical and strictly convex polygon that you can form from a non-empty subset of the sticks. If it is not possible, output $0$.

## Examples

### Sample Input

```
5
3
5 5 7
3
4 5 7
3
5 5 10
7
4 3 5 1 5 3 3
4
2 3 5 7
```

### Sample Output

```
17
0
0
23
0
```