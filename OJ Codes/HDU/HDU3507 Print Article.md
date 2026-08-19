# Print Article

## 题目描述

Zero has an old printer that doesn't work well sometimes. As it is antique, he still like to use it to print articles. But it is too old to work for a long time and it will certainly wear and tear, so Zero use a cost to evaluate this degree.
One day Zero want to print an article which has N words, and each word i has a cost Ci to be printed. Also, Zero know that print k words in one line will cost

$$(\sum_{i=1}^{k}C_i)^2+M$$

M is a const number.
Now Zero want to know the minimum cost in order to arrange the article perfectly.

## 输入格式

There are many test cases. For each test case, There are two numbers N and M in the first line (0 ≤ n ≤ 500000, 0 ≤ M ≤ 1000). Then, there are N numbers in the next 2 to N + 1 lines. Input are terminated by EOF.

## 输出格式

A single number, meaning the mininum cost to print the article.

## 样例输入

```
5 5
5
9
5
7
5
```

## 样例输出

```
230
```

