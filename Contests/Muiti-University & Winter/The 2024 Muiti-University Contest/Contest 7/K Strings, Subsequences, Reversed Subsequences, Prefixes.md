# Strings, Subsequences, Reversed Subsequences, Prefixes

## 题目描述

For a string $S=S_0S_1...S_{n-1}$ of length $n$, its reversed string is defined as $R(S)=S_{n-1}S_{n-2}...S_{0}$.

Chino has two strings $S$ and $T$, she wants to know how many **distinct** non-empty subsequences $seq$ of $S$ such that $T$ is simultaneously a prefix of both $seq$ and $R(seq)$.

Since the answer may be large, please output the result modulo $10^9+7$.

Some definitions are seen in the notes for explanation.

## 输入描述:

```
The first line contains two positive integers $N$ and $M$ $(1\leq N,M\leq 10^6)$ --- the lengths of $S$ and $T$.

Then the next two lines contain the contents of strings $S$ and $T$ $(S_i,T_i \in [a,z])$.
```

## 输出描述:

```
Only one line containing a non-negative integer --- the answer to the problem modulo $10^9+7$.
```

## 样例输入输出

### 样例输入

```
7 2
abababa
ab
```

### 样例输出

```
8
```

### 说明

$seq$ can be "aba","abba","ababa","abbba","abaaba","ababba","abbaba","abababa".

## 备注

A non-empty subsequence of string $S$ is defined as a new string obtained by deleting one or zero or more characters from the string (while keeping at least one character).

The prefix of string $S$ is defined as the part left after deleting all characters from a certain position to the end of the string.

Two strings are **distinct** iff their lengths or contents are different.