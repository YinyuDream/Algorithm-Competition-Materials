n=eval(input())
ans=0
if n<=150:
    ans=n*0.4463
elif 151<=n<=400:
    ans=150*0.4463+(n-150)*0.4663
else:
    ans=150*0.4463+(400-150)*0.4663+(n-400)*0.5663
print(format(ans,".1f"))