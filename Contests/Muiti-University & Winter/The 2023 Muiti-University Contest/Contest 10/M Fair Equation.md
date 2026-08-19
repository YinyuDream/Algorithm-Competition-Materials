# Fair Equation

## 题目描述

Equations are not solvable in a general fashion. Here's an example.

![image](https://uploadfiles.nowcoder.com/images/20230818/0_1692293774475/B65AC2392D1B8760D5BAA82A163BDDDD)

It's not fair to solve unsolvable problems in the contest, so we would like you to solve a easier one. It's decidable in polynomial time, so it's fair.

Xiao Shi is given an equation of the form $A + B = C$, where $A$, $B$ and $C$ are positive integers. However, the equation may not be true at the moment. Xiao Shi can insert a single digit ($0$-$9$) anywhere in the equation, before or after any existing digit, to make it true.

For example, if the equation is $12 + 34 = 146$, Xiao Shi can insert $1$ to $12$ (either $\overline{1}12$ or $1\overline{1}2$) to make it $112 + 34 = 146$.

Xiao Fan's task is to determine if there exists a way to insert a digit in the equation to make it true, or it is already true. Can you help him?

## 输入描述

The first and only line of input contains an equation of the form $A + B = C$, where $A$, $B$ and $C$ are positive integers with no leading zeros. The input satisfies $1 \leq A, B, C \leq 10^6$.

It's guaranteed that there are exactly one space before and after `+` and `=`.

## 输出描述

If there exists a way to insert a digit in the equation to make it true, or it is already true, output `Yes` and the modified equation on two separate lines. Please note that the equation should be presented like input format, i.e., no leading zeros and exactly one space before and after `+` and `=`.

Otherwise, output `No` on a single line.

## 示例

### 示例1

#### 输入

```
12 + 34 = 146
```

#### 输出

```
Yes
112 + 34 = 146
```

### 示例2

#### 输入

```
12 + 34 = 56
```

#### 输出

```
No
```

## 备注

English Statements (PDF): https://uploadfiles.nowcoder.com/files/20230818/427407_1692296632505/contest-33918-en.pdf