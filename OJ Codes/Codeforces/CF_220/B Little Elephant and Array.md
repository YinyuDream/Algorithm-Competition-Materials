# Little Elephant and Array

## Description

The Little Elephant loves playing with arrays. He has array $a$, consisting of $n$ positive integers, indexed from 1 to $n$. Let's denote the number with index $i$ as $a_i$.

Additionally the Little Elephant has $m$ queries to the array, each query is characterised by a pair of integers $l_j$ and $r_j$ $(1 \le l_j \le r_j \le n)$. For each query $l_j, r_j$ the Little Elephant has to count, how many numbers $x$ exist, such that number $x$ occurs exactly $x$ times among numbers $a_{l_j}, a_{l_j+1}, \dots, a_{r_j}$.

Help the Little Elephant to count the answers to all queries.

## Input

The first line contains two space-separated integers $n$ and $m$ $(1 \le n, m \le 10^5)$ — the size of array $a$ and the number of queries to it. The next line contains $n$ space-separated positive integers $a_1, a_2, \dots, a_n$ $(1 \le a_i \le 10^9)$. Next $m$ lines contain descriptions of queries, one per line. The $j$-th of these lines contains the description of the $j$-th query as two space-separated integers $l_j$ and $r_j$ $(1 \le l_j \le r_j \le n)$.

## Output

In $m$ lines print $m$ integers — the answers to the queries. The $j$-th line should contain the answer to the $j$-th query.

## Sample

```input
7 2
3 1 2 2 3 3 7
1 7
3 4
```

```output
3
1
```