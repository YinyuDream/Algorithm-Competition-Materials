# Non-Puzzle: Segment Pair

## 题目描述

There are $n$ pairs of segments in the X-axis. The $i$-th of them is $[l_i, r_i]$ and $[l'_i, r'_i]$.

You should choose **exactly one** segment from each pair (that is, choose either $[l_i, r_i]$ or $[l'_i, r'_i]$ for each $i$), satisfying that there exists at least one point $x$, which is included by all the chosen segments.

You need to determine the number of different ways of choosing the segments (over $2^n$ possible ways) that satisfies the condition, output it modulo $10^9+7$.

Two ways are considered different if and only if there exists $i$, such that $[l_i, r_i]$ is chosen in one way, and $[l'_i, r'_i]$ is chosen in another. Note that even if $[l_i, r_i] = [l'_i, r'_i]$, the two ways are considered different.

## 输入描述

The first line contains one integer $n$ ($1 \le n \le 5\cdot 10^5$).  
The following $n$ lines, each line contains four integers $l_i, r_i, l'_i, r'_i$ ($1 \le l_i \le r_i \le 5\cdot 10^5$, $1 \le l'_i \le r'_i \le 5\cdot 10^5$).

## 输出描述

Output a single integer, representing the number of different ways of choosing the segments, modulo $10^9+7$.

## 示例

### 示例1

**输入**

```
3
1 4 6 7
2 5 3 5
1 3 5 7
```

**输出**

```
2
```

### 示例2

**输入**

```
4
1 3 2 5
1 5 1 4
2 3 1 4
1 3 3 5
```

**输出**

```
16
```

### 示例3

**输入**

```
2
1 3 6 7
4 4 5 5
```

**输出**

```
0
```

## 备注

For the first example, you can choose $\{[1,4], [3,5], [1,3]\}$ (they share a common point $3$), or $\{[1,4], [2,5], [1,3]\}$ (they share common points $2,3$). There are no other valid choices.  

For the second example, all $2^4$ choices are valid.  

For the third example, it can be proved that there are no valid choices.