# Roulette

## 题目描述

Walk Alone is playing roulette, a kind of gambling. For simplification, we assume its rules and steps as follows:

- The whole gambling process composes of many turns.
- In the $i$-th turn:
  - Walk Alone can choose an integer $x_i$ and pay $x_i$ yuan as the wager.
  - If Walk Alone wins, he will get $2x_i$ yuan from the maker, which means he gains $x_i$ yuan in this turn. Otherwise, the maker will devour the $x_i$ yuan he has paid, which means he loses $x_i$ yuan in this turn. The probability that Walk Alone wins is $0.5$.

Walk Alone has $n$ yuan initially, and he wants to earn an extra $m$ yuan. He will use the following strategy to gamble:

- In the first turn, Walk Alone pays $1$ yuan as the wager, i.e., $x_1=1$.
- If Walk Alone wins in the $(i-1)$-th turn, then $x_i=1$. Otherwise, $x_i=2x_{i-1}$.
- At the beginning of each turn, if Walk Alone has at least $(n+m)$ yuan, then he gets satisfied and quits the game. Otherwise, he must pay $x_i$ yuan as the wager, and he will have to stop gambling if he has less than $x_i$ yuan.

Walk Alone's good friend, Kelin wants to exhort him not to gamble. Tell him the probability that he successfully earns an extra $m$ yuan.

## 输入描述

The only line of the input contains two integers $n\ (1  \leq n  \leq 10^9)$ and $m\ (1 \le m \le 10^9)$, indicating the initial amount of money and the amount of money Walk Alone wants to earn.

## 输出描述

Output the probability that Walk Alone successfully earns an extra $m$ yuan modulo $998\,244\,353$. It can be shown that the answer can always be expressed as an irreducible fraction $x/y$, where $x$ and $y$ are integers and $y \not\equiv 0 \pmod{998\,244\,353}$. Output such an integer $a$ that $0 \leq a < 998\,244\,353$ and $a\cdot y \equiv x \pmod{998\,244\,353}$.

## 样例输入输出

### 示例1

输入：

```
2 2
```

输出：

```
623902721
```

### 示例2

输入：

```
5 30
```

输出：

```
79070907
```

## 备注

In the first example, Walk Alone has $2$ yuan initially.
In the first turn, he pays $1$ yuan as the wager, and he has $1$ yuan left. He must win the turn, or in the next turn he will have to pay $2$ yuan, and he does not have enough money. The probability that he wins is $0.5$.
In the second turn, he pays $1$ yuan and has $2$ yuan left. If he wins the turn, he will have $4$ yuan, which reaches his goal. Otherwise, he will have to pay $2$ yuan in the third turn, and he must win the turn to reach his goal. Hence the total probability is $0.5\cdot(0.5+0.5\cdot 0.5)=3/8$.