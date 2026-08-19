# Expected Median

Arul has a **binary** array $a^{\text{∗}}$ of length $n$.

He will take all subsequences $b^{\text{†}}$ of length $k$ ($k$ is odd) of this array and find their median. The sum of all these values?

As this sum can be very large, output it modulo $10^9 + 7$.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \leq k \leq n \leq 2 \cdot 10^5$, $k$ is odd) — the length of the array and the length of the subsequence, respectively.

The second line of each test case contains $n$ integers $a_i$ ($0 \leq a_i \leq 1$) — the elements of the array.

It is guaranteed that sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print the sum modulo $10^9 + 7$.

## Note

$^{\text{∗}}$ A binary array is an array consisting only of zeros and ones.

$^{\text{†}}$ An array $b$ is a subsequence of an array $a$ if $b$ can be obtained from $a$ by the deletion of several (possibly, zero or all) elements. Subsequences **don't** have to be contiguous.

$^{\text{‡}}$ The median of an array of odd length $k$ is the $\frac{k+1}{2}$-th element when sorted.

## Example

```input
8
4 3
1 0 0 1
5 1
1 1 1 1 1
5 5
0 1 0 1 0
6 3
1 0 1 0 1 1
4 3
1 0 1 1
5 3
1 0 1 1 0
2 1
0 0
34 17
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```

```output
2
5
0
16
4
7
0
333606206
```