# Palindrome subsequence

## 题目描述

In mathematics, a subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence <A, B, D> is a subsequence of <A, B, C, D, E, F>.
(http://en.wikipedia.org/wiki/Subsequence)

Given a string S, your task is to find out how many different subsequence of S is palindrome. Note that for any two subsequence X = <Sx1, Sx2, ..., Sxk> and Y = <Sy1, Sy2, ..., Syk> , if there exist an integer i (1<=i<=k) such that xi != yi, the subsequence X and Y should be consider different even if Sxi = Syi. Also two subsequences with different length should be considered different.

## 输入格式

The first line contains only one integer T (T<=50), which is the number of test cases. Each test case contains a string S, the length of S is not greater than 1000 and only contains lowercase letters.

## 输出格式

For each test case, output the case number first, then output the number of different subsequence of the given string, the answer should be module 10007.

## 样例输入

```
4
a
aaaaa
goodafternooneveryone
welcometoooxxourproblems
```

## 样例输出

```
Case 1: 1
Case 2: 31
Case 3: 421
Case 4: 960
```

