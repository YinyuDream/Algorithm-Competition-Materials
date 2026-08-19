# Fight Against the Monster

## 题目描述

On a mysterious planet, YangQiShaoNian and Keith must fight a terrifying monster.

Now, several war machines need to be built to combat the monster. The monster starts with a health of $h$, and it will die when its health falls to $0$ or below.

Each machine has two functions —"Fight" and "Create"— described as follows:

**Fight:** For a given machine, using the "Fight" function will reduce the monster's health by $1$, but the machine will be permanently damaged and lose all functionality;

**Create:** To use the "Create" function, first, $m$ machines must be chosen, and this function must be used on them simultaneously, which will then produce $k$ new machines. Note that each machine can only use the "Create" function once, but can still use the "Fight" function afterwards.

Please calculate the minimum number of initial war machines required to defeat the monster.

## 输入描述:

The first line contains an integer $T(1\leq T\leq 2\cdot 10^5)$, indicating the number of test cases. For each test case:

Only one line is input, containing three integers $m,k,h(1 \leq k \leq m \leq 10^6, 0 \leq h \leq 10^9)$, representing the number of machines required to use the "Create" function, the number of machines produced by using the "Create" function, and the monster's initial health.

## 输出描述:

For each test case:

Output only one line containing an integer, representing the answer.

## 样例输入输出

### 示例1

**输入**

```
2
2 1 7
97 33 114514
```

**输出**

```
4
75574
```