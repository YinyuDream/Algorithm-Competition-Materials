# 知

## 题目描述

The game consists of $n$ levels, and you know in advance the probability of passing each level, given as $\frac{a_1}{100}, \frac{a_2}{100}, \cdots, \frac{a_n}{100}$, where $a_i$ are non-negative integers.

You can perform any number of operations. Each operation allows you to choose an index $i \, (1 \leq i < n, a_{i+1} > 0, a_{i} < 100)$ and decrement $a_{i+1}$ by one while incrementing $a_{i}$ by one.

After performing operations, you start the game, aiming to maximize the probability of passing all levels.

Output the maximum probability multiplied by $100^n$ modulo $998244353$.

## 输入描述

The first line contains a positive integer $T$, indicating the number of test cases.For each test case:
The first line contains a positive integer $n$.
The second line contains $n$ non-negative integers $a_i$.

## 输出描述

For each test case, output one non-negative integer, representing the result of the maximum probability multiplied by $100^n$ modulo $998244353$.

## 样例输入输出

**输入**
```
5
4
1 2 3 4
4
4 3 2 1
2
2 2
1
1
2
2 3
```

**输出**
```
36
24
4
1
6
```

## 备注

$1 \le T, n, a_i \le 100$.