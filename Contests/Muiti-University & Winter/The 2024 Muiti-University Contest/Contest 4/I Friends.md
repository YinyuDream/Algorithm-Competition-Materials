# Friends

## 题目描述

There are $n$ people standing in a line, numbered from $1$ to $n$ from left to right. Among these people, there are $m$ pairs of friends.

Define an interval $[l,r]$ ($1 \leq l \leq r \leq n$) as friendly if and only if every pair of people within the interval are friends.

How many friendly intervals are there?

## 输入描述

The first line contains two integers $n$ and $m$ ($1 \leq n, m \leq 10^6$), representing the number of people and the number of pairs of friends, respectively.

The next $m$ lines each contain two integers $u$ and $v$ ($1 \leq u < v \leq n$), representing a pair of friends.

It is guaranteed that there are no duplicate friend pairs in the input.

## 输出描述

Output a single integer representing the number of friendly intervals.

## 样例输入

```plaintext
5 9
2 3
1 3
4 5
3 5
1 2
2 4
1 5
1 4
2 5
```

## 样例输出

```plaintext
9
```