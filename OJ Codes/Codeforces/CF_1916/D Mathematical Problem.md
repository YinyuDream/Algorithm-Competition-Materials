# Mathematical Problem

The mathematicians of the 31st lyceum were given the following task:

You are given an **odd** number $n$, and you need to find $n$ different numbers that are squares of integers. But it's not that simple. Each number should have a length of $n$ (and should not have leading zeros), and the multiset of digits of all the numbers should be the same. For example, for $\texttt{234}$ and $\texttt{432}$, and $\texttt{11223}$ and $\texttt{32211}$, the multisets of digits are the same, but for $\texttt{123}$ and $\texttt{112233}$, they are not.

The mathematicians couldn't solve this problem. Can you?

## Input

The first line contains an integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The following $t$ lines contain one **odd** integer $n$ ($1 \leq n \leq 99$) — the number of numbers to be found and their length.

It is guaranteed that the solution exists within the given constraints.

It is guaranteed that the sum of $n^2$ does not exceed $10^5$.

The numbers can be output in any order.

## Output

For each test case, you need to output $n$ numbers of length $n$ — the answer to the problem.

If there are several answers, print any of them.

## Example

### Input
```
3
1
3
5
```
### Output
```
1
169
196
961
16384
31684
36481
38416
43681
```

## Note

Below are the squares of the numbers that are the answers for the second test case:

\[
\texttt{169} = \texttt{13}^2
\]

\[
\texttt{196} = \texttt{14}^2
\]

\[
\texttt{961} = \texttt{31}^2
\]

Below are the squares of the numbers that are the answers for the third test case:

\[
\texttt{16384} = \texttt{128}^2
\]

\[
\texttt{31684} = \texttt{178}^2
\]

\[
\texttt{36481} = \texttt{191}^2
\]

\[
\texttt{38416} = \texttt{196}^2
\]

\[
\texttt{43681} = \texttt{209}^2
\]