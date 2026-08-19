# Groundhog Looking Dowdy

## 题目描述

Groundhog finds that Apple seems to be less intimate than before.

He is very distressed for this.After pondering for a long time, Groundhog finds that he looks too dowdy.So, Groundhog decided to improve a little.

Because Groundhog is lazy, he only lists the clothes that can be worn for the next ${n}$ days. On the ${i^{th}}$ day, the ${j^{th}}$ clothes have a dowdiness $a_{i,j}$.On each day,he will choose one of the clothes and wear it.

And Groundhog should choose ${m}$ days from ${n}$ days to go out with Apple.

Groundhog wants to know the minimum difference between the maximum dowdiness and the minimum dowdiness in ${m}$ days when Groundhog's choice is optimal.

Simplified: You should choose n clothes for each day and then choose m clothes from those n clothes, and the problem is to calculate the minimum difference between the maximum dowdiness and the minimum dowdiness.

## 输入描述:

The first line contains two integers ${n}$ and ${m}$.
Then ${n}$ lines follow,each line contains a integer $k_i$,represents the number of the clothes that can be worn on ${i^{th}}$ day.Then $k_i$ integers $a_{i,j}$ follow.

## 输出描述:

Print in one line the minimum difference.

## 示例1

### 输入

```
4 3
1 3
2 8 6
1 2
3 1 7 5
```

### 输出

```
2
```

### 说明

Apple will pay attention to Groundhog's clothes on day 1, 3, and 4 ,Groundhog will wear clothes with dowdiness of 3, 2, and 1 on day 1, 3, and 4,and the difference is 2.

## 备注:

$1\leqslant a_{i,j}\leqslant 10^{9}$，$1\le n\leqslant  10^6，1 \le m\leqslant n$，the sum of clothes $\leqslant2\cdot10^6$，$k_i \ge 1$