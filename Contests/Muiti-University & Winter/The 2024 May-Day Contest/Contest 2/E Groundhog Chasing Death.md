# Groundhog Chasing Death

## 题目描述

As we all know,"Groundhog chasing death" means "GCD",while "GCD" stands for "greatest common divisor".

So you need to calculate $\displaystyle\prod_{i=a}^{b}\prod_{j=c}^{d}\gcd(x^i,y^j)$ modulo ${998244353}$.

## 输入描述

One line which contains six intergers ${a,b,c,d,x,y}$.

## 输出描述

One line which contains $\displaystyle \prod_{i=a}^{b}\prod_{j=c}^{d}\gcd(x^i,y^j)$ modulo ${998244353}$.

## 示例1

### 输入

```
1 2 1 2 8 4
```

### 输出

```
2048
```

## 示例2

### 输入

```
1 2 3 4 120 180
```

### 输出

```
235140177
```

## 备注

$0\leqslant{a,b,c,d\leqslant 3\times10^6,0<x,y\leqslant10^9},a\leqslant b,c\leqslant d$.