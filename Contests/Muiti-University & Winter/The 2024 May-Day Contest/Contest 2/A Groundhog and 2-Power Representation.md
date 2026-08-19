# Groundhog and 2-Power Representation

## 题目描述

Groundhog took a math class. In this class, his math teacher said:

Any positive integer can be represented by the power of ${2}$. For example: $137=2^7+2^3+2^0$.

And powers are expressed in parentheses.That is ,${a(b)}$ stands for ${a^b}$.Therefore,${137}$ can be expressed as $137={2(7)+2(3)+2(0)}$.

Further more,for $7=2^2+2+2^0$（$2^1$is expressed with ${2}$），$3=2+2^0$,137 can be finally expressed as ${137=2(2(2)+2+2(0))+2(2+2(0))+2(0)}$.

Another example:$1315=2^{10}+2^8+2^5+2+1 = 2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)$.

Groundhog feels amazing and wants you to write a program to simulate the above content.You need to read in an expression that is a power of ${2}$ and calculate its value.

## 输入描述

```
Given a string, indicating the power representation.
```

## 输出描述

```
Output the original number.
```

## 示例1

输入

```
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
```

输出

```
1315
```

## 备注

The range of answers :$[10,10^{180}]$，and the length of the input data shall not exceed ${20000}$.