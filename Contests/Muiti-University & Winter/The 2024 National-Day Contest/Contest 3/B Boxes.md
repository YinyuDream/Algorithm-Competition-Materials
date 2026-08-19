# Boxes

## 题目描述

There're $n$ boxes in front of you. You know that each box contains a ball either in white or in black. The probability for a ball to be white is $\frac{1}{2}$, and the colors of balls are independent of each other. The PJ King invites you to guess the colors of all balls. PJ King has assigned some costs to the boxes. If we number the boxes from $1$ to $n$, the cost to open the box $i$ is $w_i$, and after a box is opened you can see the ball inside this box.

For sure, there's no way to know all the colors except by opening all boxes. However, Gromah wants to give you some hints. Gromah can tell you secretly the number of black balls among all boxes that have not been opened yet, but you have to pay $C$ cost to get one such hint from Gromah. Anyway, if you're superpowered, you can do it without any hint. What's the mathematical expectation of the minimum cost to figure out all colors of balls?

## 输入描述

The first line contains an integer $n~(1\le n \le 10^5)$ and a decimal $C~(0 < C \le 10^9)$, representing the number of boxes and the cost to get a hint from Gromah.

The second line contains $n$ decimals $w_1, w_2, \cdots, w_n~(0 < w_i \le 10^9)$.

All decimal numbers in the input have at most six decimal places.

## 输出描述

Output one line with the expected minimum cost. Your answer will be considered to be correct if the relative or absolute error is less than $10^{-6}$.

## 样例输入

```
2 0.1
1 1
```

## 样例输出

```
0.6
```

## 说明

For the first test case, you can pay $0.1$ cost to get a hint from Gromah. If the number of black balls is $0$ or $2$, you will know the colors in each box. This case has a probability of $\frac{1}{2}$. Otherwise, you will know that the colors of the two balls are distinct, so you only have to open any of the boxes. Therefore, the expected cost is $0.1 + \frac{1}{2} \times 1 = 0.6$.

## 样例输入

```
4 0.123456
1 1 1 1
```

## 样例输出

```
2.248456
```