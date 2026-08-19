# Determine the Photo Position

## 题目描述

You have taken the graduation picture of graduates. The picture could be regarded as a **matrix A** of $n \times n$, each element in A is 0 or 1, representing a blank background or a student, respectively.

However, teachers are too busy to take photos with students and only took a group photo themselves. The photo could be regarded as a **matrix B** of $1 \times m$ where each element is 2 representing a teacher.

As a master of photoshop, your job is to put photo B into photo A with the following constraints:
* you are not allowed to split, rotate or scale the picture, but only translation.
* each element in matrix B should overlap with an element in A completely, and each teacher should overlap with a blank background, not shelter from a student.

Please calculate the possible ways that you can put photo B into photo A.

## 输入描述:

The first line contains two integers $n,m(1 \le n,m \le 2000)$ indicating the size of photos A and B.

In the next $n$ lines,each line contains ${n}$ characters of '0' or '1',representing the matrix A.

The last line contains ${m}$ characters of '2', representing matrix B.

## 输出描述:

Output one integer in a line, indicating the answer.

## 示例1

### 输入
```
5 3
00000
01110
01110
01110
00000
222
```

### 输出
```
6
```

## 示例2

### 输入
```
3 2
101
010
101
22
```

### 输出
```
0
```

## 示例3

### 输入
```
3 1
101
010
101
2
```

### 输出
```
4
```