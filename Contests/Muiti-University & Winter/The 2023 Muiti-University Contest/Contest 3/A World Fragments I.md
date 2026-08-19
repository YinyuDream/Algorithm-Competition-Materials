# World Fragments I

## 题目描述

**This problem is different from World Fragments II and World Fragments III. Please read the statements carefully.**

You are given two non-negative **binary integers** $x$ and $y$ without leading zeros. You can apply the following operation to $x$ any number of times (possibly zero):

1. Choose a digit $b$ in $x$.
2. Let either $x \gets x + b$ or $x \gets x - b$.

For example, when $x = (110100)_2$ you can choose the digit $b = (1)_2$ in $(1\underline{1}0100)_2$, then let $x \gets x - b = (110100)_2 - (1)_2 = (110011)_2$.

Find out the least number of operations needed to turn $x$ into $y$. Print $-1$ if it is impossible to turn $x$ into $y$.

## 输入描述

The first line contains a non-negative binary integer $x$. It is guaranteed that $x$ has at most $60$ digits.

The second line contains a non-negative binary integer $y$. It is guaranteed that $y$ has at most $60$ digits.

## 输出描述

Print a **decimal integer** in a single line, denoting the answer. If it is impossible to turn $x$ into $y$, print $-1$.

## 示例

### 示例1

**输入**

```
1
0
```

**输出**

```
1
```

### 示例2

**输入**

```
10101010101010101010
11001100110011001100
```

**输出**

```
139810
```

## 备注

In the first sample, the optimal way to apply the operation is shown as following:

- Choose the digit $b = (1)_2$, then let $x \gets x - b = (0)_2$.