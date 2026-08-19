a, plus, b, eq, c = input().split()

def check(a, b, c):
    if int(a) + int(b) == int(c):
        print("Yes")
        print(f"{a} + {b} = {c}")
        exit(0)


check(a, b, c)
for i in range(len(a)+1):
    for j in range(10):
        check(a[:i] + str(j) + a[i:], b, c)
for i in range(len(b)+1):
    for j in range(10):
        check(a, b[:i] + str(j) + b[i:], c)
for i in range(len(c)+1):
    for j in range(10):
        check(a, b, c[:i] + str(j) + c[i:])

print("No")