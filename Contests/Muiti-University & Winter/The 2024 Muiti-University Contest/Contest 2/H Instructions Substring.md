# Instructions Substring

## 题目描述

**Red** stands at the coordinate $(0,0)$ of the Cartesian coordinate system. She has a string of instructions: up, down, left, right (where `right' increases the x-coordinate by $1$, and `up' increases the y-coordinate by $1$).

Now **Red** wants to select a continuous substring of instructions and execute them. **Red** hopes that the final execution of the instructions can pass through the coordinate $(x,y)$. She wants to know how many selection options there are.

## 输入描述:

The first line contains three integers $n$, $x$, and $y$ $(1 \leq n \leq 2 \times 10^5, -10^5 \leq x, y \leq 10^5)$, — the length of the instruction string and the coordinates **Red** hopes to pass through.

The second line contains a string of length $n$, consisting of the characters $'W'$, $'S'$, $'A'$, and $'D'$. — the four directions: up, down, left, and right, respectively.

## 输出描述:

Output one integer representing the number of selection options for the continuous substring.

## 示例1

**输入**

```
6 1 1
ASAWDD
```

**输出**

```
3
```

**说明**

Choosing $"AWDD"$, $"WD"$, or $"WDD"$ are all valid.

## 示例2

**输入**

```
4 0 0
WWWS
```

**输出**

```
10
```

**说明**

Any substring can pass through $(0,0)$, as it is the starting point.