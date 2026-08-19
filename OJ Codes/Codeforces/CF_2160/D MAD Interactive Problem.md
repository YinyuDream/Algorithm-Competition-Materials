# MAD Interactive Problem

## 题目描述

*This is an interactive problem.*

There is a secret sequence $a_1, a_2, \ldots, a_{2n-1}, a_{2n}$, which contains each integer from $1$ to $n$ **exactly twice**.

Your task is to guess the sequence by using queries of the following type:

- `? k j1 j2 ... jk` — select the integer $k$ ($1 \le k \le 2n$) and $k$ **distinct** indices $j_1, j_2, \ldots, j_k$ ($1 \le j_1, j_2, \ldots, j_k \le 2n$). In response to the query, the jury will return $\text{MAD}([a_{j_1}, a_{j_2}, \ldots, a_{j_k}])$.

We define the $\operatorname{MAD}$ (Maximum Appearing Duplicate) of an integer sequence as the largest integer that appears at least twice. Specifically, if there is no number that appears at least twice, the $\operatorname{MAD}$ value is $0$. Some examples are as follows:

- $\operatorname{MAD}([1, 2, 1]) = 1$;
- $\operatorname{MAD}([2, 2, 3, 3]) = 3$;
- $\operatorname{MAD}([1, 2, 3, 4]) = 0$.

Please identify the secret sequence **using at most $3n$ queries**.

## 输入描述

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 3000$). The description of the test cases follows.

The first line of each test case contains one integer $n$ ($2 \le n \le 300$).

It is guaranteed that the sum of $n^2$ over all test cases does not exceed $10^5$.

After you read this line of input, the interaction begins with your first query.

## 输出描述

To make a query, output a line (without quotes) in the following format:

- `? k j1 j2 ... jk` ($1 \le k \le 2n$, $1 \le j_1, j_2, \ldots, j_k \le 2n$)

Here, the indices $j_1, j_2, \ldots, j_k$ which you selected must be **pairwise distinct**.

Then, after each query, read a single integer — the answer to your query.

You can make at most $3n$ queries of this type.

If your program has found the sequence $a$, print the line (without quotes) in the following format:

- `! a1 a2 ... a2n-1 a2n` ($1 \le a_i \le n$)

Note that this does not count towards the query limit.

After printing each line, do not forget to output the end of line and flush the output buffer.

## 样例输入输出

```input
2

2

0

1

2

0

1

1
```

```output
? 2 2 1

? 2 1 3

? 3 1 3 4

! 2 2 1 1

? 2 1 2

? 2 1 3

? 3 1 3 4

! 1 2 1 2
```

## 备注说明

In the first test case, the hidden sequence is $a=[2,2,1,1]$.

For the query `? 2 2 1`, the jury returns $2$ because $\operatorname{MAD}([a_2, a_1]) = \operatorname{MAD}([2, 2]) = 2$.

For the query `? 2 1 3`, the jury returns $0$ because $\operatorname{MAD}([a_1, a_3]) = \operatorname{MAD}([2, 1]) = 0$.

For the query `? 3 1 3 4`, the jury returns $1$ because $\operatorname{MAD}([a_1, a_3, a_4]) = \operatorname{MAD}([2, 1, 1]) = 1$.

Note that the example interaction is only for understanding statements and does **not** guarantee finding a unique sequence $a$.