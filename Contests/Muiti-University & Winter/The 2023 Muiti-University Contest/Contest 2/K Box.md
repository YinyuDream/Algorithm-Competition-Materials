# Box

## 题目描述

Now, the Traveler has $n$ boxes in their possession, some of which have lids that can be shifted left or right by at most one step. If the $i$-th box is covered with a lid, you gain $a_i$ score.(Covering it with multiple lids still gets only $a_i$ score.) Determine the maximum total game score achievable by covering boxes with lids after shifting serveral(possibly, zero) lids.

## 输入描述

The first line contains a integer, $n$ ($1 \leq n \leq 10^6$), representing the number of boxes.

The second line contains $n$ integers, where the $i$-th integer $a_i$ ($0 \leq a_i \leq 10^9$) represents the value of $i$-th box.

The third line contains $n$ integers, where the $i$-th integer $b_i$ ($0 \leq b_i \leq 1$) represents whether $i$-box has a lid. $b_i=0$ means there is no lid on the box.

## 输出描述

An integer represents the answer.

## 示例1

### 输入

```
3
1 2 3
0 1 0
```

### 输出

```
3
```

## 示例2

### 输入

```
3
1 3 1
1 0 1
```

### 输出

```
4
```