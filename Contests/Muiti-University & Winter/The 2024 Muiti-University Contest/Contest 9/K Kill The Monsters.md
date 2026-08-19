# Kill The Monsters

## 题目描述

There are $n$ monsters in the forest. The $i$-th one has a defense value of $a_i$.
You can perform the following attacks:
1. Decrease all monsters' defense values by $1$.
2. Choose a monster and let its defense value $a_i$ be $\lfloor\frac{a_i}{k}\rfloor$, where $k$ is given.
Find the minimum number of operations required to make the defense value of each monster less than or eqaul to $0$.

## 输入描述:

Line $1$: Two integers $n,k$.
Line $2$: $n$ integers, indicating sequence $a$.

## 输出描述:

Line $1$: An integer, the answer.

## 样例输入输出

### 示例1

输入：
```
5 2
1 3 5 7 9
```

输出：
```
7
```

### 示例2

输入：
```
10 3
1 3 6 9 17 26 44 16 22 83
```

输出：
```
17
```

## 备注

$1\leq n\leq 10^5$.
$1\leq a_i,k\leq 10^9$.