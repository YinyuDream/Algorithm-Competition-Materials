# CF455C Civilization

## 题目描述

Andrew plays a game called "Civilization". Dima helps him.

The game has $n$ cities and $m$ bidirectional roads. The cities are numbered from $1$ to $n$. Between any pair of cities there either is a single (unique) path, or there is no path at all. A path is such a sequence of distinct cities $v_1, v_2, \ldots, v_k$, that there is a road between any contiguous cities $v_i$ and $v_{i+1}$ ($1 \le i < k$). The length of the described path equals to $(k-1)$. We assume that two cities lie in the same region if and only if, there is a path connecting these two cities.

During the game events of two types take place:

1. Andrew asks Dima about the length of the longest path in the region where city $x$ lies.
2. Andrew asks Dima to merge the region where city $x$ lies with the region where city $y$ lies. If the cities lie in the same region, then no merging is needed. Otherwise, you need to merge the regions as follows: choose a city from the first region, a city from the second region and connect them by a road so as to minimize the length of the longest path in the resulting region. If there are multiple ways to do so, you are allowed to choose any of them.

Dima finds it hard to execute Andrew's queries, so he asks you to help him. Help Dima.

## 输入格式

The first line contains three integers $n, m, q$ ($1 \le n \le 3 \cdot 10^5$; $0 \le m < n$; $1 \le q \le 3 \cdot 10^5$) — the number of cities, the number of the roads we already have and the number of queries, correspondingly.

Each of the following $m$ lines contains two integers, $a_i$ and $b_i$ ($a_i \ne b_i$; $1 \le a_i, b_i \le n$). These numbers represent the road between cities $a_i$ and $b_i$. There can be at most one road between two cities.

Each of the following $q$ lines contains one of the two events in the following format:

- `1 xi` — it is the request Andrew gives to Dima to find the length of the maximum path in the region that contains city $x_i$ ($1 \le x_i \le n$).
- `2 xi yi` — it is the request Andrew gives to Dima to merge the region that contains city $x_i$ and the region that contains city $y_i$ ($1 \le x_i, y_i \le n$). Note, that $x_i$ can be equal to $y_i$.

## 输出格式

For each event of the first type print the answer on a separate line.

## 样例输入

```
6 0 6
2 1 2
2 3 4
2 5 6
2 3 2
2 5 3
1 1
```

## 样例输出

```
4
```
