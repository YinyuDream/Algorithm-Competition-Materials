# B. Two Divisors

## Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then follows the description of the test cases.

The only line of each test cases contains two integers $a$, $b$ ($1 \le a < b \le 10^9$).

It is guaranteed that $a$, $b$ are the two largest divisors for some number $1 \le x \le 10^9$.

## Output

For each test case, output the number $x$, such that $a$ and $b$ are the two largest divisors of the number $x$.

If there are several answers, print any of them.

## Example

### Input

```
8
2 3
1 2
3 11
1 5
5 10
4 6
3 9
250000000 500000000
```

### Output

```
6
4
33
25
20
12
27
1000000000
```

## Note

For the first test case, all divisors less than $6$ are equal to $[1, 2, 3]$, among them the two largest will be $2$ and $3$.

For the third test case, all divisors less than $33$ are equal to $[1, 3, 11]$, among them the two largest will be $3$ and $11$.

For the fifth test case, all divisors less than $20$ are equal to $[1, 2, 4, 5, 10]$, among them the two largest will be $5$ and $10$.

For the sixth test case, all divisors less than $12$ are equal to $[1, 2, 3, 4, 6]$, among them the two largest will be $4$ and $6$.