mod = 998244353
a = 1
for i in range(2, 114514 + 1, 2):
    a *= i
    a %= mod

print(a)