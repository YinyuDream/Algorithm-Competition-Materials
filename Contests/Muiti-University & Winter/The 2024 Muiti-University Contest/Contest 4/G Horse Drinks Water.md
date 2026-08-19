# Horse Drinks Water

## 题目描述

This problem is a variant of the General’s Horse Drinking Water problem.

Given that the general’s horse is at point $(x_G, y_G)$, the tent is at point $(x_T, y_T)$, and the river is located along the positive half of the x-axis and the positive half of the y-axis, find the shortest distance the horse needs to travel to drink water from the river and return to the tent.

## 输入描述:

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^5$). The description of the test cases follows.

Each test case consists of a single line containing four integers $x_G, y_G, x_T, y_T$ ($0 \leq x_G, y_G, x_T, y_T \leq 10^9$), describing the positions of the general’s horse and the tent.

## 输出描述:

For each test case, output a decimal number representing the shortest distance the horse needs to travel to drink water from the river and return to the tent.

Your answer is considered correct if its absolute or relative error does not exceed $10^{-9}$.

Formally, let your answer be $a$, and the jury’s answer be $b$. Your answer is accepted if and only if $\frac{|a - b|}{\max(1, |b|)} \leq 10^{-9}$.

## 样例输入输出

### 示例1

**输入**

```
5
1 3 3 3
1 1 1 1
1 5 4 2
11 4 5 14
19 1 9 810
```

**输出**

```
4
2
5.8309518948
18.8679622641
809.4844038028
```

## 备注:

In test case 3, the optimal path is:
![图片](https://uploadfiles.nowcoder.com/images/20240711/0_1720677634515/75F60A0FC4890882425A751C4E49375D)