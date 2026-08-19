# C. Restore the Array

## Problem Description

Kristina had an array $a$ of length $n$ consisting of non-negative integers.

She built a new array $b$ of length $n-1$, such that $b_i = \max(a_i, a_{i+1})$ ($1 \le i \le n-1$).

For example, suppose Kristina had an array $a$ = [3, 0, 4, 0, 5] of length 5. Then she did the following:

1. Calculated $b_1 = \max(a_1, a_2) = \max(3, 0) = 3$;
2. Calculated $b_2 = \max(a_2, a_3) = \max(0, 4) = 4$;
3. Calculated $b_3 = \max(a_3, a_4) = \max(4, 0) = 4$;
4. Calculated $b_4 = \max(a_4, a_5) = \max(0, 5) = 5$.

As a result, she got an array $b$ = [3, 4, 4, 5] of length 4.

You only know the array $b$. Find any matching array $a$ that Kristina may have originally had.

## Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of elements in the array $a$ that Kristina originally had.

The second line of each test case contains exactly $n-1$ non-negative integers — elements of array $b$ ($0 \le b_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$, and that array $b$ was built correctly from some array $a$.

## Output

For each test case on a separate line, print exactly $n$ non-negative integers — the elements of the array $a$ that Kristina originally had.

If there are several possible answers — output any of them.

## Sample

### Input
```
11
5
3 4 4 5
4
2 2 1
5
0 0 0 0
6
0 3 4 4 3
2
10
4
3 3 3
5
4 2 5 5
4
3 3 3
4
2 1 0
3
4 4
6
8 1 3 5 10
```

### Output
```
3 0 4 0 5
2 2 1 1
0 0 0 0 0
0 0 3 4 3 3
10 10
3 3 3 1
4 2 2 5 5
3 3 3 3
2 1 0 0
2 4 4
8 1 1 3 5 10
```