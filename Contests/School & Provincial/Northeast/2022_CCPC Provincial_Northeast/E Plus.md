# Plus

## 题目描述

Given $n$, you need to find all pairs $(p,q)$ such that:

- $1 \le p \le q \le n$.
- $p,q$ are all primes.
- $p^q + q^p$ is a prime.

## 输入描述

One line contains one integer $n$. ($1 \le n \le 10^{18}$)

## 输出描述

In the first line, output the number of pairs $(p,q)$ you found.  
Then each line contains two integers, indicating $p$ and $q$.

If there are multiple pairs $(p,q)$, you should output them in the increasing order. $(p_1,q_1) < (p_2,q_2)$ if and only if $p_1 < p_2$ or ($p_1 = p_2$ and $q_1 < q_2$).

## 样例输入输出

**示例1**

**输入**

```text
2
```

**输出**

```text
0
```

**示例2**

**输入**

```text
3
```

**输出**

```text
1
2 3
```