# Grayscale Confusion

## 题目描述

Sometimes, you may want to print a color image in grayscale mode, either because you want to save ink or your printer can only do so. However, when you do that, you may encounter a problem: some colors that are distinct in the color image may become indistinguishable in the grayscale image. This is the information loss caused by the grayscale conversion.

![示意图](https://uploadfiles.nowcoder.com/images/20230818/0_1692293809278/2C8C3901200EC6A785640C924ACD5A1D)

Of course, a good conversion from RGB (Red, Green, Blue) to Grayscale is not unique. Here, we define a property that a good conversion must satisfy: if a color $(r, g, b)$ is strictly less than $(r', g', b')$: $r < r', g < g', b < b'$, then the conversion $f$ must hold that $f(r, g, b) < f(r', g', b')$. It means that the strict partial order on color space should be preserved.

Xiao Fan is given an RGB image and you want to convert it to a grayscale image. However, Xiao Fan also want to confuse Xiao Shi by intentionally mapping two specified colors to the same grayscale value, while keeping the order of the colors. Can you help Xiao Fan to find a good conversion that confuses two given colors from $n$ given colors?

## 输入描述

The first line of input contains an integer $n~(2 \leq n \leq 1\,000)$, representing the number of distinct colors in the RGB image.

The next $n$ lines of input each contain three integers $r_i, g_i, b_i~ (0 \leq r_i, g_i, b_i \leq 255)$, representing the red, green and blue components of a color $c_i$.

The two colors that should be confused is the first two colors, $c_1$ and $c_2$.

## 输出描述

If it's impossible to do so, print `\texttt{-1}` in one line.

Otherwise, output $n$ lines, each containing an **integer** $w_i (0 \leq w_i \leq 255)$, representing the grayscale value of the corresponding color $f(r_i, g_i, b_i) = w_i$ in your solution. If there are multiple solutions, print any of them.

## 示例1

### 输入

```3
0 0 0
2 2 2
1 1 1
```

### 输出

```-1
```

## 示例2

### 输入

```3
1 0 0
0 1 0
0 0 1
```

### 输出

```0
0
1
```

## 示例3

### 输入

```3
0 0 0
0 1 2
255 255 255
```

### 输出

```0
0
1
```

## 备注

For sample 1, it's impossible to satisify both (1) The color 1 and color 2 has the same gray value, and; (2) the strict partial order condition since $(0, 0, 0)$ is strictly less than $(2, 2, 2)$ in all three dimensions.

For sample 2, there are $256 ^ 2$ solutions where each gray value can be any integer between 0 and 255, since there is no order restriction should take into effect.

For sample 3, we have partial order color 1 < color 3 and color 2 < color 3, so the gray value should also preserve the order.