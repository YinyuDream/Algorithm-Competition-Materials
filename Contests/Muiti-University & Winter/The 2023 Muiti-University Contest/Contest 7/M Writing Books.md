# Writing Books

## 题目描述

Bandycar is writing page numbers for $T$ books. The page numbers of all books start from $1$. The $i$-th book has $n_i$ pages. Bandycar wants to know, for each book, how many digits does he need to write.

## 输入描述

The first line contains an integer $T$.

The $i$-th line in the following $T$ lines contains an integer $n_i$.

## 输出描述

Output $T$ lines, the $i$-th line contains the answer to the $i$-th book.

## 示例

### 示例1

#### 输入

```text
2
15
1000
```

#### 输出

```text
21
2893
```

#### 说明

For the first book, page $1$ to $9$ each has one digit; page $10$ to $15$ each has two digits. So the answer is $1\times9+2\times6=21$.

## 备注

$1\le T\le 10^5,\;1\le n_i\le 10^9$