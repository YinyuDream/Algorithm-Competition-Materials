# The Crime-solving Plan of Groundhog

## 题目描述

Today, ZLZX has a mysterious case: Orange lost his down jacket hanging in his dorm room. Under the expectations of everyone, detective Groundhog took his small spoon of the artifact and started the journey to solve the case.

After an in-depth investigation of the northernmost mysterious room on each floor, Groundhog discovered $n$ mysterious numbers. As long as the clues conveyed by these numbers are deciphered, he can reveal the truth of the matter. The deciphering method is: using these numbers to generate two positive integers without leading zeros, and minimizing the product of these two positive integers is the final clue.

Then Groundhog wants to know: What is the smallest product?

As he continued to investigate in the room west of the new building, he gave you the question.

Concise meaning: Given n numbers between 0 and 9, use them to make two **positive integers** without leading zeros to minimize the product.

## 输入描述:

The first line of input is a single integer $T$, the number of test cases.
For each set of data：
Each test case begins with a single integer $n$, the count of numbers.
The next line are $n$ numbers.

## 输出描述:

For each set of Case, an integer is output, representing the smallest product.

## 示例1

### 输入

```
1
4
1 2 2 1
```

### 输出

```
122
```

## 示例2

### 输入

```
2
5
1 3 2 1 2
3
1 1 0
```

### 输出

```
1223
10
```

## 备注:

${ 1 \leqslant T \leqslant 1000}, 2 \leqslant n \leqslant 100000, { 1 \leqslant \sum n \leqslant 1000000}$

There are at least two Numbers that are guaranteed not to be zero.
The Numbers range between ${[0,9]}$.