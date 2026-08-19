# GCD VS XOR

Ben_H has a positive integer $x$. He wants you to find another positive integer $y$, which is strictly less than $x$, so that the equation $gcd(x, y) = x \oplus y$ holds. Can you help him?

where $\oplus$ is bitwise XOR operation (see notes for explanation).

## 输入描述:

The first line contains a single integer $t (1 \leq t \leq 10^4)$ — the number of test cases.
The only line of each test case contains a single integer $x (1\leq x \leq 10^{18})$.

## 输出描述:

For each testcase, output a single positive integer $y$, if you find a feasible answer, or $-1$ otherwise.

## 样例输入输出

```plaintext
输入：
2
15
1

输出：
10
-1
```

## 备注:

$gcd(x, y)$ represents the greatest common divisor of $x$ and $y$, such as $gcd(4, 6) = 2$.

A bitwise XOR is a binary operation that takes two bit patterns of equal length and performs the logical exclusive OR operation on each pair of corresponding bits. The result in each position is $1$ if only one of the bits is $1$, but will be $0$ if both are $0$ or both are $1$.