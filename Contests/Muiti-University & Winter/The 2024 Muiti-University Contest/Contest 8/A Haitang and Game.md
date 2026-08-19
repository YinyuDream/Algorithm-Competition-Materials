# Haitang and Game

## 题目描述

Given a set $S$, dXqwq and Haitang take turns performing the following operations, with dXqwq going first: 

*   Find a pair $(x,y)$ such that $x,y\in S$ and $\gcd(x,y)\notin S$.   
*   Insert $\gcd(x,y)$ into $S$.   

The player who cannot make a move loses the game. You need to output the winner when both players play optimally. 

## 输入描述:

Each test contains multiple test cases. The first line contains an integer $T$ ($1\leq T\leq 20$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1\leq n\leq 10^5$) — the size of set $S$.

The second line contains $n$ integers $a_1,a_2,\cdots,a_n$ ($1\leq a_1<a_2<\cdots<a_n\leq 10^5$) — the elements of set $S$.

## 输出描述:

For each test case, output “dXqwq” if dXqwq will win the game, and “Haitang” if Haitang will win the game.

## 样例输入输出

### 示例1

输入：

```plain
5
1
24
2
44 77
3
6 10 15
4
11 45 1419 19810
8
2 6 9 10 12 17 18 20
```

输出：

```plain
Haitang
dXqwq
Haitang
dXqwq
dXqwq
```