#include<cstdio>
#include<cmath>
using namespace std;
long long n,m;
int main()
{
	freopen("fenjie.in","r",stdin);
	freopen("fenjie.out","w",stdout);
	scanf("%lld",&n);
	m=sqrt(n);
	if(n%2==0)printf("%d",n/2);
	for(int i=3;i<=m;i+=2)
	{	
		bool bo=0;
		for(int k=2;k<=sqrt(i);k++)
		{
			if(i%k==0)
			{
				bo=1;break;
			}
		}
		if(n%i==0&&bo==0)
		{
			printf("%lld",n/i);
			break;
		}
	}
	return 0;
}
