# idol!!

## 题目描述

Akuya has finally obtained Shinki Hikari's iPhone. Now, he needs to crack the password to gather evidence!

Blindly attempting to crack the password won't work, so Akuya found a note inside Shinki Hikari's phone case. On it was a puzzle! He believes the solution to this puzzle is the phone's password. The puzzle is as follows:

Given a positive integer $n$, the double factorial of $n$ is the product of all positive integers with the same odd/even parity as $n$ and not exceeding $n$. It is denoted as $n!!$, for example, $5!! = 1 \times 3 \times 5, 6!! = 2 \times 4 \times 6$.

Find the number of trailing zeros in the decimal representation of the product $1!! \times 2!! \times 3!! \times \dots \times n!!$.

Akuya is just one step away from achieving his revenge. Can you help him?

## 输入描述

Input one line containing a positive integer $n (1 \leq n \leq 10^{18})$.

## 输出描述

Only one line, containing a integer, represents the answer.

## 示例

### 输入

```
11
```

### 输出

```
5
```

### 说明

$1!!\times 2!!\times 3!!\times \dots \times 11!!$ = 52563198423859200000