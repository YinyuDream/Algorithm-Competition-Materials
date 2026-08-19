# Cirno's Perfect Equation Class

## 题目描述

Ran is a puzzle lover and loves solving all kinds of math puzzles. One day, Cirno gives her an easy equation: $ka+b=c$.

Cirno gives the value of $k$, $c$ and $n$, and want to know how many positive integer pairs $(a,b)$ satisfy $ka+b=c$, $b|c$ (that means $c=xb$, $x\ge1$ and $x$ is an integer) and $\gcd(a,b)\ge n$.

Cirno will ask $q$ questions (that means there'll be $q$ data cases). Help Ran answer them!

## 输入描述

The first line contains on integer $q$ ($1\le q\le 100$), means the number of test cases.
For the next $q$ lines, each line contains three integers $k,c,n$ ($1\le k,c,n\le 10^9$).

## 输出描述

For each question, output a single integer representing the number of pairs $(a,b)$ satisfying all restrictions.

## 示例

### 示例输入

```
3
4 30 2
5 30 1
3 28 6
```

### 示例输出

```
2
3
1
```

## 备注

In the first question, there're two legal pairs $(5,10)$ and $(6,6)$. Notice that $(7,2)$ is illegal because $\gcd(7,2)=1<2$. $(0,30)$ is also illegal because $0$ isn't a positive integer.