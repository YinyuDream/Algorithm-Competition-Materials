# B - 3^A

### Problem Statement

You are given a positive integer $M$.
Find a positive integer $N$ and a sequence of non-negative integers $A = (A_1, A_2, \ldots, A_N)$ that satisfy all of the following conditions:

* $1 \le N \le 20$
* $0 \le A_i \le 10$ $(1 \le i \le N)$
* $\displaystyle \sum_{i=1}^N 3^{A_i} = M$

It can be proved that under the constraints, there always exists at least one such pair of $N$ and $A$ satisfying the conditions.

### Constraints

* $1 \le M \le 10^5$

---

### Input

The input is given from Standard Input in the following format:

$M$

### Output

Print $N$ and $A$ satisfying the conditions in the following format:

$N$  
$A_1$ $A_2$ $\ldots$ $A_N$

If there are multiple valid pairs of $N$ and $A$, any of them is acceptable.

---

### Sample Input 1

```
6
```

### Sample Output 1

```
2
1 1
```

For example, with $N=2$ and $A=(1,1)$, we have $\displaystyle \sum_{i=1}^N 3^{A_i} = 3+3=6$, satisfying all conditions.

Another example is $N=4$ and $A=(0,0,1,0)$, which also satisfies the conditions.

---

### Sample Input 2

```
100
```

### Sample Output 2

```
4
2 0 2 4
```

---

### Sample Input 3

```
59048
```

### Sample Output 3

```
20
0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
```

Note the condition $1 \le N \le 20$.
