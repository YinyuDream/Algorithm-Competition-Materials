n=list(input())
while n[-1]=="0" and len(n)>1:
    n.pop()
n.reverse()
if n[-1]=="-":
    n.pop()
    n.insert(0,"-")
ans=""
for i in n:
    ans+=i
print(ans)