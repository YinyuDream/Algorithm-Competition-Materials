n,m=tuple(map(int,input().split()))
book=[0]*(n+10)
for i in range(m):
    l,r=tuple(map(int,input().split()))
    l+=1
    r+=1
    book[l]+=1
    book[r+1]-=1
for i in range(n+2):
    book[i]+=book[i-1]
ans=0
for i in book[1:n+2]:
    if(i==0):
        ans+=1
print(ans)