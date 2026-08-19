# Eyjafjalla

## 题目描述

There are n cities in the volcano country, numbered from 1 to n. The city 1 is the capital of the country, called Eyjafjalla. A large volcano is located in the capital, so the temperature there is quite high. The temperature of city i is denoted by $t_i$.

The n cities are connected by n-1 undirected roads. The i-th road connects city $u_i$ and city $v_i$. If $u_i$ is closer to the capital than $v_i$, then $t_{u_i}>t_{v_i}$. The capital has the highest temperature.

The coronavirus is now spreading across the whole world. Although the volcano country is far away from the mess, Cuber QQ, the prime minister of the country, is still designing an emergency plan in case some city getting infected. Now he wants to know if a virus whose survival temperature range is [l, r] breaks out in city x, how many cities will be infected. The assumption is that, if the temperature of one city is between l and r inclusive, and it is connected to another infected city, it is infected too.

## 输入描述

The first line contains an integer n ($1 \leq n \leq 10^5$), representing the number of cities.

In each of the next n-1 lines, there are two integers u,v ($1 \le u, v \le n$, $u \neq v$) per line, denoting that a road connecting u and v.

The next line contains n space-separated integers $t_1,t_2,\dots, t_n$ ($1\leq t_i \leq 10^9$), representing the temperature in each city.

The next line contains one integer q ($1 \le q \le 10^5$), representing the number of queries.

The next q lines contain one query each line. Each query is 3 space-separated integers x,l,r ($1 \leq x \leq n, 1 \leq l \leq r \leq 10^9$), representing a query that a virus whose survival temperature range is [l, r] breaks out in city x.

## 输出描述

For each query, output one integer representing the number of cities that will be infected. As a special case, if $t_x\notin [l,r]$, please output 0.

## 样例输入输出

### 示例1

**输入**
```
4
1 2
1 3
2 4
10 8 7 6
3
1 10 10
2 6 7
3 7 10
```

**输出**
```
1
0
3
```

**说明**
For the third query, the virus will first land in city 3, and then infect city 1, and then infect 2, so 3 cities will be infected.