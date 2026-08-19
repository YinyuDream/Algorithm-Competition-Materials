T = eval(input())
for i in range(T):
    a = input()
    if eval(a) < 100:
        print("NO")
        continue
    else:
        b = a[0:2]
        if eval(b) != 10:
            print("NO")
            continue
        else:
            c=a[2:4]
            if c[0] == '0' or eval(c) < 2:
                print("NO")
                continue
            else:
                print("YES")