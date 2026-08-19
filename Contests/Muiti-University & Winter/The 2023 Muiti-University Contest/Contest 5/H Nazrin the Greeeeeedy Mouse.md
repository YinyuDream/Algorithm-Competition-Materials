# Nazrin the Greeeeeedy Mouse

## 题目描述

There're $n$ cheeses in the house. The $i$-th cheese is between point $i$ and point $i+1$. The $i$-th cheese's size is $a_i$ and its weight is $b_i$.

Nazrin is at point $1$ in the beginning and wants to steal some cheeses. She has $m$ chances to take the cheeses:

In the $i$-th time, Nazrin brings a bag of size $sz_i$. Since she's greedy, for $i>1$, $sz_i\ge sz_{i-1}$ always holds. She can travel from point $1$ and take some cheeses. She can only travel from point $x$ to $x+1$, or backwards. If she wants to travel from point $x$ to point $x+1$, she has to dig a hole on the $x$-th cheese or take it. She can't take a cheese with a hole on it. Of course, the sum of the cheeses' size she takes in the $i$-th time can't be larger than $sz_i$. After taking the cheeses, she needs to go back to point $1$.

Please maximize the sum of the weights of taken cheeses and output it.

## 输入描述

The first line contains two integer $n$ ($1\le n\le 200$) and $m$ ($1\le m\le 10^5$).  

For the following $n$ lines, the $i$-th line contains two integers $a_i$ ($1\le a_i\le 200$) and $b_i$ ($1\le b_i\le 10^5$).  

The next line contains $m$ integers, the $i$-th one is $sz_i$ ($1\le sz_i\le 200$). Notice that for $i>1$, $sz_i\ge sz_{i-1}$.

## 输出描述

One integer, the maximum sum of the weights of taken cheeses.

## 示例

### 示例1

#### 输入
```
5 3
2 10
2 5
1 22
3 7
6 8
1 3 7
```

#### 输出
```
44
```

## 备注

In the example, Nazrin can take actions below to maximize the weight of taken cheeses:

In the first time, Nazrin stays at point $1$ and gives up the first chance to take cheese.

In the second time, Nazrin takes the cheese between point $1$ and point $2$ and returns to point $1$.

In the third time, Nazrin takes all cheeses between point $2$ and point $5$, and goes back to point $1$.