# Turtle Math: Fast Three Task

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^4$).

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer: the minimum number of moves.

## Sample

```input
8
4
2 2 5 4
3
1 3 2
4
3 7 6 8
1
1
4
2 2 4 2
2
5 5
7
2 4 8 1 9 3 4
2
4 10
```

```output
1
0
0
1
1
2
1
1
```

## Note

In the first test case, initially the array $a = [2, 2, 5, 4]$. One of the optimal ways to make moves is:

- remove the current $4$th element and get $a = [2, 2, 5]$;

As a result, the sum of the elements of the array $a$ will be divisible by $3$ (indeed, $a_1 + a_2 + a_3 = 2 + 2 + 5 = 9$).

In the second test case, initially, the sum of the array is $1+3+2 = 6$, which is divisible by $3$. Therefore, no moves are required. Hence, the answer is $0$.

In the fourth test case, initially, the sum of the array is $1$, which is not divisible by $3$. By removing its only element, you will get an empty array, so its sum is $0$. Hence, the answer is $1$.