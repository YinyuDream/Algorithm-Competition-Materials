# Intervals on the Ring

## 题目描述

There is a ring of numbers consisting of $1$ to $n$ sequentially. For every number $i$ $(1 \leq i \leq n - 1)$, $i$ and $i+1$ are adjacent to each other. Particularly, $n$ and $1$ are adjacent. We use $[l,r]$ to describe an interval on the ring. Formally, if $l \leq r$, then the interval $[l,r]$ is equivalent to the set $\{ l, l + 1, \ldots, r - 1, r \}$. Otherwise, the interval $[l,r]$ is equivalent to $\{l,l+1,\ldots,n,1,\ldots,r-1,r\}$.

Yukikaze has $m$ non-intersecting intervals. She wants you to construct a set of intervals such that the intersection of them is the union of the $m$ intervals that Yukikaze has. The intersection of the intervals is the set of integers that the intervals have in common.

## 输入描述

The first line of the input contains a single integer $T\ (1 \leq T \leq 1000)$, denoting the number of test cases.

The first line of each test case contains two integers $n\ (3 \leq n \leq 1000)$ and $m\ (1 \leq m \leq n)$, denoting that the ring consists of numbers from $1$ to $n$.

Each of the next $m$ lines contains two integers $l,r\ (1 \leq l, r \leq n)$, denoting an interval Yukikaze has. It's guaranteed that the $m$ intervals won't intersect with each other.

## 输出描述

For each test case, if the answer doesn't exist, output $-1$ in a line. Otherwise, output an integer $k$ indicating the number of intervals you construct in a line. Then output the $k$ intervals in $k$ lines. The number of intervals you used should never be less than one or greater than $2000$.

If there are multiple solutions, print any. Don't print any extra spaces at the end of each line.

## 示例1

### 输入

```
2
3 1
2 2
4 2
1 1
3 3
```

### 输出

```
1
2 2
2
3 1
1 3
```