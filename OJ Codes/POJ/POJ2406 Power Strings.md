# Power Strings

## 题目描述

Given two strings a and b we define $a*b$ to be their concatenation. For example, if a = "abc" and b = "def" then $a*b$ = "abcdef". If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).

## 输入格式

Each test case is a line of input representing s, a string of printable characters. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.

## 输出格式

For each s you should print the largest n such that s = a^n for some string a.

## 样例输入

```
abcd
aaaa
ababab
.
```

## 样例输出

```
1
4
3
```

## Hint

This problem has huge input, use scanf instead of cin to avoid time limit exceed.
