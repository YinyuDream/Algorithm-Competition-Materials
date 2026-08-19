# Doremy's IQ 2

## 题目描述

Doremy is asked to test $n$ contests. The difficulty of contest $i$ is $a_i$. In the following $n$ days, Doremy has to test all $n$ contests, one contest per day. Each contest should be tested only once, but can be tested in any order. Initially, Doremy's IQ is $0$, and it may change after each test.

If Doremy chooses to test a contest with difficulty $d$ and now Doremy's IQ is $x$, the following happens:
- if $d>x$, Doremy will feel inspired, so her IQ increases by $1$;
- if $d<x$, Doremy will feel fooled, so her IQ decreases by $1$;
- if $d=x$, Doremy will feel satisfied, and her IQ will not change.

Doremy wants to encounter as many $d=x$-type contest as possible. Please help Doremy find out the number.

## 输入描述:

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 10^4$) - the number of test cases. The description of the test cases follows.

The first line contains one integer $n$ ($1 \le n \le 10^5$) - the number of contests.

The second line contains $n$ integers $a_1,a_2,\cdots,a_n$ ($-n \le a_1 \le a_2 \le \cdots \le a_n \le n$) - the difficulty of each contest.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3\cdot 10^5$.

## 输出描述:

For each test case, output the maximum number of $d=x$-type contests that Doremy can encounter.

## 样例输入输出

**输入**

```
5
5
1 2 3 4 5
5
-2 -1 0 1 2
8
-8 -3 -2 -2 -2 1 1 8
1
0
2
0 1
```

**输出**

```
2
2
4
1
1
```