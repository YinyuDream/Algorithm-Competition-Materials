# LCS

Let $LCS(s_1,s_2)$ denote the length of the longest common subsequence (not necessary continuity) of string $s_1$ and string $s_2$.

Now give you four integers $a,b,c,n$, you need to find three lowercase character strings $s_1,s_2,s_3$ satisfy that $|s_1|=|s_2|=|s_3|=n$ 

and $LCS(s_1,s_2)=a, LCS(s_2,s_3)=b, LCS(s_1,s_3)=c$.

## 输入描述:

The first line has four integers $a,b,c,n$.

$0\leq a,b,c\leq n$.

$1\leq n\leq 1000$.

## 输出描述:

If there is no solution, output "NO" (without double quotation marks).

If there exists solutions, you only need to output any one: output three lines, the i-th line has one strings $s_i$.

## 示例1

### 输入
```
1 2 3 4
```

### 输出
```
aqcc
abpp
abcc
```

## 示例2

### 输入
```
1 2 3 3
```

### 输出
```
NO
```