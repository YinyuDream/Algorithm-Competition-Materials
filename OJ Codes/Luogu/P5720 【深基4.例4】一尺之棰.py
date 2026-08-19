n=eval(input())
cnt=0
while n>1:
    n//=2
    cnt+=1
print(cnt+1)