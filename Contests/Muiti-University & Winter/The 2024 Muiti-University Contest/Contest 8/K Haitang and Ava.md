# Haitang and Ava

*One day, Haitang found that Ava would not hold live streaming anymore.*

Ava would say an opening statement at the beginning of the live streaming.

The conditions for a valid opening statement are as follows:

- An empty string is a valid opening statement.
- If $S$ is a valid opening statement, then $S+\texttt{ava}$ and $\texttt{ava}+S$ are also valid opening statements.
- If $S$ is a valid opening statement, then $S+\texttt{avava}$ and $\texttt{avava}+S$ are also valid opening statements.
- Any string that cannot be constructed using the above methods is not a valid opening statement.

Given a string $S$, you need to determine if it is a valid opening statement.

## 输入描述:

Each test contains multiple test cases. The first line contains an integer $T$ ($1\leq T\leq 1.7\times 10^5$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains a string $S$ ($3\leq |S|\leq 5\times 10^5$), consisting of lowercase letters of the English alphabet.

It is guaranteed that the sum of $|S|$ over all test cases does not exceed $5\times 10^5$.

## 输出描述:

For each test case, output “Yes” if $S$ is a valid opening statement, and “No” otherwise.

## 样例输入输出

**输入**
```
5
ava
avavaava
avavava
avaava
haitang
```

**输出**
```
Yes
Yes
No
Yes
No
```