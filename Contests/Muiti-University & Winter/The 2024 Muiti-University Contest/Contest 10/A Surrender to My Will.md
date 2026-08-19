# Surrender to My Will

## 题目描述

League of Legends is a famous game where two teams of 5 players each control their own heroes and engage in battles with the objective of destroying the enemy base.

However, many battles can reach a point where it becomes apparent halfway through that one team is on the brink of defeat. Therefore, it has a surrender mechanism.

Specifically, when a member of a team initiates a surrender vote, each member of the team can vote either for or against it. If the number of votes in favor is 4 or more, the surrender is considered successful; otherwise, it fails.

Here is an example of a successful surrender. Even there is a player not voting, the result is able to be declared as successful.

![图片](https://uploadfiles.nowcoder.com/images/20240627/0_1719481270241/799BAD5A3B514F096E69BBC4A7896CD9)

However, often the outcome of the surrender vote can be determined before all team members have voted. You are given the current state of votes, represented as a string $S$ of length 5, where each character can be $\texttt{Y}$ (for a vote in favor), $\texttt{N}$ (for a vote against), or $\texttt{-}$ (indicating no vote yet). The string $S$ satisfies the following constraints:

- The first character is $\texttt{Y}$, indicating the initiator of the surrender vote has voted in favor.
- There exists an index $1\le i\le 5$ such that for all indices $1\le j \le i$, $S[j] \in \{\texttt{Y}, \texttt{N}\}$, and for all indices $j > i$, $S[j] = \texttt{-}$.

Your task is to determine if the final outcome of the surrender vote can be determined based on the given state $S$. If it can be determined, output:
- 1 if the surrender is successful,
- -1 if the surrender fails.

If it cannot be determined based on the given state $S$, output 0.

## 输入描述

A string $S$ of length 5 consisting only of characters $\texttt{Y}$, $\texttt{N}$, and $\texttt{-}$.

## 输出描述

If the result is determined, print $1$ if the vote succeeds and $-1$ otherwise. If the result is not determined and is based on the votes of some players, print $0$.

## 样例输入输出

### 示例1

输入：

```
YYYY-
```

输出：

```
1
```

### 示例2

输入：

```
YNNY-
```

输出：

```
-1
```

说明：

In the input $\texttt{YNNY-}$, at most three members will vote yes in the final result. Therefore, the outcome is negative.

### 示例3

输入：

```
Y----
```

输出：

```
0
```