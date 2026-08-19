# Chocolate

## 题目描述

Walk Alone has $n\times m$ pieces of chocolates placed in a board with $n$ rows and $m$ columns. The coordinates of the $i$-th row and the $j$-th column is $(i,j)$.

Walk Alone wants to play a game with Kelin. They will eat the chocolates in turn with Kelin moving first. In each turn, a player can choose two integers $i,j\ (1 \leq i\leq n,1\leq j\leq m)$, and then eat all chocolates with coordinates $(x,y)$ where $x \leq i$ and $y\leq j$. One must eat at least one piece of chocolate in his turn, and the one who eats the last piece loses the game.

Suppose that both Walk Alone and Kelin are intelligent enough and will play optimally, you should decide who will win the game. If Walk Alone will win, print 'Walk Alone'; otherwise, print 'Kelin' (without quotes).

## 输入描述

The only line of the input contains two integers $n$ and $m\ (1\leq n,m\leq 10^9)$, indicating the size of the board.

## 输出描述

Print 'Walk Alone' if he wins, and 'Kelin' otherwise (without quotes).

## 示例输入输出

### 示例1

输入：

```
2 3
```

输出：

```
Kelin
```

### 示例2

输入：

```
1 1
```

输出：

```
Walk Alone
```