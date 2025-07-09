n=eval(input())
a=input().split()
ans=1001
for i in range(0,n):
    ans=min(ans,int(a[i]))
print(ans)