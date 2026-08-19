# Two Convex Polygons

## 题目描述

In a two-dimensional plane, given two convex polygons (there may be three collinear points) $A,B$.

$A$ is fixed. You can translate, rotate, flip $B$ in the plane, but make sure that $A$ and $B$ have at least one point in common. Find the perimeter of the graph composed of points that $B$ may cover.

## 输入描述:

The first line is a positive integer $T$, which represents the number of test cases. For each test case:

* The first line contains a positive integer $n (3\le n \le 10^6)$, representing the number of points in $A$ convex polygon;
* For the following $n$ lines, the $i$-th line contains two integers $x_i,y_i (-10^8 \le x_i,y_i \le 10^8)$, representing a vertex $(x_i,y_i)$ of $A$ convex polygon;
* The next line contains a positive integer $m (3\le m \le 10^6)$, representing the number of points in $B$ convex polygon;
* For the following $m$ lines, the $i$-th line contains two integers $x'_i,y'_i (-10^8\le x'_i,y'_i \le 10^8)$, representing a vertex $(x'_i,y'_i)$ of $B$ convex polygon.

## 输出描述:

For each test case, output one line containing a real number representing the answer for this case.

The answer will be accepted if and only if its absolute or relative error does not exceed $10^{-9}$.

## 样例输入输出

### 样例输入

```
1
3
0 0
3 0
3 4
4
0 0
3 0
3 4
0 4
```

### 样例输出

```
43.415926535897932
```

### 说明

The answer is $12+10\pi$.

## 备注:

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$ and the sum of $m$ over all test cases does not exceed $10^6$.

The vertices of convex polygons are given in counterclockwise order and are different from each other.

It is guaranteed that no convex polygon degenerates into a line segment.