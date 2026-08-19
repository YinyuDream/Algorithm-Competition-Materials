# Ares, Toilet Ares

## 题目描述

Ares is the Greek god of courage and war. He is one of the Twelve Olympians and the son of Zeus and Hera. In Greek literature, he often represents the physical or violent and untamed aspect of war and is the personification of sheer brutality and bloodlust, in contrast to his sister, the armored Athena, whose functions as a goddess of intelligence include military strategy and generalship.

A Toilet-Ares appeared at the western hub of the mysterious East. They took part in ShengJing AUPC(abnormal university programming competition). There are $n$ problems in this competition. For some irresistible reason, the Toilet-Ares had got solutions to all of the problems. To ensure the fairness of AUPC, the groups of problems' authors changed the problems immediately. They changed $n-m$ problems in total and enhanced data ranges of simplest $a$ of the rest $m$ unchanged problems. The Toilet-Ares seemed to have a little intelligence to solve the simplest $a$ of unchanged problems, while they seemed not willing to pass harder ones for fear of being exposed(or maybe because they didn't get solutions to the harder ones). They have $k$ chances to go to the toilet. Every time they go to toilet, they can attain $x_i$ lines of code related to the problem 'k', while has $p_i$ probability (in the form of $\frac{y}{z}$, $0 \leq y \leq z < 4933$) of failure in solving the problem. Notice that the length of code to solve problem 'k' is $l$. It is guaranteed that $\sum x_i = l$.

## 输入描述:

The first line of input contains five integers $n, m, k, a, l$ $(1 \leq a \leq m \leq n \leq 10^9, 1\leq l \leq 10^{9}, 1\leq k \leq 10^{5})$.

Then $k$ lines follows, each line contains three integers $x_i, y_i, z_i$ $(0 \leq x_i \leq 10^9, 0 \leq y_i \leq z_i < 4933)$.

It is guaranteed that $\sum x_i = l$.

## 输出描述:

One line contains one number donating the number of problems which the Toilet-Ares can accept. The answer is proved to be a fraction as $\frac{p}{q}$. Please output the fraction in module $4933$. (By the way, $4933$ is a special number which consists of two double digits)

## 示例1

### 输入

```
5 3 2 1 5
2 2 3
3 3 4
```

### 输出

```
4523
```

### 说明

In this case, the answer is 1+1/3*1/4=13/12, and it's equal to 4523 in module 4933.