# Sequence

## 题目描述

You have an array of $n$ elements $a_1,\ a_2,\dots,\ a_n$.

For each task, you have three integers $l,r,k$.

Ask whether you can find an array $b$ of $k-1$ integers satisfy:

- $\ l \le \ b_1 < \ b_2 < \ b_3 < \dots < \ b_{k-1} < \ r$

- $sum(l, b_1),\ sum(b_1+1, b_2),\dots,\ sum(b_{k-1}+1,\ r)$ are the multiples of $2$

Specially, if $k=1$, it should satisfy $sum(l,r)$ is the multiple of $2$.

We define $sum(l,r)=\sum_{i=l}^{r} a_i\ (l\le r)$.

If possible, print "YES". Otherwise, print "NO".

## 输入描述

Each test contains multiple test cases. The first line contains the number of test cases $T(1\le T\le 10000)$.

The description of the test cases follows.

The first line contains two integers $n, \ q$($1\le n ,\ q   \le  10^5$).

The second line contains $n$ integers $a_1,\ a_2,\dots,\ a_n$($0 \le a_i \le 10^{10}$).

Each of the $q$ lines contains three integers $l, r, k$($1\le  l  \le \ r  \le \ n, 1  \le \  k \le  10^5$).

It's guaranteed that $\sum n, \ \sum q \ \le \ 5 \times \ 10^5$.

## 输出描述

For each test case, output "YES" or "NO".

## 示例

### 示例输入

```
2
3 3
1 2 3
1 2 1
1 3 1
2 3 1
3 3
2 2 2
1 2 1
1 2 2
1 2 3
```

### 示例输出

```
NO
YES
NO
YES
YES
NO
```