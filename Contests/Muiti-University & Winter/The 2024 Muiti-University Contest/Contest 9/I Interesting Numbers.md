# Interesting Numbers

## 题目描述

Little G is looking for a special type of number with the following characteristics: they have $n$ digits. Splitting the number by half yields two perfect square numbers, possibly with leading zeros. It's guaranteed that $n \equiv 0 \bmod 2$

Now Little G wants to know how many such numbers there are within the range $[L, R]$.

The two halves must have the same length.

## 输入描述:

```
Line 1: An integer $n$.
Line 2: Two integers $L$ and $R$.
```

## 输出描述:

```
Line 1: An integer, the answer.
```

## 样例输入输出

### 示例1

输入：

```plain
2
10 99
```

输出：

```plain
12
```

说明：

$10,11,14,19,40,41,44,49,90,91,94,99$ are the only numbers satisfying the conditions.

### 示例2

输入：

```plain
6
100000 999999
```

输出：

```plain
704
```

## 备注:

$1\leq n\leq 60$, $10^{n-1} \le L \le R < 10^n$.