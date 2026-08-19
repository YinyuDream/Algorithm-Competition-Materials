# First Last

## Problem Description

Xiao Fan is playing a game with $n$ players, where you always find himself ranking either first or last.

![image](https://uploadfiles.nowcoder.com/images/20230818/0_1692291842773/65CC36FAD96101A4ABBBB8A73781B876)

This is quite strange, right? One possible explanation is that the game system is rigged; another possible explanation is that Xiao Fan is risk‑taking and would seize every opportunity to reach the top spot at the expense of lower expected scores.

Now, suppose Xiao Fan is an average player who ranks uniformly at random each time independently. How likely is it that Xiao Fan is always the ``outstanding'' one, either first or last, in $m$ consecutive games?

To be more precise, in an $n$ player game, an average player takes rank $i~ (1 \leq i \leq n)$ with probability $1/n$. The first means the rank $1$, and the last means the rank $n$.

## Input Description

Input contains two integers, $n, m ~ (1 \leq n, m \leq 20)$, the number of players in each game and the number of games to be considered.

## Output Description

Print a real number presented by decimal format, denoting the possibility.

Your answer will be accepted if the absolute or relative error is at most $10^{-9}$.

## Sample

### Sample 1

**Input**
```
4 10
```

**Output**
```
0.000976562500000
```

### Sample 2

**Input**
```
2 20
```

**Output**
```
1.000000000000000
```

### Sample 3

**Input**
```
3 3
```

**Output**
```
0.296296296296296
```

## Note

[English Statements (PDF)](https://uploadfiles.nowcoder.com/files/20230818/427407_1692296632505/contest-33918-en.pdf)