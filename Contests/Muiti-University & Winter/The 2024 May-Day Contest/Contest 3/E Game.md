# Game

## 题目描述

There are $n$ columns of blocks standing in a row. The $i$-th column has $a_i$ blocks in the beginning. Each block has size $1\times 1\times 1$. Define $(x,y)$ represent the block at column $x$ and is the $y$-th block from bottom to top. You can perform one operation:

- Push one block to the left, that means you choose one block which has no block at its right and make it move to the left. Because of the friction, the block above it will also move to the left, and because the blocks cannot intersect, the block at its left will move to the left either. This will cause a chain reaction. After every block moved, if some blocks hang in the air, then it will fall because of gravitation. Note that the blocks at column 1 can't move to the left, so if a movement will cause a block at column 1 move, you can't perform this operation.

Formally, let $b_i$ be the number of blocks in the $i$-th column now, then you can choose block $(x,y)$ that satisfy $b_x \ge y$ and $b_{x+1} < y$ (or $x=n$). Let $l$ be the greatest position that satisfies $1 \le l < x$ and $b_l < y$, then you can perform this operation as long as $l$ exists. Then for all blocks $(i,j)$ that satisfy $l < i \le x$ and $j \ge y$, it moves to $(i-1,j)$. After that, for blocks $(x,y)$ ($y>1$) that there are no blocks in $(x,y-1)$, it moves to $(x,y-1)$. Repeat doing it until no blocks satisfy the condition.

![operation example 1](https://uploadfiles.nowcoder.com/images/20200809/329343_1596986352254_E347C2BEA8CEDD3BB15D00541D0076CF)

![operation example 2](https://uploadfiles.nowcoder.com/images/20200809/329343_1596986364553_E27C0E6AF3F884E005FAE44BB4699B71)

![operation example 3](https://uploadfiles.nowcoder.com/images/20200809/329343_1596986374049_21A10E668E6994E6DA6C22EC53C00B36)

This shows an operation that pushes the block at $(6,4)$, and the value of $l$ is $3$.

The goal of the game is to minimize the height of blocks. You need to operate any number of times of the operation and minimize $\max_{i=1}^n b_i$, where $b_i$ represents the number of blocks in the end. Output the minimized value.

## 输入描述

The first line contains one integer $T$ $(1 \le T \le 100000)$ — the number of test cases.

The first line of each test case contains only one integer $n$ $(1 \le n \le 10^5)$ — the number of columns of blocks in the game.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ $(1 \le a_i \le 10^9)$ — the number of blocks in each column at the beginning.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## 输出描述

Print $T$ integers — for each test case output the minimum value of $\max_{i=1}^n b_i$.

## 示例1

### 输入

```text
2
4
2 3 5 6
8
2 1 1 4 4 6 2 3
```

### 输出

```text
4
3
```