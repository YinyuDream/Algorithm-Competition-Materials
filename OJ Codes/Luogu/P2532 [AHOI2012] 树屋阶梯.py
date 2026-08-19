n=int(input())
pre=1
for i in range(1,n+1):
	ans=pre*(4*i-2)/(i+1)
	pre=ans
print(int(ans))