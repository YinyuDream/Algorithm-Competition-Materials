#include<cstdio>
#include<cmath> 
using namespace std;
int k=1,ans;
int s[100010];
long long n,c,a,b=1;
void f(int x)
{
	s[1]=2;
	for(int i=3;i<=x;i+=2)
	{
		bool bo=0; 
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				bo=1;
				break;
			}
		}
	if(bo==0)
		{
		k++;s[k]=i;
		}
	}
	k=k-1;
}
int main()
{
	scanf("%lld",&n);
	c=n;
	a=sqrt(n);
	f(a);
	for(int i=1;i<=k+1;i++)
	{
		while(n%s[i]==0)
		{
			n=n/s[i];
			ans=s[i];
			b=b*s[i];
		}
	}
	if(n!=1)ans=c/b;
	printf("%d",ans);	
}
