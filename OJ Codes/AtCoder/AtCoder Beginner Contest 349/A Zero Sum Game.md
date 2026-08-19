# A - Zero Sum Game

### Problem Statement

### Constraints

* $2 \leq N \leq 100$
* $-100 \leq A_i \leq 100$
* All input values are integers.

---

### Input

The input is given from Standard Input in the following format:

$N$  
$A_1$ $A_2$ $\ldots$ $A_{N-1}$

### Output

Print the answer.

---

### Sample Input 1

```
4
1 -2 -1
```

### Sample Output 1

```
2
```

* Initially, persons $1, 2, 3, 4$ have $0, 0, 0, 0$ points, respectively.
* Persons $1$ and $2$ play, and person $1$ wins. The players now have $1, -1, 0, 0$ point(s).
* Persons $1$ and $4$ play, and person $4$ wins. The players now have $0, -1, 0, 1$ point(s).
* Persons $1$ and $2$ play, and person $1$ wins. The players now have $1, -2, 0, 1$ point(s).
* Persons $2$ and $3$ play, and person $2$ wins. The players now have $1, -1, -1, 1$ point(s).
* Persons $2$ and $4$ play, and person $4$ wins. The players now have $1, -2, -1, 2$ point(s).

---

### Sample Input 2

```
3
0 0
```

### Sample Output 2

```
0
```

---

### Sample Input 3

```
6
10 20 30 40 50
```

### Sample Output 3

```
-150
```
