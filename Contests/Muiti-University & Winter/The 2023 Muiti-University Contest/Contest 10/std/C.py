n_str = input().strip()
k = int(input().strip())
n = int(n_str)
L = len(n_str)

def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)

ans = 0
for l in range(L, 0, -1):
    if ans > 0:
        break
    for x in range(1, l):
        """
        |---- y ----|------- x -------|
        """
        y = l - x
        if l == L:
            maxA = int(n_str[:y])
        else:
            maxA = 10**y - 1
        maxB = 10**x - 1
        minA = 10**(y-1)
        minB = 10**(x-1)
            
        # A = tP, B = tQ
        # minA <= A <= maxA, minB <= B <= maxB
        P = 10**y - k
        Q = k * 10**x - 1
        g = gcd(P, Q)
        P //= g
        Q //= g
        
        maxt = min(maxA // P, maxB // Q)
        mint = max((minA + P - 1) // P, (minB + Q - 1) // Q)

        def calc(t):
            global ans
            if t > maxt or t < mint:
                return
            A = t * P
            B = t * Q

            ret = A * 10**x + B
            if ret <= n:
                ans = max(ans, ret)
        
        calc(maxt)
        calc(maxt - 1)

print(ans)