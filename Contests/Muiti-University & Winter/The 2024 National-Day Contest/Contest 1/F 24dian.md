## 题目描述

24dian is a famous game. You are given a set of n cards, each card contains an integer between 1 to 13. You can put the cards in arbitrary order, add + or - or * or / between any two cards, and add as many parentheses as you want. Your goal is to make the expression valid and its value equals m.  
However, there're cases when valid solutions exist, but all the valid solutions involve fractions, that is, non-integers, in the process of calculation. For example, if you want to use (1, 5, 5, 5) to get 24, the only solution is 5*(1-(1/5)), where 1/5 is a fraction.  
Given the number of cards n and the result m you want to get, find all the possible set of cards that has a valid solution but any solution involves fraction in the calculation.  

## 输入描述

The first line contains two integers $n,m(1\leq n\leq 4,1\leq m\leq 10^9)$ , representing the number of cards and the result you want to get.  

## 输出描述

First line contains an integer k, denoting the number of possible sets.  
In next k lines, each line contains n non-decreasing numbers, represent a possible set. You should print the sets in lexicographical order.

## 示例1

**输入**

```
4 24
```

**输出**

```
16
1 3 4 6 
1 4 5 6 
1 5 5 5 
1 6 6 8 
1 8 12 12 
2 2 11 11 
2 2 13 13 
2 3 5 12 
2 4 10 10 
2 5 5 10 
2 7 7 10 
3 3 7 7 
3 3 8 8 
4 4 7 7 
5 5 7 11 
5 7 7 11
```

## 示例2

**输入**

```
1 114514
```

**输出**

```
0
```

## 备注

(空)