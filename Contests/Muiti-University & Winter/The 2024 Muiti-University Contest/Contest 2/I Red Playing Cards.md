# Red Playing Cards

## 题目描述

There are $2\cdot n$ cards arranged in a row, with each card numbered from $1$ to $n$ having exactly $2$ copies.

Each time, **Red** can choose a subarray of consecutive cards (at least $2$ cards) to remove from the deck. The chosen subarray must satisfy that the first and last cards have the same number. The score for this operation is: the number of cards multiplied by the number on the first card. Now **Red** wants to know what is the maximum value of the final score?

## 输入描述:

The first line contains a positive integer $n(1\leq n \leq 3\times 10^3)$ — the number of card types.

The second line contains $2\cdot n$ positive integers $a_i(1\leq a_i \leq n)$ — the number on each card from left to right.

## 输出描述:

A single positive integer — representing the maximum final score.

## 样例输入输出

**输入**

```
4
4 4 1 2 3 1 3 2
```

**输出**

```
21
```

## 说明

First operation: choose the $5$-th to $7$-th cards, get $9$ points, and the remaining cards are $[4,4,1,2,2]$.

Second operation: from the remaining cards, choose the $1$-st to $2$-nd cards, get $8$ points, and the remaining cards are $[1,2,2]$.

Third operation: from the remaining cards, choose the $2$-nd to $3$-rd cards, get $4$ points, and there is still $1$ card remaining, so no more operations can be performed.