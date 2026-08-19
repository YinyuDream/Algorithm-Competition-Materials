# Cake

## 题目描述

Grammy and Oscar bought a big cake. They like it very much, so dividing the cake becomes difficult. In order to divide the cake in a relatively fair way, they decided to play a game to earn more part of the cake for themselves.

The game consists of two phases.

For phase $1$, Grammy and Oscar will play on a tree rooted at vertex $1$. Each edge of the tree has a number $0$ or $1$. Initially, there is a horse on the root. 
They take turns moving the horse, with Grammy moving first. At each turn, suppose the horse is at vertex $p$, the player must select some child of $p$ and move the horse to that child of $p$. Phase $1$ ends when $p$ has no children. As a result of phase $1$, we will get a string $S$ formed by concatenating the numbers on edges the horse has passed by. Note that $S$ consists of only $0$ and $1$.

For phase $2$, Grammy and Oscar will play on the string $S$ they obtained in phase $1$. Let $m$ be the length of $S$. Firstly, Oscar will divide the cake into $m$ parts (some parts can be empty). Then $m$ steps follow. At the $i$-th step, if the $i$-th character of $S$ is $1$, Grammy will choose one part and get it; otherwise, Oscar will choose one part and get it.

Both of them hope to maximize the cake they get, and they both play optimally. Please calculate the fraction of cake Grammy gets.

## 输入描述:

There are multiple test cases. The first line of the input contains an integer $T$ ($1\leq T\leq 100\,000$) indicating the number of test cases. For each test case:

The first line contains one integer $n$ ($2\leq n\leq 200\,000$), indicating the size of the rooted tree in phase $1$.

For the following $n-1$ lines, the $i$-th line contains three integers $x, y, k$ ($1\leq x,y\leq n, 0\leq k\leq 1$) describing an edge connecting $x$ and $y$ with number $k$.

It is guaranteed that the sum of $n$ over all test cases will not exceed $500\,000$.

## 输出描述:

For each test case:

Output one line containing one real number indicating the fraction of cake Grammy gets in the game, assuming both players play optimally.

Your answer is considered correct if its absolute or relative error does not exceed $10^{-9}$.

Formally, let your answer be $a$, and the jury's answer be $b$. Your answer is accepted if and only if $\frac{|a-b|}{max(1,|b|)}\leq 10^{-9}$.

## 样例输入输出

### 示例1

输入：

```
3
3
1 2 1
1 3 0
4
1 2 0
1 3 1
3 4 0
5
1 2 0
1 3 0
3 4 1
4 5 1
```

输出：

```
1.000000000000
0.500000000000
0.000000000000
```