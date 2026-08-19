# B - 1122 String

### Problem Statement

A string $T$ is called a **1122 string** if and only if it satisfies all of the following three conditions:

* $\lvert T \rvert$ is even. Here, $\lvert T \rvert$ denotes the length of $T$.
* For each integer $i$ satisfying $1\leq i\leq \frac{|T|}{2}$, the $(2i-1)$-th and $2i$-th characters of $T$ are equal.
* Each character appears in $T$ exactly zero or two times. That is, every character contained in $T$ appears exactly twice in $T$.

Given a string $S$ consisting of lowercase English letters, print `Yes` if $S$ is a 1122 string, and `No` otherwise.

### Constraints

* $S$ is a string of length between $1$ and $100$, inclusive, consisting of lowercase English letters.

---

### Input

The input is given from Standard Input in the following format:

$S$

### Output

If $S$ is a 1122 string, print `Yes`; otherwise, print `No`.

---

### Sample Input 1

```
aabbcc
```

### Sample Output 1

```
Yes
```

$S=$`aabbcc` satisfies all the conditions for a 1122 string, so print `Yes`.

---

### Sample Input 2

```
aab
```

### Sample Output 2

```
No
```

$S=$`aab` has an odd length and does not satisfy the first condition, so print `No`.

---

### Sample Input 3

```
zzzzzz
```

### Sample Output 3

```
No
```

$S=$`zzzzzz` contains six `z`s and does not satisfy the third condition, so print `No`.

---
