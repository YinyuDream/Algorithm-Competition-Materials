# Red Walking on Grid

**Red** is on a $2\cdot n$ grid, with some cells being red and others being white.

**Red** can initially choose a red cell, and at each step, can choose a red cell above, below, to the left, or to the right. When **Red** leaves a cell, the cell immediately turns white.

**Red** wants to know the maximum number of steps she can take.

If there are no initial red cells, please output $0$.

## 输入描述:

The first line contains a positive integer $n(1\leq n \leq 10^6)$.

The next two lines contain a $2\cdot n$ character matrix, consisting only of `R` and `W` characters. `R` represents a red cell, and `W` represents a white cell.

## 输出描述:

An integer — the maximum number of steps **Red** can take.

## 示例1

### 输入

```
4
RWRR
RRRR
```

### 输出

```
6
```

## 示例2

### 输入

```
4
WWWW
WWWW
```

### 输出

```
0
```