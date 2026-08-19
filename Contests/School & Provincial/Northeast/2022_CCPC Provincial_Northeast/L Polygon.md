# Polygon

## 题目描述

You have $n$ segments, which are numbered from $1$ to $n$. The length of the $i$-th segment is $a_i$.  
A simple polygon is a polygon that does not intersect itself and has no holes. Note that a simple polygon has at least $3$ edges and its area is not equal to $0$.  

Determine whether you can use all $n$ segments to form a simple polygon with $n$ edges. Note that each segment must be used exactly once.

## 输入描述

The first line contains one single integer $n$ ($3\le n \le 2\times 10^5$), denoting the number of segments.  

The second line contains $n$ integers $a_i$ ($1\le a_i\le 10^9$), denoting the length of the $i$-th segment.  

It is guaranteed that $\displaystyle\sum_{i=1}^{n} a_i\le 2\times 10^9$.

## 输出描述

If you can use these $n$ segments to form a simple polygon, output **YES**, otherwise **NO**.

## 样例输入输出

### 示例1

**输入**

``` 
3
3 4 5
```

**输出**

``` 
YES
```

**说明**

In the first example, you can use them to construct a right-angled triangle.

### 示例2

**输入**

``` 
4
1 1 1 3
```

**输出**

``` 
NO
```