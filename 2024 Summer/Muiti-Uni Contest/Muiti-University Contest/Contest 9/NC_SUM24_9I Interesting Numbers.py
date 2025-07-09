from math import isqrt

# Precompute powers of 10
pw10 = [10**i for i in range(31)]

def calc(n, s):
    a, b = 0, 0
    for i in range(n // 2):
        a = a * 10 + int(s[i])
    for i in range(n // 2, n):
        b = b * 10 + int(s[i])
    return (a, b)

def check(x):
    y = isqrt(x)
    return y * y == x

def max(a, b):
    return a if a > b else b

def work(n, a):
    x, y = a
    if x == pw10[n // 2 - 1]:
        if not check(x):
            return 0
        return isqrt(y) + 1
    else:
        ans = 0
        xl = isqrt(pw10[n // 2 - 1])
        xr = isqrt(x - 1)
        if xl * xl != pw10[n // 2 - 1]:
            xl += 1
        yr = isqrt(pw10[n // 2] - 1)
        ans += max(0, xr - xl + 1) * (yr + 1)
        if not check(x):
            return ans
        return ans + isqrt(y) + 1

def main():
    n = int(input())
    l, r = input().split()
    #l = input().strip()
    #r = input().strip()
    a = calc(n, l)
    b = calc(n, r)
    ans = work(n, b)
    if a[0] != pw10[n // 2 - 1] or a[1] != 0:
        if a[1] == 0:
            a = (a[0] - 1, pw10[n // 2] - 1)
        else:
            a = (a[0], a[1] - 1)
        ans -= work(n, a)
    print(ans)

if __name__ == "__main__":
    main()
