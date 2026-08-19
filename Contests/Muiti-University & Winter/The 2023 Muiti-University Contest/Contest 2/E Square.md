# Square

## 题目描述

Find a number $y$ ($0 \leq y \leq 10^9$) so that the square of $y$ starts with $x$ in Decimal.

Formally, given an integer $x$, find an integer $y$ ($0 \leq y \leq 10^9$) such that there exists a nonnegative integer $k$ that satisfies $\lfloor \frac{y^2}{10^k} \rfloor = x$.

## 输入描述

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases.

Each test case contains an integer $x$ ($0 \leq x \leq 10^9$) - the $x$ described in the problem statement.

## 输出描述

For each test case, output an integer $y$ ($0 \leq y \leq 10^9$). If there are multiple results, you can output any one. If no $y$ satisfies the condition, output `-1`.

## 示例1

### 输入

```
3
1
123
781273981
```

### 输出

```
4
111
-1
```