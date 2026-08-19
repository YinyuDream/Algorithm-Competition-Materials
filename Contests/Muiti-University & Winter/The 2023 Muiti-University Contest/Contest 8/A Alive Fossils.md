# Alive Fossils

## 题目描述

Nowcoder Multi-University Training Camp is now holding again. As a contestant, you are a little bit curious about the problem setters. Now you have a list of the problem setters among all the $n$ Nowcoder Multi-University Training Camps, and you are curious about the alive fossil setters, who set problems in all the $n$ camps. Please output the alive fossil setters in the lexicographic order.

## 输入描述

The first line contains one integer $n$ ($1\le n\le 10^5$), denoting the number of Nowcoder Multi-University Training Camps ever held.

For each training camp:

The first line contains one integer $c$ ($1 \le c \le 10^5$), denoting the number of problem setters.

Each of the following $c$ lines contains a string containing lowercase letters and digits only, denoting a problem setter in the camp. No problem setters appear more than once in a training camp.

It is guaranteed the total length of strings in all training camps does not exceed $10^6$.

## 输出描述

Output a single integer $f$ in the first line, and then output all the $f$ alive fossil setters in the lexicographic order in the following $f$ lines.

## 示例1

### 示例输入

```
2
14
buaa
bit
sunsiyu
uestc
ezec
qcjjfanclub
nfls
oscar114514
jianglyfan
gromah
calabash
lzr010506
gispzjz
roundgod
13
uestc
bit
buaa
gispzjz
roundgod
ynoi
hdu
oscar114514
gromah
calabash
quailty
nfls
sjtu
```

### 示例输出

```
9
bit
buaa
calabash
gispzjz
gromah
nfls
oscar114514
roundgod
uestc
```