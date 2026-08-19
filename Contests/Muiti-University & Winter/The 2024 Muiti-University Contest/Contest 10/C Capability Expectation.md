# Capability Expectation

## 题目描述

In the world where competitive programming competitions are with no limit on the number of participants, $n$ participants have decided to form a team for the Consistent and Continuous Pigeon Competition tomorrow. As the name suggests, each of the participants might independently decide not to show up on the day of the contest, with probability $p_i$.

Now let's talk about the competition. Since it's not an algorithmic competition but a programming one, there's nothing about algorithmic ability. Instead, each participant is associated with their problem-solving and reading abilities, represented by $x_i$ and $y_i$, respectively.

The team can only solve the problems within its *capability*. The team's *capability* to solve problems is geometrically represented by an area of points of the weighted average of participants: if there are $k$ participants (renumbered to $1\dots k$) in the team, the *capability* is

$$
\text{capability} = \left\{ (\mathbf{w} \cdot \mathbf{x}, \mathbf{w} \cdot \mathbf{y}) \mid \mathbf{w} \in \mathbb{R}^k_{\geq 0}, \sum_{i=1}^k w_i = 1 \right\},
$$

where $\cdot$ is the dot product: $\mathbf{a} \cdot \mathbf{b} = \sum_{i = 1}^{k} a_i b_i$.

Given all information about the participants, please calculate the expected area of *capability* of the team formed by the participants who do show up

## 输入描述

The first line of the input contains an integer $T~(1 \leq T \leq 100)$ , the number of test cases.

For each test case, the first line contains an integer $n~(1 \leq n \leq 2000)$ , the number of potential participants. Each of the next $n$ lines for a case contains three values: a real number $p_i~(0 \leq p_i \leq 1)$ with at most three decimal places, and two integers $x_i, y_i ~ (0 \leq x_i, y_i \leq 10^9)$ .

It's guaranteed that in any test case, no two points are equal and no three points are collinear. Also, the sum of all $n$ across the cases does not exceed $2000$.

## 输出描述

Output a single decimal real number, representing the expected area of capability of the team formed by the participants who do show up.

Your answer will be accepted if it is within an absolute or relative error of $10^{-6}$.

## 样例输入

```plain
5
3
0 0 0
0 0 1
0 1 0
3
0.5 0 0
0.5 0 1
0.5 1 0
3
1 0 0
1 0 1
1 1 0
4
0.5 0 0
0.5 0 1
0.5 1 0
0.5 1 1
3
0.114 5 14
0.191 9 810
0.192 60 817
```

## 样例输出

```plain
0.5000000000
0.0625000000
0.0000000000
0.1875000000
11747.5474033280
```