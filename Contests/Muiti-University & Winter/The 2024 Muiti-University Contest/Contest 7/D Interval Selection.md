# Interval Selection

## 题目描述

YangQiShaoNian has an array of length $n$, a subarray $[l,r]$ in the array is good if and only if each element in $a_l,a_{l+1},\dots a_r$ appears exactly $k$ times in the current interval.

For example, for $a=[1,1,2,3,2,3,1]$ and $k=2$, the intervals $[1,2]$, $[3,6]$, $[1,6]$, etc., are all good. However, $[1,3]$ does not meet the condition because the element $2$ appears only once, and $[1,7]$ does not meet the condition because the element $1$ appears $3$ times.

Please help YangQiShaoNian to find the number of good intervals that can be selected.

## 输入描述

```
The first line contains an integer $T(1\leq T \leq 10^5)$, indicating the number of test cases.

For each test case:

The first line contains two integers $n(1\leq n\leq 2\cdot 10^5),k(1\leq k\leq n)$.

The second line contains $n$ integers $a_1\dots a_n(0\leq a_i\leq 10^9)$ --- each element of the array.

It is guaranteed that the total sum of $n$ for all test cases does not exceed $2\cdot 10^5$.
```

## 输出描述

```
For each test case:

Only output one line containing an integer, representing the answer.
```

## 样例输入输出

### 样例输入

```plain
4
3 2
1 2 2
3 1
1 2 3
6 2
1 1 4 5 1 4
6 3
1 2 1 1 1 1
```

### 样例输出

```plain
1
6
1
2
```