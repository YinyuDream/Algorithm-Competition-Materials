# Inverse Pair

## 题目描述

For a sequence $t_{1...n}$, we define the weight of it is the number of pairs $(i,j)$ satisfy $i<j$ and $t_i>t_j$.

Now give you a permutation $a_{1...n}$, you need to choose a sequence $b_{1...n}$ satisfies $b_i\in \{0,1\}$ to minimize the weight of sequence $c_{1...n}$ which satisfies $c_i=a_i+b_i$.

## 输入描述

The first line has one integer $n$.

The second line has $n$ integers $a_{1...n}$.

It's guaranteed that $a_i$ is a permutation of $\{1,2...n\}$

$1\leq n\leq 2\times 10^5$

## 输出描述

Output the minimum weight of $c_{1...n}$ you can get.

## 示例1

**输入**

```
5
4 3 2 5 1
```

**输出**

```
5
```