# Generator

## 题目描述

Mr.L has a uniform random generator.  
In the beginning, Mr. L will input an integer $N$, and then pushes the **generate** button. The generator will output a random integer $x\in [1,N]$. Then he will push the button again, and the generator will output a random integer $y\in [1,x]$ and so on and so forth.  
It is clear that the output is non-increasing, and after a number of pushes, the output will at last be $1$. Now he wants to know the expected number of pushes to obtain $1$ as output.

## 输入描述

A positive integer $N$ $(1\leq{N}\leq10^9)$.

## 输出描述

A real number --- the expected number of pushes.  
Your answer will be accepted if the relative or absolute error does not exceed $10^{-6}$.

## 示例

### 示例1

**输入**
```
1
```

**输出**
```
1.0000000000
```

### 示例2

**输入**
```
3
```

**输出**
```
2.5000000000
```