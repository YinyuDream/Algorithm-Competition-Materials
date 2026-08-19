# Tadokoro-Tono-Toe

## 题目描述

Tadokoro Kouji 与好友 Tono 正在大小为 $n \times n$ 的棋盘上玩 3 子棋游戏：先手执黑，后手执白，双方轮流在棋盘上任意一个空位落子，先在横线、竖线或斜对角线上形成 $3$ 子连线者将赢得比赛。

现在 Tadokoro Kouji 担任先手。Tadokoro Kouji 想知道，是否存在一种策略，使得无论 Tono 如何落子，自己都能赢得比赛。于是她找到了你，希望你解决这个问题。

## 输入描述

本题有多组数据。

第一行一个正整数 $T$ $(T \leq 100)$，表示数据组数。

对于每组数据：

一行一个正整数 $n$ $(1 \leq n \leq 114514)$，代表 Tadokoro Kouji 所询问的 $3$ 子棋的棋盘大小为 $n$。

## 输出描述

对于每组数据，如果 Tadokoro Kouji 存在赢得比赛的策略，输出一行一个 "Yarimasune"（不含引号）；

如果 Tadokoro Kouji 无论如何都无法赢得比赛，输出一行一个 "Unhuhhuhahhhhhhhh"（不含引号）。

## 示例1

### 输入

```
3
1
2
114514
```

### 输出

```
Unhuhhuhahhhhhhhh
Unhuhhuhahhhhhhhh
Yarimasune
```