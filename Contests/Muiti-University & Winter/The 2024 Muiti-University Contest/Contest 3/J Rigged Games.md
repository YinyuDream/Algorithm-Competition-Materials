# Rigged Games

## 题目描述

In a two-player competitive match, for any positive integer $a$, we define the Best of $2a-1$ format as follows: the two players continue to compete until one of them wins $a$ times, thereby winning the overall match. The Best of $2a-1$ format includes a maximum of $2a-1$ games and a minimum of $a$ games.

For any two positive integers $a$ and $b$, we define the Best of $2b-1$ of Best of $2a-1$ format as follows: the two players compete in a major match using the Best of $2b-1$ format, which consists of a maximum of $2b-1$ major games and a minimum of $b$ major games. Each major game is a Best of $2a-1$ format, consisting of a maximum of $2a-1$ minor games and a minimum of $a$ minor games. For example, Team A and Team B play a Best of $3$ of Best of $5$ match. Here are some possible outcomes (we use $1$ to represent a win for Team A and $0$ to represent a win for Team B):

- 000111000 (Team A loses the first and third major games 0:3, wins the second major game 3:0, so the overall score is a 1:2 loss for Team A);
- 0110000110 (Team A loses the first and second major games 2:3, so the overall score is a 0:2 loss for Team A).

Team A and Team B are currently engaged in a DotA2 match using the Best of $2b-1$ of Best of $2a-1$ format. To the spectators, this is an exciting event! However, unknown to the spectators, the entire match outcome is predetermined: there is a "script" of length $n$ represented by a binary string $T$, where the results of the minor games will continuously repeat this pattern of $01$. Having this information, you want to know the match results when the "script" $01$ string is repeated from each position (see the sample explanation for details).

## 输入描述

```
The first line of input contains three integers $n$, $a$, $b$ $(1\leq n,a,b\leq 10^5)$, whose meanings are already given in the statement.

The second line of input contains a binary "script" string $T$ with length $n$.
```

## 输出描述

```
Output a binary string $ans$ of length $n$, where $ans[i]$ $(1 \leq i \leq n)$ represents the final match result when repeating the script string $T$ starting from the $i$-th position of $T$.
```

## 样例输入输出

### 样例1

输入：
```
3 1 1
001
```

输出：
```
001
```

### 样例2

输入：
```
7 2 2
1010101
```

输出：
```
1110111
```

### 样例3

输入：
```
10 5 3
1001011001
```

输出：
```
0011010011
```

### 样例4

输入：
```
10 2 4
1010000011
```

输出：
```
0000011110
```

### 样例5

输入：
```
2 100000 100000
01
```

输出：
```
01
```

## 备注

For the second sample test, the situation starting from each position is as follows:

Starting from the first position, the match results in $1010101\cdots$, and the final match sequence is $10101011$. Team A wins 2:1 in major matches, with scores of 2:1, 1:2, 2:0, respectively.

Starting from the second position, the match results in $0101011\cdots$, and the final match sequence is $010101101$. Team A wins 2:1 in major matches, with scores of 1:2, 2:1, 2:1, respectively.

Starting from the third position, the match results in $1010110\cdots$, and the final match sequence is $101011$. Team A wins 2:0 in major matches, with scores of 2:1, 2:1, respectively.

Starting from the fourth position, the match results in $0101101\cdots$, and the final match sequence is $01011010$. Team A loses 1:2 in major matches, with scores of 1:2, 2:0, 1:2, respectively.

Starting from the fifth position, the match results in $1011010\cdots$, and the final match sequence is $101101$. Team A wins 2:0 in major matches, with scores of 2:1, 2:1, respectively.

Starting from the sixth position, the match results in $0110101\cdots$, and the final match sequence is $011010101$. Team A wins 2:1 in major matches, with scores of 2:1, 1:2, 2:1, respectively.

Starting from the seventh position, the match results in $1101010\cdots$, and the final match sequence is $11010101$. Team A wins 2:1 in major matches, with scores of 2:0, 1:2, 2:1, respectively.