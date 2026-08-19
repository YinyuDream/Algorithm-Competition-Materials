# T291046 Knuth-Morris-Pratt Algorithm 与弱周期引理

## 题目描述

最近，Nanarikom 学习了一些字符串理论。对于字符串 $s$，我们用 $|s|$ 表示 $s$ 的长度，用 $s_{l..r}$ 表示从 $s$ 第 $l$ 个字符到第 $r$ 个字符形成的子串。例如，对于字符串 $s = \texttt{abcdefg}$，我们有 $|s| = 7$，$s_{1..3} = \texttt{abc}$，$s_{2..5} = \texttt{bcde}$。特别地，如果 $l > r$，则 $s_{l..r}$ 是长度为 $0$ 的空字符串 $\varnothing$。

如果 $0 \leq i < |s|$ 且 $s_{1..i} = s_{|s| - i + 1..|s|}$，则我们称 $s_{1..i}$ 是 $s$ 的一个 Border。$s$ 可能有不止一个 Border，所以 Nanarikom 用函数 $\operatorname{MaxBorder}(s)$ 表示 $s$ 最长的 Border。例如，$\operatorname{MaxBorder}(\texttt{ababa}) = \texttt{aba}$，因为在 $\texttt{aba}, \texttt{a}, \varnothing$ 三者中，第一个 Border 长度较长。

Border 有很多优雅的性质。为了研究这些性质，Nanarikom 定义函数 $f(s)$ 如下：
$$
f(s) = 
\left \{
\begin{matrix}
	0									& (s = \varnothing)		\\
	f(\operatorname{MaxBorder(s)}) + 1	& (s \neq \varnothing)	\\
\end{matrix}
\right.
$$
此外，Nanarikom 定义字符串 $s$ 的优雅程度 $g(s)$ 如下：
$$
g(s) = \max_{l=1}^{|s|} \max_{r=l}^{|s|} f(s_{l..r})
$$
现在，Nanarikom 给你一个仅由英文小写字母组成的字符串 $s$，你可以任意重排 $s$ 中字符的顺序，但不能添加或删除字符。记你重排后得到的字符串为 $s'$，Nanarikom 希望你求出 $g(s')$ 的最大值。

## 输入格式

输入共一行，包含一个仅由英文小写字母组成的字符串 $s$ ($1 \leq |s| \leq 100$)。

## 输出格式

输出一个整数，代表 $g(s')$ 的最大可能值。

## 输入输出样例 #1

### 输入 #1

```
nanarikom
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
kanzakiskoxia
```

### 输出 #2

```
3
```

## 说明/提示

将 $\texttt{nanarikom}$ 重排为 $\texttt{mokiranan}$ 后，我们有 $f(\texttt{anan}) = f(\texttt{an}) + 1 = (f(\varnothing) + 1) + 1 = (0 + 1) + 1 = 2$，且 $\texttt{mokiranan}$ 的其他子串的 $f$ 函数值均不超过 $2$，故有 $g(\texttt{mokiranan}) = 2$。

可以发现，其他重排方式得到的 $g$ 函数值不会超过 $2$。