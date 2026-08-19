# Tournament

## 题目描述

You are scheduling a tournament. There are n teams. There are $\frac{n(n-1)}{2}$ competitions against every pair of teams. You can schedule a competition each day. For each team, it will arrive in the day when its first competition holds, and leave after its last competition finishes.

For example, there are 3 teams and the schedule is (1,2), (1,3), (2,3). The first team will arrive in day 1, and leave in day 2. It will stay for two days. The second team will stay for three days. The third team will stay for two days.

You want to find a schedule minimizing the sum of days they stay.

## 输入描述

The first line contains one integer $T(1\le T \le 30)$ — the number of test cases.  
For each test cases, the first line contains one integer $n(2\le n\le 300)$.

## 输出描述

For each test cases, output $\frac{n(n-1)}{2}$ lines. Each line contains two integers $(u,v)\ (1\le u, v\le n)$ - the competition you schedule in this day.

## 示例1

### 输入

```
2
3
4
```

### 输出

```
1 2
1 3
2 3
1 2
1 3
1 4
2 3
2 4
3 4
```