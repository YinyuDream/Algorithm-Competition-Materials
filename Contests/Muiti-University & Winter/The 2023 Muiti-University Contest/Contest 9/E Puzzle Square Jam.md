# Puzzle: Square Jam

## 题目描述

Grammy is a puzzle master. Today, she is playing a variant of "Square Jam" puzzle. Given an $n \times m$ rectangle. The goal is to divide the rectangle into several squares (with integral lengths) such that no point is touched by 4 squares.

![Puzzle example 1](https://uploadfiles.nowcoder.com/images/20230814/0_1691978733329/4A47A0DB6E60853DEDFCFDF08A5CA249)

![Puzzle example 2](https://uploadfiles.nowcoder.com/images/20230814/0_1691978738529/FB5C81ED3A220004B71069645F112867)

The left picture illustrates a solution to a $4\times 6$ puzzle, and the right picture shows an example of what is not allowed in the solution.

Grammy surely knows how to solve the puzzle, but she decided to give you a quiz. Please solve the puzzle.

## 输入描述

There are multiple test cases.

The first line contains the number of test cases $T$ ($1 \leq T \leq 2\times 10^5$).

Each of the following $T$ lines contains two positive integers $n,m$ ($1 \leq n,m \leq 10^5$), denoting the side lengths of the rectangle.

It is guaranteed that the sum of $nm$ is less than or equal to $2\times 10^5$.

## 输出描述

For each test case:

If the solution does not exist, output `NO` on a single line.

Otherwise, output `YES` on the first line, then output an integer $k$ on the second line, denoting the number of squares divided. Finally, output $k$ lines, each of which contains $3$ integers $x,y,l$, denoting a square of size $l$ having $(x,y)$ as its upper-left corner.

For the details of the coordinates, please refer to the following picture.

![Coordinate system](https://uploadfiles.nowcoder.com/images/20230814/0_1691978794339/10FB15C77258A991B0028080A64FB42D)

If there are multiple solutions, output any.

## 样例输入

```
2
4 6
1 1
```

## 样例输出

```
YES
10
0 0 2
0 2 1
1 2 1
0 3 3
2 0 1
3 0 1
2 1 2
3 3 1
3 4 1
3 5 1
YES
1
0 0 1
```