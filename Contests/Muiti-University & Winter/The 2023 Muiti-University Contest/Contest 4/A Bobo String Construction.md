# Bobo String Construction

## 题目描述

Bobo is studying encoding to send messages to his best friend, oboB. He recently developed a “Bobo encoding,” which is essentially a binary encoding. However, unlike direct binary encoding, “Bobo encoding” consists of three parts: a “start recognition string” $t$ at the beginning, a “message string” $s$ used to transmit information, and an “end recognition string” $t$ that is identical to the “start recognition string.”  

Given a “message string” $s$ that needs to be transmitted and a recognition string $t$, the Bobo encoding of this “message string” $s$ is  

$$
\text{encoding}=t+s+t,
$$

where $+$ indicates string concatenation.  

When sending information, Bobo encrypts the message string he wants to transmit into “Bobo encoding” and transmits it to oboB one by one. oboB will stop receiving information as soon as he finds the recognition string appearing twice in the received string, indicating that he has received both the “start recognition string“ and the “end recognition string.”  

**Note that the recognition string can overlap**, for example, if the recognition string is $t=101$ and oboB receives $10101$, oboB will think that the recognition string has appeared twice, and stop receiving information.

---

Bobo is proud of his “Bobo encoding,” but he has no idea that he has made a huge mistake! One day, Bobo wanted to send the message string $1101$ to oboB, and they agreed that the recognition string was $010$. So the “Bobo encoding” of this message string is  

$$
010+1101+010=0101101010.
$$

However, oboB found that he had received two recognition strings $010$ after receiving the first $8$ characters $01011010$, so he mistakenly took $01011010$ as the “Bobo encoding.”

Nevertheless, Bobo thinks there must be some way to fix this issue. He wants to know if, given a pattern string $t$ and the length $n$ of the message string to be sent, he can find a suitable message string so that the “Bobo encoding” can be correctly interpreted.

Formally, given a string $t$ consisting only of $0$s and $1$s, and a positive integer $n$, can you find a string $s$ consisting only of $0$s and $1$s with a length of $n$ so that $t$ appears **only twice** in $t+s+t$ (only at the beginning and the end)?

## 输入描述

This problem has multiple test cases. The first line contains a positive integer $T$ $(1\leq T\leq 1000)$, denoting the number of test cases.

The first line of each test case contains a positive integer $n$ $(1\leq n\leq 1000)$, denoting the length of the message string that Bobo wants to transmit.

The second line of each test case contains a string $t$ $(1\leq |t|\leq 1000)$, consisting only of $0$s and $1$s, denoting the pattern string agreed upon by Bobo and oboB.

## 输出描述

For each test case, if there is no solution, output $-1$ in a line; otherwise, output a binary string $s$ that meets the requirement. If there are multiple possible answers, you can print any.

## 示例

### 示例输入

```
2
6
101
3
0
```

### 示例输出

```
001100
111
```