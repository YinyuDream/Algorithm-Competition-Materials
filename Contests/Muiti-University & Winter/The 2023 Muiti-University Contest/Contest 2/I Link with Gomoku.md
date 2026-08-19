# Link with Gomoku

## 题目描述

*The more you win, the stronger your confidence becomes. The stronger your confidence, the more arrogant you become. The more arrogant you are, the easier it is to make mistakes. The more mistakes you make, the more you lose. So the more you win, the more you lose.*

Link and Fall are playing Gomoku on a board with $n$ rows and $m$ columns, but neither of them wants to win (because the more they win, the more they lose). Therefore, they have decided to achieve a draw. Your task is to design a strategy for them to place their pieces on the board in such a way that the game ends in a draw.

If you have never played Gomoku before, here are the rules:

Black plays the first move (represented by `x`), and white plays the second move (represented by `o`). Each player takes turns placing their piece on an empty spot on the board. The game ends immediately if either player has five consecutive pieces in a row, column, or diagonal (both positive and negative). If the board is filled but neither player has five consecutive pieces, the game is a draw.

In this problem, the forbidden move rule is not used.

## 输入描述

The input contains multiple test cases.

The first line contains an integer $T$ $(1 \leq T \leq 10^3)$, representing the number of test cases.

For the following $T$ lines, each containing two integers $n$ and $m$ $(1 \leq n, m \leq 10^3)$, representing a test case.

It is guaranteed that $\sum n \times m \leq 10^6$.

## 输出描述

For each test case, you need to output $n$ lines, each containing $m$ characters, representing the final state of the board. The $j$-th character of the $i$-th line $c_{i,j}$ represents the piece at row $i$, column $j$ of the board. If $c_{i,j}$ is `x`, it means the cell at row $i$, column $j$ contains a black piece. If $c_{i,j}$ is `o`, it means the cell at row $i$, column $j$ contains a white piece. If $c_{i,j}$ is any other character, you will receive a `Wrong Answer` result.

If there is a line of five consecutive pieces on the board or **the state you output cannot be the final state of a Gomoku game according to the aforementioned rules**, you will receive a `Wrong Answer` result.

It can be shown that at least one solution exists. If there are multiple solutions, you can output any of them.

## 示例

### 示例输入

```input
2
4 4
5 5
```

### 示例输出

```output
oooo
xxxx
oooo
xxxx
oooox
xxxxo
oooox
xxxxo
xoxox
```