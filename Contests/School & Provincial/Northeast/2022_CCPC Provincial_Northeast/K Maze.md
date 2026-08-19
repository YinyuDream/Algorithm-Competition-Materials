# Maze

## 题目描述

You are given a maze. It is a grid with $n$ rows and $n$ columns. Rows and columns are both numbered from $1$ to $n$. The intersection of the $a$-th row and $b$-th column is denoted by $(a, b)$. Some cells of the maze are obstacles.  
Initially, you are standing in the top left corner $(1,1)$. Your goal is to reach the bottom right corner $(n,n)$.  
You can move in four directions from $(a, b)$: up to $(a-1, b)$, down to $(a+1, b)$, left to $(a, b-1)$ or right to $(a, b+1)$.  
You cannot move in the same direction for more than $m$ consecutive moves, you cannot leave the grid and the cells with obstacle are unreachable. What is the minimum number of moves to reach $(n, n)$?

## 输入描述

The input consists of multiple test cases.

The first line contains a single integer $t$ ($t \leq 50$) – the number of the test cases, the description of the test cases follows.

The first line of each test case contains two integers $n, m$ ($2 \leq n \leq 100$, $1 \leq m \leq 100$), denoting the size of the maze and the most consecutive moves you can perform in one direction.

The next $n$ lines describe the maze. Each of them contains a string of length $n$ that consists only of symbols `.` and `*`. The $j$-th character of the $i$-th line corresponds to the cell of the maze at row $i$ and column $j$. Symbol `.` denotes a free cell, while symbol `*` denotes a cell with an obstacle.

Ensure that the number of test cases with $n > 40$ will not exceed $10$.

## 输出描述

For each test case, print a single integer: $-1$ if it is impossible to reach $(n, n)$, otherwise the minimum number of moves.

## 示例

### 示例输入

```
1
3 1
..*
..*
...
```

### 示例输出

```
4
```