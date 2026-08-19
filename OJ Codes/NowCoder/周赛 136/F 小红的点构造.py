import sys

def solve():
    n, k = map(int, sys.stdin.readline().split())

    # 计算最大可能边数
    max_k = 0
    for r in range(1, n+1):
        # ceil(n/r) = (n + r - 1) // r
        cur = 2 * n - r - (n + r - 1) // r
        if cur > max_k:
            max_k = cur

    if k > max_k:
        print("No")
        return
    
    print("Yes")
    
    # 如果k <= n-1，使用一条直线加孤立点
    if k <= n - 1:
        # 直线上的点：从 (0,0) 到 (k,0)
        for i in range(k + 1):
            print(i, 0)
        # 孤立点：放在 y=2,4,6,... 处，x=0
        for i in range(n - k - 1):
            print(0, 2 * (i + 1))
        return

    # 否则，k >= n，使用行长度递减的构造
    # 寻找合适的行数 r
    for r in range(2, n+1):
        c1 = 2 * n - r - k
        if c1 < 1:
            continue
        if c1 >= (n + r - 1) // r:
            break

    # 构造每行的长度
    s = n - c1
    base = s // (r - 1)
    rem = s % (r - 1)
    # c[0] = c1, c[1]...c[rem] = base+1, c[rem+1]...c[r-1] = base
    rows = [c1] + [base+1] * rem + [base] * (r - 1 - rem)

    # 输出点
    for y, length in enumerate(rows):
        for x in range(length):
            print(x, y)

if __name__ == "__main__":
    solve()