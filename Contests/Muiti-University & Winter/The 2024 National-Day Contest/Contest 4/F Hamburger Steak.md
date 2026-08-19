# Hamburger Steak

Riko is ready to cook hamburger steaks. There are $m$ pans and $n$ hamburger steaks that need to be fried. The $i$-th hamburger steak needs to be fried for $t_i$ (which is a **positive integer**) minutes. Riko can fry it in a certain pan for $t_i$ minutes, or in two different pans for $a_i$ and $b_i$ minutes respectively, where $a_i$ and $b_i$ are both **positive integers** and $a_i + b_i = t_i$. Riko will start cooking at time $0$ and she wants to finish cooking as soon as possible. Please help Riko make a plan to minimize the time spent cooking all the hamburger steaks.

In this problem, we assume that a pan can fry at most one hamburger steak at the same time, and a hamburger steak can be put in at most one pan at the same time. Different pans can fry different hamburger steaks at the same time. We also assume that it takes no time to put a hamburger steak in a pan or take it out.

## 输入描述:

The first line of the input contains two integers $n$ and $m \ (1 \leq n, m \leq 10^5)$.

The second line contains $n$ integers $t_1, t_2, \ldots, t_n \ (1 \leq t_i \leq 10^9)$.

## 输出描述:

Output $n$ lines. The $i$-th line describes the cooking plan for the $i$-th hamburger steak.

Each line begins with an integer $k \ (k \in \{ 1, 2 \})$, representing that Riko will fry the hamburger steak in $k$ pans. Then there follow $k$ integer triples $id, l, r \ (1 \leq id \leq m, \ 0 \leq l < r \leq 10^{18})$ **in chronological order**, representing that Riko will fry the hamburger steak in the pan numbered $id$ during time $[l, r)$.

If there are multiple answers, output any.

## 样例输入

```plain
5 3
1 2 3 4 5
```

## 样例输出

```plain
1 1 0 1
1 2 0 2
1 2 2 5
1 1 1 5
1 3 0 5
```

## 说明

Other valid outputs, such as the one below, are also acceptable for the example input:
```
1 1 0 1
1 1 1 3
2 2 0 1 1 3 5
1 2 1 5
1 3 0 5
```