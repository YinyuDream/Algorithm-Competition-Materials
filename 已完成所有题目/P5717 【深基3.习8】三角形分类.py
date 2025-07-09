a=input().split()
for i in range(len(a)):
    a[i]=int(a[i])
a.sort()
if a[0]+a[1]<=a[2]:
    print("Not triangle")
else:
    if a[0]**2+a[1]**2==a[2]**2:
        print("Right triangle")
    elif a[0]**2+a[1]**2>a[2]**2:
        print("Acute triangle")
    else :
        print("Obtuse triangle")
    if a[0]==a[1] or a[0]==a[2] or a[1]==a[2]:
        print("Isosceles triangle")
        if a[0]==a[1]==a[2]:
            print("Equilateral triangle")
