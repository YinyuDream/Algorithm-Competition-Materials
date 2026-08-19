# Ball

## 题目描述

Chino is considering such a geometric problem.

![image](https://uploadfiles.nowcoder.com/images/20240801/0_1722445106551/8BF5CF367EC1D9E33095313D059908A5)

In the two-dimensional Cartesian coordinate system, there is a long stick with negligible width and a length of $l$ perpendicular to the $y$-axis, with the left endpoint at the origin $O(0,0)$.

A small ball, which can be seen as a point, is located at $P(x,y)$.

Chino wants to know whether there is a pivot point on the long stick, so that during the rotation of the stick around the pivot point, it can hit the small ball. Please help Chino find any pivot point that satisfies the condition, or tell her that such a pivot point does not exist.

Iff the stick or its endpoint passes through point $P(x,y)$ during rotation, the stick can hit the ball.

## 输入描述:

The first line contains a positive integer $T(1\leq T \leq 10^4)$ --- the number of test cases.

For each test case:

Input a line with three integers $l,x,y(1\leq l \leq 10^5,-10^5 \leq x,y \leq 10^5)$ --- the length of the long stick and the coordinates of the small ball.

## 输出描述:

If there is a pivot point that satisfies the condition, first print "Yes", followed by the $x$-coordinate of the pivot point on the next line, you can give any real number in the range $[0,l]$; otherwise, print "No".

## 示例1

### 输入

```plain
3
5 3 1
5 2 1
5 3 6
```

### 输出

```plain
Yes
3.114514
Yes
2.114514
No
```

## 示例2

### 输入

```plain
2
17 -8 15
17 17 18
```

### 输出

```plain
Yes
0
No
```