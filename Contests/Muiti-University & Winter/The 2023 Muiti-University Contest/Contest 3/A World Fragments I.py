x=input()
y=input()
if int(x,2)==0 and int(y,2)!=0:
    print(-1)
else:
    ans=abs(int(x,2)-int(y,2))
    print(ans)