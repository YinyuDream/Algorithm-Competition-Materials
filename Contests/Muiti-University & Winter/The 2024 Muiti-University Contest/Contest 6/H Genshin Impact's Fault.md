# Genshin Impact's Fault

## 题目描述

In Genshin Impact, making wishes is an action trying to obtain some specific character.

In this problem, there are four possible results for making wishes: $3$-star weapon, $4$-star weapon/character, $5$-star non-promotional weapon/character, $5$-star promotional weapon/character. Here, we do not distinguish between weapon and character, and we use $3$, $4$, $5$, and $U$ to represent each result, respectively.

There are some rules for making wishes.

- For every consecutive $10$ wishes, it will not only contain $3$-star weapons.
- For every consecutive $90$ wishes, it must contain at least one $5$-star weapon/character, no matter whether it is promotional.
- For every two neighboring $5$-star weapons/characters, there must be at least one which is promotional. Here, two $5$-star weapons/characters are called neighboring if and only if all wishes between them are not $5$-star weapons/characters.

Now you're given a list of wishes. Determine if it fits in the above rules.

## 输入描述

The first line contains one integer $T$ ($1\le T \le 10^5$), representing the number of test cases.

For each test case, one single line contains a string $S$ ($1 \le |S| \le 10^6$), which only contains $3$, $4$, $5$, and $U$.

It is guaranteed that $\sum |S| \le 10^6$.

## 输出描述

For each test case, if it fits in the above rules, output "$\texttt{valid}$", otherwise output "$\texttt{invalid}$".

## 样例输入输出

### 样例输入

```
5
433333333334
34343453434
333335333335
UUUUUUUUUU
5U5U5U5U5U4
```

### 样例输出

```
invalid
valid
invalid
valid
valid
```