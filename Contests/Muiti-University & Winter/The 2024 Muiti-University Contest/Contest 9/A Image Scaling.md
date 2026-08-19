# Image Scaling

## 题目描述

You are given a $n\times m$ matrix consisting of $\tt{.}$ and $\tt{x}$. All $\tt{x}$s form a submatrix and you want to extract it and scale down as much as possible while keeping integer side length and unchanged aspect ratio. Output the final matrix. It's guaranteed that there's at least one $\tt{x}$ in the matrix.

## 输入描述

The first line contains two integers $n,m$.

The following $n$ lines each contain a string of length $m$ consisting of $\tt{.}$ and $\tt{x}$.

## 输出描述

A matrix consisting of $\tt{x}$.

## 样例输入

```plain
8 7
.......
..xxxx.
..xxxx.
..xxxx.
..xxxx.
..xxxx.
..xxxx.
.......
```

## 样例输出

```plain
xx
xx
xx
```

## 备注

$1\le n,m\le500$