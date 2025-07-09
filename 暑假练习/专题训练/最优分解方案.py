'''
给定正整数$n(n\leq 1000)$,设$n=\sum\limits_{i=1}^k a_i$且对于任意$i,j$满足$$a_i \neq a_j$.试求$\prod\limits_{i=1}^{k}$的最大值.
'''
import math

n = int(input())  # 输入一个正整数 n
f = [[0] * (n + 1) for _ in range(n + 1)]  # 初始化二维数组 f
ans = 0  # 最大乘积的结果

for i in range(n + 1):
    f[0][i] = 1  # 初始化边界条件

for i in range(1, n + 1):
    low_j = int(math.sqrt(2 * i))  # 确定 j 的最小值
    for j in range(low_j, i + 1):  # 遍历 j
        low_k = int(math.sqrt(2 * (i - j)))  # 确定 k 的最小值
        max_k = min(i - j + 1, j)  # k 的最大值不超过 i-j+1 和 j 中的较小值
        for k in range(low_k, max_k):  # 遍历 k
            f[i][j] = max(f[i][j], f[i - j][k] * j)  # 计算 f[i][j] 的最大值
            if f[i][j] != 0 and max_k - low_k >= 4:
                break

for i in range(1, n + 1):
    ans = max(ans, f[n][i])  # 找到最大的 f[n][i]
print(ans)  # 输出最大乘积结果
