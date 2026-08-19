n = eval(input())
val = [] * n
mx = 0
for i in range(n):
    k, d, a = map(int, input().split('/'))
    if k - d >= 10:
        val.append(k * (k - d) + a)
    elif k >= d:
        val.append((k - d + 1) * 3 + a)
    else:
        val.append(a * 2)
    
    if val[i] > val[mx]:
        mx = i

print(mx + 1)