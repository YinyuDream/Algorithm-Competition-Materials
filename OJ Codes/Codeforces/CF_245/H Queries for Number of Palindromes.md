# CF245H Queries for Number of Palindromes

## 题目描述

题目给定一个仅由小写字母组成的字符串 $s$，下标从 $1$ 开始。

有 $Q$ 次询问，每组询问给定两个数 $l$ 和 $r$，表示询问 $s_l \sim s_r$ 这段区间中包含了多少个[回文串](https://baike.baidu.com/item/%E5%9B%9E%E6%96%87%E4%B8%B2/1274921)。注意单独一个字符也算回文串。

## 输入格式

第一行一个字符串 $s$，保证 $|s| \le 5000$；  
第二行一个正整数 $Q$，保证 $1 \le Q \le 10^6$；  
接下来 $Q$ 行，每行两个正整数 $l$ 和 $r$，描述一组询问。

## 输出格式

针对 $Q$ 组询问，分别输出对应的答案。

## 输入输出样例 #1

### 输入 #1

```
caaaba
5
1 1
1 4
2 3
4 6
4 5

```

### 输出 #1

```
1
7
3
4
2

```

## 说明/提示

Consider the fourth query in the first test case. String $ s[4...\ 6] $ = «aba». Its palindrome substrings are: «a», «b», «a», «aba».