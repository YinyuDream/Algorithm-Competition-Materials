T = eval(input())
for i in range(T):
    ppmax = int(input())
    a, b, c, d, e, f = map(int, input().split())
    Acc = (300 * a + 300 * b + 200 * c + 100 * d + 50 * e) / (a + b + c + d + e + f) / 3
    print(f'{Acc:.2f}%')
    pp = round(max(0, (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) / (a + b + c + d + e + f) / 320 - 0.8) * 5 * ppmax, 5)
    print(pp)
    pp = round(pp,0)
    print(pp)
    