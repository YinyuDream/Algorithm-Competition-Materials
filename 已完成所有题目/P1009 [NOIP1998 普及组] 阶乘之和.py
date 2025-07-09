n=eval(input())
tot=0
for i in range(1,n+1):
	sum=1
	for j in range(1,i+1):
		sum*=j
	tot+=sum
print(tot)