# Merge the squares!

## 题目描述

Just like all math‑loving students, Bobo loves squares, especially big ones, and he loves to combine many small squares into a big one.  
“Exactly. That's why I drew squares on my algebra exam,” Bobo explained to his algebra professor.

![Algebraic representation of squares](https://uploadfiles.nowcoder.com/images/20230725/0_1690287020636/87A184AC99D5515188276A4471DB8E49)

Because of this, Bobo is also interested in *perfect squared squares*, which are squares that can be dissected into smaller squares of different sizes. The smallest order for a perfect squared square is 21, discovered by A. J. W. Duijvestijn.

![Perfect squared square of order 21](https://uploadfiles.nowcoder.com/images/20230725/0_1690287041036/337D7775FF249E0C34E0A221A0FB831E)

However, it's too difficult for Bobo to assemble squares of different sizes into a big square, so he wants to start with something simpler: assembling an $n\times n$ board of unit squares (side length $1$) into a single large square of side length $n$.  
Of course he cannot do it in one operation, otherwise it would be boring. He now requires that **the number of squares merged in each operation must be between 2 and 50 (inclusive)**, and the resulting shape must still be a square.

Bobo doesn't know how to proceed, so he has given this problem to you.  
*It is guaranteed that, under the constraints of the problem, a valid sequence of operations always exists.*

## 输入描述

The only line contains an integer $n$ $(1\le n\le 1000)$, denoting the number of rows and columns of the small squares.

## 输出描述

Output a number $m$ $(0\le m\le 10^6)$ in the first line, representing the number of operations.  
In the next $m$ lines, output three numbers $x$, $y$ and $k$ per line, describing one operation:

* $1\le x\le n$, $1\le y\le n$ are the row and column of the upper‑left corner of the merged large square (the board uses $1$–$n$ indexing);
* $1\le k\le n$ is the side length of the merged large square.

You must ensure that every operation satisfies

1. $x+k-1\le n,\; y+k-1\le n$ (the square stays inside the board);
2. The $k\times k$ region whose upper‑left corner is $(x,y)$ consists only of **complete squares** (i.e. squares that were already formed by previous operations) and the number of such squares is between $2$ and $50$.

After all operations, the whole $n\times n$ board of unit squares must be merged into one large square of side $n$.  
Any valid sequence of operations may be output.

## 示例

### 示例 1

#### 输入
```
1
```

#### 输出
```
0
```

### 示例 2

#### 输入
```
2
```

#### 输出
```
1
1 1 2
```

### 示例 3

#### 输入
```
8
```

#### 输出
```
5
1 1 4
1 5 4
5 1 4
5 5 4
1 1 8
```

## 备注

The following pictures illustrate the merging process for the third sample (purple area is merged in each step).

![Step 1](https://uploadfiles.nowcoder.com/images/20230725/0_1690287093706/6A6AB14A41FB3C3DC50AC20E89012F1F)  
![Step 2](https://uploadfiles.nowcoder.com/images/20230725/0_1690287105049/1EAD0EAAAA3225D84293A3C388F1F017)  
![Step 3](https://uploadfiles.nowcoder.com/images/20230725/0_1690287118904/0E00DFA923C39828D8BAB7E9F75B95D3)  
![Step 4](https://uploadfiles.nowcoder.com/images/20230725/0_1690287128923/DCDDCAABE0F11E2526AAC2C3ED9C4334)  
![Step 5](https://uploadfiles.nowcoder.com/images/20230725/0_1690287138810/871E84B94D9D3654A59D625DCE390F1E)