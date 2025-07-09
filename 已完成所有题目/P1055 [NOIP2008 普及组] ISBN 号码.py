a=list(input())
b=list(a)
sum=0
while "-" in a:
    a.remove("-")
for i in range(9):
    sum+=int(a[i])*(i+1)
val=str(sum%11) if sum%11<10 else "X"
if val==a[9]:
    print("Right")
else:
    b.pop()
    b.append(val)
    ans=""
    for i in b[:-1]:
        ans+=i
    ans+=val
    if ans[12]=="2":
        ans2=ans[:12]+"7"
        print(ans2)
    else:
        print(ans)



