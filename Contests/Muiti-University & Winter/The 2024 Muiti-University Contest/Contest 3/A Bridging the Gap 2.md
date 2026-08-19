# Bridging the Gap 2

## 题目描述

A group of $n$ walkers arrives at a riverbank at night. They want to cross the river using a boat, which is initially on their side. The boat can hold at most $R$ walkers at a time and requires at least $L$ $(1 \leq L < R)$ walkers to operate.

Rowing the boat is a tiring task. Each time the boat is used to transport a group of walkers to the other side of the river, all walkers on the boat must have stamina greater than $0$, and each walker's stamina decreases by $1$ after the trip. Initially, the $i$-th walker $(1 \leq i \leq n)$ has a stamina value of $h_i$.

You need to determine if it is possible to transport all the walkers to the other side of the river using the boat.

## 输入描述:

The first line of input contains three integers $n, L, R$ ($1 \le L < R \le n \le 5 \times 10^5$), denoting the number of walkers, the minimum and the maximum number of walkers to use the boat at a time, respectively.

The second line of input contains $n$ integers $h_1,h_2,\dots,h_n$ $(1\leq h_i\leq 5\times 10^5)$, where $h_i$ $(1 \leq i \leq n)$ denotes the stamina value of the $i$-th walker.

## 输出描述:

If it is possible to transport all the walkers to the other side of the river using the boat, output "Yes" in the first line (without quotes). Otherwise, output "No" in the first line (without quotes). You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will all be considered as positive replies.

## 样例输入输出

### 示例1

输入：

```
4 1 2
1 2 5 10
```

输出：

```
Yes
```

### 示例2

输入：

```
5 1 2
1 1 1 1 5
```

输出：

```
No
```

### 示例3

输入：

```
5 1 3
1 1 1 1 5
```

输出：

```
Yes
```

### 示例4

输入：

```
5 2 3
1 1 1 1 5
```

输出：

```
No
```

### 示例5

输入：

```
9 1 9
1 1 1 1 1 1 1 1 1
```

输出：

```
Yes
```