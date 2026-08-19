# D. Vasya And The Matrix

## Problem Description

Now Vasya is taking an exam in mathematics. In order to get a good mark, Vasya needs to guess the matrix that the teacher has constructed!

Vasya knows that the matrix consists of $n$ rows and $m$ columns. For each row, he knows the xor (bitwise excluding or) of the elements in this row. The sequence $a_1, a_2, ..., a_n$ denotes the xor of elements in rows with indices $1, 2, ..., n$, respectively. Similarly, for each column, he knows the xor of the elements in this column. The sequence $b_1, b_2, ..., b_m$ denotes the xor of elements in columns with indices $1, 2, ..., m$, respectively.

Help Vasya! Find a matrix satisfying the given constraints or tell him that there is no suitable matrix.

## Input

The first line contains two numbers $n$ and $m$ $(2 \le n, m \le 100)$ — the dimensions of the matrix.

The second line contains $n$ numbers $a_1, a_2, ..., a_n$ $(0 \le a_i \le 10^9)$, where $a_i$ is the xor of all elements in row $i$.

The third line contains $m$ numbers $b_1, b_2, ..., b_m$ $(0 \le b_i \le 10^9)$, where $b_i$ is the xor of all elements in column $i$.

## Output

If there is no matrix satisfying the given constraints in the first line, output "NO".

Otherwise, on the first line output "YES", and then $n$ rows of $m$ numbers in each $c_{i1}, c_{i2}, ... , c_{im}$ $(0 \le c_{ij} \le 2 \cdot 10^9)$ — the description of the matrix.

If there are several suitable matrices, it is allowed to print any of them.

## Samples

### Sample 1

**Input**
```
2 3
2 9
5 3 13
```

**Output**
```
YES
3 4 5
6 7 8
```

### Sample 2

**Input**
```
3 3
1 7 6
2 15 12
```

**Output**
```
NO
```