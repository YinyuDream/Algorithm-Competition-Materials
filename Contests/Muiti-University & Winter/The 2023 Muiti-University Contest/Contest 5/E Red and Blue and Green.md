# Red and Blue and Green

## 题目描述

Ran loves intervals, inversions and trees, so she wants to make a problem mixing all of them together!

Ran has a unknown permutation $p$ of length $n$ and $m$ pairwise distinct intervals, the $i$-th one is $[l_i,r_i]$. It's guaranteed that for two intervals $i$ and $j$, let $l_i\le l_j$ (if $l_i=l_j$, let $r_i>r_j$), then $r_i<l_j$ or $r_i\ge r_j$ always holds.

There will be $m$ restrictions, the $i$-th one is like the number of inversions in $[l_i,r_i]$ must be odd/even. An inversion in an array $a$ is a pair of indices $(i, j)$ such that $i > j$ and $a_i < a_j$.

Now Ran want you to construct a permutation $p$ and meet all restrictions, or report it is impossible.

## 输入描述

The first line contains two integers $n$ and $m$ ($1\le n,m\le 10^3$).

For the next $m$ lines, each line contains three integers $l_i,r_i,w_i$ ($1\le l_i\le r_i\le n$, $w_i\in\{0,1\}$). If $w_i=0$ then the number of inversions in $[l_i,r_i]$ must be even, $w_i=1$ otherwise.

## 输出描述

Output $-1$ if it's impossible to construct $p$, or output $n$ integers representing $p$.

## 示例1

### 输入

```4 2
1 3 1
1 2 0
```

### 输出

```1 3 2 4
```

## 示例2

### 输入

```4 1
1 1 1
```

### 输出

```-1
```