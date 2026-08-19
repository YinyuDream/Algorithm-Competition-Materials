#include<cstdio>
using namespace std;
int a,b,n,ans;
int k,A=0,x;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	x=k=a/b;
	if(k==0){A=A+1;}
	while(k>0)
	{
		k=k/10;
		A++;
	}
	if(n<=A)
	{
		for(int i=1;i<=A-n+1;i++)
		{
		ans=x%10;
		x=x/10;
		}
	}
	else
	{
		k=a%b;
		for(int j=1;j<=n-A;j++)
		{
		k=k*10;
		ans=k/b;
		k=k%b;
		}
	}
printf("%d",ans);	 
return 0; 
}
