# Tada!

## 题目描述

There is a combination lock with $n~ (1 \leq n \leq 5)$ digits , each digit being between $0 \sim 9$. For each digit, turning it clockwise by one position will change the digit from $x$ to $x + 1 \bmod 10$. For example, $0$ becomes $1$, $1$ becomes $2$, and $9$ turns into $0$. Turning it counterclockwise does the opposite, changing the digit to $x + 9 \bmod 10$.

Little Cyan Fish has locked the secrets of the China Clattering Processing Contest (CCPC) with this combination lock. Every day, to secure the secrets, Little Cyan Fish scrambles the combination by repeating the following operations for some number of times: turning an interval $[l, r]~(1 \leq l \leq r \leq n)$ of digits by one position, each turn accompanied by a distinct ``tada'' sound.

As Big Black Fish, who is secretly positioned next to Little Cyan Fish, you aim to steal the secrets for a reward. You eavesdrop on Little Cyan Fish's locking process daily, recording the number of ``tada'' sounds --- which is the number of operations, and then inspect the digits on the lock in the dead of night.

You have collected $m$ pieces of information, and you need to determine whether the information collected uniquely identifies the correct combination.

## 输入描述

```
The input consists of multiple test cases. The first line contains $T~ (1 \leq T \leq 1000)$, the number of test cases.

For each test case, the first line contains two numbers, $n, m ~ (1 \leq n \leq 5, 1 \leq m \leq 50)$, separated by a space.

The next $m$ lines contain a string of $n$ digits $s_i$ and an integer $t_i~(0 \leq t_i \leq 50)$, indicating the combination displayed is $s_i$, resulting from $t_i$ operations on the correct combination. The digit string and the number are separated by a space.

It is guaranteed that $\sum_{n} 10 ^ n \leq 3 \times 10 ^ 5$ for all $T$ cases.
```

## 输出描述

```
For each test case:

* If there is a unique solution, output a line with the $n$-digit combination.
* If there are multiple solutions, output a line with the string \texttt{MANY}.
* If there is no solution, indicating an error in the records, output a line with the string \texttt{IMPOSSIBLE}.
```

## 样例输入输出

### 输入

```plain
3
3 3
003 1
003 3
025 1
3 2
000 1
999 1
1 2
0 0
1 0
```

### 输出

```plain
014
MANY
IMPOSSIBLE
```

## 说明

For the first sample, the following are possible operation sequences:

* $003 \xrightarrow{2\sim 3,+} 014$ ;
* $003 \xrightarrow{2\sim 3,+} 014 \xrightarrow{1\sim 1,+} 114 \xrightarrow{1\sim 1,-} 014$ ;
* $025 \xrightarrow{2\sim 3,-} 014$.

For the second sample, $009, 099, 990, 900$ are all possible.