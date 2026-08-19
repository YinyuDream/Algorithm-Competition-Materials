data=input().split()
n=int(data[0])
k=int(data[1])


num=n//3
if num<k:
    print(-1,end="")
else:
    print("heu"*k+"h"*(n-k*3),end="")
