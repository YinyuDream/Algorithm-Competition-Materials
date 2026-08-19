# Hot Water Pipe

## 题目描述

There is a long hot water pipe consisting of $n$ sections, each with a capacity of $1$ unit volume. The $n$ sections are numbered $1$ to $n$ from the left to the right to match the direction of water flow in the pipe.

The initial temperature of the water in section $i$ is $a_i$ and it will drop by $1$ unit every minute. To keep the water warm enough, once the temperature of the water in a section is lower than $T_{min}$, it will be heated to $T_{max}$ immediately (the heating time can be ignored). When the water in the $n$-th section is used, the water in the $i$-th section will move to the $(i+1)$-th section for all $i\in [1,n-1]$ (note that the movements will be completed immediately which means the temperature of the water will not change), and the hot water of temperature $T_{max}$ will be added to section $1$ at the same time. Please note that heat transfer effects are not considered in this problem.

Now, there are $m$ operations using hot water. Each operation can be described as two integers $t,k$, denoting using $k$ units volume of water after $t$ minutes since the last operation (or since the initial time if it is the first operation). Note that the operation is completed immediately. Please output $T \times k$ for every operation, where $T$ stands for the average temperature of the water used. It can be shown that $T \times k$ must be an integer.

## 输入描述

The first line of the input contains four integers $n,m,T_{min},T_{max}$ $(1\leq n,m \leq 10^6)$.

The second line contains $n$ integers, indicating $a_i$ $(1\leq T_{min} \leq a_i \leq T_{max}\leq 10^6)$ respectively.

Each of the next $m$ lines contains two integers $t,k$ $(1\leq t,k \leq 10^6)$, indicating an operation using $k$ units volume of water after $t$ minutes since the last operation.

## 输出描述

For each operation, output a line containing an integer representing your answer.

## 示例

### 输入

```
8 4 18 26
19 20 21 22 23 24 25 26
2 2
10 5
4 10
2 3
```

### 输出

```
47
104
225
72
```

### 说明

Explanation of example:

When the first operation was performed, the temperature of water in section $1\sim n$ is $26,18,19,20,21,22,23,24$ respectively, therefore the answer is $\frac {24+23} {2}\times 2=47$.

When the second operation was performed, the temperature of water in section $1\sim n$ is $25,25,25,26,18,19,20,21$ respectively, therefore the answer is $\frac {21+20+19+18+26} {5}\times 5=104$.

When the third operation was performed, the temperature of water in section $1\sim n$ is $22,22,22,22,22,21,21,21$ respectively, therefore the answer is $\frac {21+21+21+22+22+22+22+22+26+26} {10}\times 10=225$.

When the fourth operation was performed, the temperature of water in section $1\sim n$ is $24,24,24,24,24,24,24,24$ respectively, therefore the answer is $\frac {24+24+24} {3}\times 3=72$.