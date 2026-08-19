# Cake 2

## 题目描述

Grammy bought a big cake. The shape of the cake is a regular polygon. That is, a convex polygon whose all interior angles are equal and all edges are equal.

Grammy wants to cut the cake into a pretty pattern and share the cake with her friends. She indexed the vertices $0$ through $n-1$ in counterclockwise order and chooses an integer $k$. After that, she cuts the cake through $n$ straight lines connecting vertex $i$ and vertex $(i+k)\bmod n$ for each $i$.

Grammy wants to know the number of pieces after cutting the cake. Please calculate it for her.

## 输入描述:

The only line contains $2$ integers $n,k$ ($4\leq n \leq 10^6, 2\leq k \leq n-2$), denoting the number of sides of the regular polygon and the integer chosen by Grammy.

## 输出描述:

Output a single integer in a line, denoting the number of pieces after cutting the cake.

## 样例输入输出

### 示例1

**输入**

```plain
6 2
```

**输出**

```plain
13
```

## 备注:

For the sample test case, the final cake is shown below:  

![图片](https://uploadfiles.nowcoder.com/images/20240801/0_1722457118119/4A47A0DB6E60853DEDFCFDF08A5CA249)