# Gcd

## 题目描述

Initially, you have a set $S = \{x, y\}$ $(x \neq y)$. Then you have two operations:

- **1.** Choose two elements $a, b$ $(a \neq b)$ from set $S$, insert $a - b$ to the set.

- **2.** Choose two elements $a, b$ $(a \neq b)$ from set $S$, insert $\gcd(|a|, |b|)$ to the set.

We define $|a|$ as the absolute value of $a$.

We define $\gcd(a,\ b)$ as the greatest common divisor of $a$ and $b$.

Specially, $\gcd(a,\ 0) = \gcd(0,\ a) = a$.

You task is making $z \in S$ after several operations.

If possible, print "YES". Otherwise, print "NO".

## 输入描述

Each test contains multiple test cases. The first line contains the number of test cases $T$ ($1 \le T \le 10^5$).  
The description of the test cases follows.  
One line contains three integers $x, y, z$ ($0 \le x, y, z \le 10^9$, $x \neq y$).

## 输出描述

For each test case, output "YES" or "NO".

## 示例

### 输入

```text
3
2 4 2
2 4 1
5 6 1
```

### 输出

```text
YES
NO
YES
```