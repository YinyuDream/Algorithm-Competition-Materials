# Go to Play Maimai DX

## 题目描述

Ran loves playing Maimai DX. However, to play it, she needs to perpare a big bottle of water, a pair of gloves, an earphone and some coins. She wants to play Maimai DX as soon as possible, but she has to take enough coins.

So here's the Maimai DX Problem:

Given an array $a$ guaranteed that $1\le a_i\le 4$ and an integer $k$. Let's call an interval $[l,r]$ good if it contains all $4$ kinds of numbers. Try to find the shortest good interval with at least $k$ $4$s in it, and output it's length.

It's guaranteed that there're at least one "$1$"s, "$2$"s and "$3$"s in $a$. Also, there're at least $k$ "$4$"s. That means, there'll be at lease one good intervals in $a$.

## 输入描述

The first line contains two integers $n$ and $k$ ($1\le k\le n\le 10^5$), $n$ means $a$'s length.

The next line contains $n$ integers, the $i$-th one means $a_i$ ($1\le a_i\le 4$).

## 输出描述

One integer, means the length of the shortest good interval with at least $k$ $4$s in it.

## 示例1

**输入**
```
6 2
4 1 1 4 2 3
```

**输出**
```
6
```

## 示例2

**输入**
```
8 2
4 2 3 4 1 1 4 2
```

**输出**
```
5
```