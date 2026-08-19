# King of Range

## 题目描述

Given $n$ integers $a_1,a_2,\cdots,a_n$ and $m$ queries. For each query, you are given a const $k$ and you should determine how many different pairs $(l,r)$ are there meeting the condition that the range of the subsequence $a_l,a_{l+1},\cdots,a_r$ is strictly greater than $k$.

Note: the range of a sequence equals the difference between the maximum and the minimum of the sequence.

## 输入描述:

The first line contains two integers $n,m\,(1 \le n \le 10^5, 1 \le m \le 200)$, denoting the number of given integers and the number of queries respectively.

The second line contains n integers $a_1, a_2, \cdots, a_n\,(1 \le a_i \le 10^9)$, denoting the given integers.

Next m lines each contains one integer $k\,(1 \le k \le 10^9)$, denoting the queries.

## 输出描述:

Print $m$ lines each contains one integer, denoting the answers.

## 示例1

### 输入

```
5 1
1 2 3 4 5
2
```

### 输出

```
3
```

### 说明

There are three pairs, $(1,4),(1,5),(2,5)$, which meet the condition.