# Make it Zigzag

## Problem Description

An array $b$ of length $m$ is considered **awesome** if for all $i$ ($1 \le i < m$):

* if $i$ is **odd** then $b_i < b_{i+1}$;
* if $i$ is **even** then $b_i > b_{i+1}$.

In other words, the following inequality is true:
$$b_1 < b_2 > b_3 < b_4 \ldots$$

You are given an array of positive integers $a$ of length $n$.
You may do either of the following operations any number of times, in any order:

* **Operation 1**: select an integer $i$ ($1 \le i \le n$) and do  

  $$a_i := \max(a_1,\ldots,a_i),$$  

  i.e. replace $a_i$ with the prefix maximum up to position $i$.
* **Operation 2**: select an integer $i$ ($1 \le i \le n$) and then decrease $a_i$ by $1$.

Determine the minimum number of times you need to do **operation 2** to make $a$ awesome.
Note that you do **not** need to minimise the number of times you perform operation 1.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$).

The description of the test cases follows.

For each test case:

* The first line contains an integer $n$ ($2 \le n \le 2 \cdot 10^5$) – the length of the array $a$.
* The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

The sum of $n$ across all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output the minimum cost (the minimum number of operations of type 2) to make $a$ awesome.

## Sample

```input
7
5
1 4 2 5 3
4
3 3 2 1
5
6 6 6 6 6
7
1 2 3 4 5 6 7
3
3 2 1
2
1 2
9
65 85 19 53 21 79 92 29 96
```

```output
0
1
3
6
1
0
13
```

## Note

In the first test case the array is already awesome, so no operations are needed.

In the second test case $a$ can be made awesome as follows:

* use operation 2 and decrease $a_1$ by $1$:

  $$[3, 3, 2, 1] \rightarrow [2, 3, 2, 1].$$

* use operation 1 and change $a_4$ to $\max(2, 3, 2, 1) = 3$:

  $$[2, 3, 2, 1] \rightarrow [2, 3, 2, 3].$$

The resulting array $[2, 3, 2, 3]$ is awesome because $2 < 3 > 2 < 3$.
It can be proven that this uses the smallest possible number of operations of type 2.