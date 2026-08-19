# 珑

## 题目描述

You need to cover an $n \times m$ rectangle using several $1 \times 2$ or $2 \times 1$ dominoes. Each position must be covered exactly once, and the dominoes must not extend outside the rectangle.

Additionally, there may be two types of constraints:

1. The short sides of the dominoes cannot be adjacent, meaning no two dominoes can share a side of length 1.
2. The long sides of the dominoes cannot be adjacent, meaning no two dominoes can share a side of length 2 (even if they only share one edge).

There are $T$ queries, each giving $n, m, a, b$, representing the size of the rectangle and whether the two constraints exist. When $a$ is 0, the first constraint exists; when $a$ is 1, the first constraint does not exist. When $b$ is 0, the second constraint exists; when $b$ is 1, the second constraint does not exist. For each query, you need to determine if there is a way to cover the entire rectangle.

## 输入描述:

The first line contains a positive integer $T$.

The next $T$ lines each contain four integers $n, m, a, b$.

## 输出描述:

For each query, output "Yes" or "No" indicating whether there is a way to cover the entire rectangle.

## 样例输入输出

### 示例1

**输入**

```
5
3 3 1 1
2 4 0 1
1 5 1 0
5 5 0 0
1 2 0 0
```

**输出**

```
No
Yes
No
No
Yes
```

## 备注:

$1 \le T \le 10^5$

$1 \le n, m \le 10^9$

$0 \le a, b \le 1$