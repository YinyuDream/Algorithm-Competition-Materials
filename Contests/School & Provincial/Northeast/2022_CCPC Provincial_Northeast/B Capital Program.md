# Capital Program

## 题目描述

There is a kingdom that has $n$ cities connected by $n-1$ roads. All roads' length is $1$. The King wants to choose an area to be the capital of the kingdom. The area must have exactly $k$ connected cities (the area of the capital is a connected component with exactly $k$ cities). To show the importance of the capital, the King wants to minimize the maximum value of all the $n$ cities.

We define the value of a city as the minimum distance between the city and one city which belongs to the capital. The distance between two cities is the length of the shortest path between them.

## 输入描述

The first line of each test contains two integers $n$ and $k$ ($5 \leq n \leq 100000, 1 \leq k \leq n$) --- the number of vertices and the number of cities of the capital, respectively.

Next $n-1$ lines describe edges: the $i$-th line contains two integers $u_i, v_i$ ($1 \leq u_i,v_i \leq n, u_i \neq v_i$) --- indices of vertices connected by the $i$-th edge.

## 输出描述

Print the minimum of the maximum value of all cities.

## 示例

### 示例 1

**输入**
```
6 3
1 2
2 3
2 4
1 5
5 6
```

**输出**
```
1
```