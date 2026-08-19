# Non-Palindromic Substring

## Problem Description

A string $t$ is said to be $k$-good if there exists at least one substring$^\dagger$ of length $k$ which is not a palindrome$^\ddagger$. Let $f(t)$ denote the sum of all values of $k$ such that the string $t$ is $k$-good.

You are given a string $s$ of length $n$. You will have to answer $q$ of the following queries:

- Given $l$ and $r$ ($l < r$), find the value of $f(s_l s_{l+1} \ldots s_r)$.

---

### $\dagger$ A substring of a string $z$ is a contiguous segment of characters from $z$.

### $\ddagger$ A palindrome is a string that reads the same backwards as forwards.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2 \cdot 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($2 \le n \le 2 \cdot 10^5, 1 \le q \le 2 \cdot 10^5$), the size of the string and the number of queries respectively.

The second line of each test case contains the string $s$. It is guaranteed the string $s$ only contains lowercase English characters.

The next $q$ lines each contain two integers, $l$ and $r$ ($1 \le l < r \le n$).

It is guaranteed the sum of $n$ and the sum of $q$ both do not exceed $2 \cdot 10^5$.

## Output

For each query, output $f(s_l s_{l+1} \ldots s_r)$.

## Example

### Input
```
5
4 4
aaab
1 4
1 3
3 4
2 4
3 2
abc
1 3
1 2
5 4
pqpcc
1 5
4 5
1 3
2 4
2 1
aa
1 2
12 1
steponnopets
1 12
```

### Output
```
9
0
2
5
5
2
14
0
2
5
0
65
```

## Note

In the first query of the first test case, the string is $\texttt{aaab}$. $\texttt{aaab}$, $\texttt{aab}$ and $\texttt{ab}$ are all substrings that are not palindromes, and they have lengths $4$, $3$ and $2$ respectively. Thus, the string is $2$-good, $3$-good and $4$-good. Hence, $f(\texttt{aaab}) = 2 + 3 + 4 = 9$.

In the second query of the first test case, the string is $\texttt{aaa}$. There are no non-palindromic substrings. Hence, $f(\texttt{aaa}) = 0$.

In the first query of the second test case, the string is $\texttt{abc}$. $\texttt{ab}$, $\texttt{bc}$ and $\texttt{abc}$ are all substrings that are not palindromes, and they have lengths $2$, $2$ and $3$ respectively. Thus, the string is $2$-good and $3$-good. Hence, $f(\texttt{abc}) = 2 + 3 = 5$. Note that even though there are $2$ non-palindromic substrings of length $2$, we count it only once.