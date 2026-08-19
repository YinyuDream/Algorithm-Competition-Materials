# Ball Dropping

## 题目描述

A standard sphere ball is falling in the air, and the center of the sphere is exactly on the centerline of an empty isosceles trapezoidal. The trapezoid is hanging horizontally under the sphere.

![图片](https://uploadfiles.nowcoder.com/images/20210714/364712_1626255830704/D45F07914599F01E1B34C63EC3702F0F)

Please determine whether the ball will get stuck in the trapezoid or drop past the trapezoid.

## 输入描述

The input contains four integers $r, a, b, h(1 \le r,a,b,h \le 1000, a > b)$, indicating the radius of the ball, the top base, the bottom base, and the height of the isosceles trapezoid.

It is guaranteed that $2r \ne b, 2r < a, 2r < h$.

## 输出描述

Output 'Drop' if the sphere ball will drop past the empty trapezoid, otherwise output 'Stuck'.

If the answer is 'Stuck', please also calculate the stuck position(the height between the center of the sphere and the midpoint of the bottom base). Your answer is considered correct if its absolute or relative error does not exceed $10^{-6}$.

## 示例1

### 输入

```
2 8 2 5
```

### 输出

```
Stuck
2.2206345966
```

## 示例2

### 输入

```
1 8 3 5
```

### 输出

```
Drop
```