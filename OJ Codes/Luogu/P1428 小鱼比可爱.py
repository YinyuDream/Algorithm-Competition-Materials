n=eval(input())
a=list(map(int,input().split()))
tot=[0]*11
for i in range(n):
    print(sum(tot[0:a[i]]),end=" ")
    tot[a[i]]+=1