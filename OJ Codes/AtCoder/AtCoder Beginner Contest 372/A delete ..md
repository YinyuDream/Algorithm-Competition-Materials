# A - delete .

### Problem Statement

You are given a string $S$ consisting of lowercase English letters and `.`.
Find the string obtained by removing all `.` from $S$.

### Constraints

* $S$ is a string of length between $1$ and $100$, inclusive, consisting of lowercase English letters and `.`.

---

### Input

The input is given from Standard Input in the following format:

$S$

### Output

Print the string obtained by removing all `.` from $S$.

---

### Sample Input 1

```
.v.
```

### Sample Output 1

```
v
```

Removing all `.` from `.v.` yields `v`, so print `v`.

---

### Sample Input 2

```
chokudai
```

### Sample Output 2

```
chokudai
```

There are cases where $S$ does not contain `.`.

---

### Sample Input 3

```
...
```

### Sample Output 3

```

```

There are also cases where all characters in $S$ are `.`.
