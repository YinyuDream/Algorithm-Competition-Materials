# Link with Chess Game

## 题目描述

There is a row of $n$ cells, numbered from $1$ to $n$. The $u$-th cell is called to be adjacent to the $v$-th cell if and only if $|u - v| = 1$.

There are three chess pieces: red, green, and blue. The red piece is located at the $r$-th cell, the green piece is located at the $g$-th cell, and the blue piece is located at the $b$-th cell. (Different pieces may occupy the same cell.)

Alice and Bob take turns performing the following operation, with Alice going first:

- Select a chess piece and move it to an adjacent cell (different pieces may occupy the same cell).

If, after a move, the ordered triple $(r, g, b)$ formed by the positions of the three pieces has appeared at some previous moment, the player who made that move loses, and the other player wins. (The initial state is considered to have appeared before.)

Assuming both players adopt an optimal strategy, who will win the game?

## 输入描述

Input consists of multiple test cases.

The first line contains an integer $T$ ($1 \leq T \leq 10^4$), indicating the number of test cases.

Following that are $T$ lines, each containing four positive integers $n, r_0, g_0, b_0$ ($2 \leq n \leq 10^5, 1 \leq r_0, g_0, b_0 \leq n$). These represent a query, where $r_0, g_0, b_0$ are the initial positions of the red, green and blue chess pieces, respectively.

It is guaranteed that $\sum n \leq 10^6$.

## 输出描述

For each test case, if Alice wins, please output “Alice”; otherwise, please output “Bob”.

## 示例

### 输入

```
2
2 2 2 2
3 3 3 3
```

### 输出

```
Alice
Bob
```