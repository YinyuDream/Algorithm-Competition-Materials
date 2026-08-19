# We are the Lights

## 题目描述

One day, Bobo was attending an international light exhibition and noticed a grid of $n\times m$ lights arranged in $n$ rows and $m$ columns. Initially, all lights were off.

Bobo noticed that there were two buttons for each row and column, one for turning on and one for turning off. This means that he can perform the following four operations:

1. row $i$ on: turns on all the lights in row $i$.
2. row $i$ off: turns off all the lights in row $i$.
3. column $i$ on: turns on all the lights in column $i$.
4. column $i$ off: turns off all the lights in column $i$.

Mischievous Bobo, of course, will not miss this opportunity. You are given $q$ operations performed by Bobo. You need to determine the number of lights that are on after performing $q$ operations in sequence.

## 输入描述

The first line contains three positive integers $n$, $m$, and $q$ $(1\leq n,m\leq 10^6, 1\leq q\leq 10^6)$, denoting the number of rows and columns of the lights, and the number of operations that Bobo performs.

The next $q$ lines contain an operation each, with the form of each operation already given in the problem description.

## 输出描述

Output an integer in one line, denoting the number of lights that are turned on after performing $q$ operations in order.

## 示例输入输出

### 示例1

**输入**
```
2 2 3
row 1 on
column 2 off
row 2 on
```

**输出**
```
3
```

### 示例2

**输入**
```
3 4 4
row 1 on
column 4 on
row 3 on
column 2 off
```

**输出**
```
7
```

## 备注

To help with understanding, we provide graphical illustrations for the second sample test case. There are three rows of lights, each with four lights. Initially, all lights are off, as shown in the figure below.

![图1](https://uploadfiles.nowcoder.com/images/20230725/0_1690287920612/64BEFA18637BF0CB5338CECD2E1B0D5C)

After the first operation, the state of the lights is shown in the figure below.

![图2](https://uploadfiles.nowcoder.com/images/20230725/0_1690288039285/B1DD01812B22D34C373E011261AB5FB9)

After the second operation, the state of the lights is shown in the figure below.

![图3](https://uploadfiles.nowcoder.com/images/20230725/0_1690288059833/0FF0A3D73E6D6AA1D6DEDDAA9FDDE263)

After the third operation, the state of the lights is shown in the figure below.

![图4](https://uploadfiles.nowcoder.com/images/20230728/0_1690517821128/2D5AE404CA714EC7B16C97E3CC1B2DE3)

After the fourth operation, the state of the lights is shown in the figure below. At this point, there are still 7 lights on.

![图5](https://uploadfiles.nowcoder.com/images/20230725/0_1690288089101/AD194CBE90A56F2011FAB3605EF5AF18)