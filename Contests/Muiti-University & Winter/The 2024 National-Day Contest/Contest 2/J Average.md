# Average

## 题目描述

Bob has an $n\times m$ matrix $W$. 

This matrix is very special, It's calculated by two sequences $a_{1...n},b_{1...m}$, $\forall i\in [1,n],\forall j\in [1,m]$, $W_{i,j}=a_{i}+b_{j}$

Now Bob wants to find a submatrix of $W$ with the largest average value.

Bob doesn't want the size of submatrix to be too small, so the submatrix you find must satisfy that the height (the first dimension of matrix) of it is at least $x$ and the width (the second dimension of matrix) of it is at least $y$.

Now you need to calculate the largest average value.

## 输入描述

The first line has four integers $n,m,x,y$.

The second line has $n$ integers $a_{1...n}$.

The third line has $m$ integers $b_{1...m}$.

$1\leq n,m\leq 10^5$

$1\leq x\leq n,1\leq y\leq m$

$0\leq a_i,b_i\leq 10^5$

## 输出描述

Output the largest average value.

Your answer will be considered correct if the absolute or relative error is less than $10^{-6}$

## 示例1

### 输入

```
3 4 2 2
3 1 2
4 1 3 2
```

### 输出

```
4.6666666667
```