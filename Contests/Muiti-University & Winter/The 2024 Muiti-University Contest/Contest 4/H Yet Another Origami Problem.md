# Yet Another Origami Problem

Fried-chicken hates origami problems! He always fails at solving origami problems that others can solve easily (for example, CF1966E and HDU6822). However, today Fried-chicken is the problem setter! It’s his turn to give contestants a very difficult origami problem!

Given an array $a$ of length $n$, you can perform the following operations any number of times (possibly zero):

Choose an index $p$, and then perform one of the following two operations:

1. For all $i$ such that $a_i \leq a_p$, let $a_i \gets a_i + 2(a_p - a_i)$.
2. For all $i$ such that $a_i \geq a_p$, let $a_i \gets a_i - 2(a_i - a_p)$.

For example, if the original array is $[2,4,5,3]$ and you choose $p=2$ and perform operation 1, the array will become $[6,4,5,5]$.

Now, you want to minimize the range of the array through these operations. Recall that the range of an array is the difference between the maximum and minimum elements of the array.

## 输入描述:

```
Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 5 \times 10^5$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^5$), representing the length of the array.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^{16}$), describing the elements of the array $a$ in the initial state.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5\times 10^5$.
```

## 输出描述:

```
For each test case, output one integer on a single line, representing the minimum range of the array after any number of operations.
```

## 样例输入输出

**输入**

```plain
3
4
2 4 5 3
3
1 2 100
1
10000
```

**输出**

```plain
1
1
0
```