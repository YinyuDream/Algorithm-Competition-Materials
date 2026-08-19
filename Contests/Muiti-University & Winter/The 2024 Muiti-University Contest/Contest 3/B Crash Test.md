# Crash Test

## 题目描述

After five years, the most high-profile event in motor racing, Formula 1, returns to China. The Chinese Grand Prix was recently held at the Shanghai International Circuit. Formula 1 cars can reach speeds of up to 350 km/h. To ensure the safety of the drivers, the cars must pass rigorous crash tests.

We consider the following simplified version of a crash test. Initially, a car is positioned with its front facing a wall, at a distance of $D$ meters from the wall. This crash test provides $n$ types of boosters, where the $i$-th type of booster has a thrust performance of $h_i$, and there are ample quantities of each type of booster. Suppose the current distance between the car's front and the wall is $d$, and we use a booster with a thrust performance of $h$. When $d \ge h$, the car will move forward $h$ meters and then stop. Otherwise, the car will move forward $d$ meters, crash into the wall, and rebound $h-d$ meters, after which it stops, still facing the wall.

Now, you want to know, through any number of operations (including no operation), what the minimum distance between the car's front and the wall can be?

## 输入描述

The first line of input contains two positive integers $n$ and $D$ ($1 \le n \le 100, 1 \le D \le 10^{18}$), denoting the number of boosters and the distance between the Formula 1 car and the wall, respectively.

The second line of input contains $n$ positive integers $h_1, h_2, \ldots, h_n$ ($1 \le h_i \le 10^{18}$), denoting the thrust performance of each booster.

## 输出描述

Output an integer in a line, denoting the minimum possible distance between the car's front and the wall.

## 样例输入输出

### 样例1

**输入**
```
1 10
3
```

**输出**
```
1
```

**说明**
An optimal strategy is $10 \overset{i = 1}{\rightarrow} 7 \overset{i = 1}{\rightarrow} 4 \overset{i = 1}{\rightarrow} 1$.

### 样例2

**输入**
```
2 10
3 4
```

**输出**
```
0
```

**说明**
An optimal strategy is $10 \overset{i = 1}{\rightarrow} 7 \overset{i = 2}{\rightarrow} 3 \overset{i = 1}{\rightarrow} 0$.

### 样例3

**输入**
```
2 1
3 7
```

**输出**
```
0
```

**说明**
An optimal strategy is $1 \overset{i = 2}{\rightarrow} 6 \overset{i = 1}{\rightarrow} 3 \overset{i = 1}{\rightarrow} 0$.

### 样例4

**输入**
```
10 4306315981482911
4306 3519 8148 2911 9970 7222 5462 1844 7072 1702
```

**输出**
```
0
```

### 样例5

**输入**
```
10 123456789987654321
10 10 10 10 10 10 10 10 10 10
```

**输出**
```
1
```