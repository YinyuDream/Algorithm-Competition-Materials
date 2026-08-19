# All-in at the Pre-flop

## 题目描述

In the backroom of the ``All-in at the Pre-flop'' casino, a crowd gathers nightly to witness a high-stakes duel that strips Texas Hold'em down to its rawest form of luck. Two players, known only by their monikers ``Antileaf'' and ``Despradotwo'', have become the main attraction. This evening, they bring their chips and a fierce desire to outlast the other, betting everything they have at the pre-flop stage in a daring display of brinkmanship. The crowd watches, mesmerized by the simplicity and intensity of the game where strategy is absent, and fortune rules. The entire pot goes to the winner, and the loser must leave with nothing.

In a simplified version of Texas Hold'em poker, two players face off in a duel where strategy is replaced by sheer luck. Each player starts with a fixed number of chips: the first player has $a$ chips and the second player has $b$ chips. In each game round, two players go all-in before even seeing the hole cards. After that, all community cards are dealt only once. Since nothing will change when the round is a tie, we assume that no tie happens, and the first player wins with probability $1/2$ independently as it's a fair game. The round concludes as follows:

* If the winner in the round has at least the chips the loser has, the game ends and the winner takes all the chips.
* Otherwise, the loser pays the same amount of chips as the winner has, and another round starts afterwards.

You want to know the probabilities of each player winning the game (taking all the chips) under these conditions.

## 输入描述

The input consists of two integers, $a, b ~(1 \leq a, b < 998\,244\,353, a + b < 998\,244\,353)$, indicating the number of chips with which the first and second players start, respectively.

## 输出描述

Print two integers in a line separated by a space:

* The probability modulo $998\,244\,353$, expressed as an integer, that the first player wins.
* The probability modulo $998\,244\,353$, expressed as an integer, that the second player wins.

The expected value in question will be a rational number. If we express it as a fractional number $\frac{x}{y}$ where $x$ and $y$ are coprime positive integers, $x$ will be coprime with $P = 998244353$. Therefore, print the only integer $z$ between $0$ and $P-1$ (inclusive) such that $xz \equiv y \pmod{P}$.

## 样例输入输出

### 样例输入

```plain
1 3
```

### 样例输出

```plain
748683265 249561089
```

### 说明

In this scenario, all possibilities conclude within two rounds. In the first round, if the first player loses, the game ends immediately. Otherwise, the next round starts with $a = 2, b = 2$, and the player who wins the second round takes all the chips. Therefore, it is only possible for the first player to win the entire game by winning both rounds, and the probabilities are $1/4$ and $3/4$.