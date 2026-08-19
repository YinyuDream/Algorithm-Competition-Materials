n=eval(input())
a=input().split()
a=list(map(int,a))
a.sort()
ans=0
for i in a[1:-1]:
    ans+=i
ans/=(n-2)
print(format(ans,".2f"))

