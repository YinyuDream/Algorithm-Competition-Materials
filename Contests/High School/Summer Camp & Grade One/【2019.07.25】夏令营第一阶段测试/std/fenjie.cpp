#include<cstdio>
using namespace std;


long long n;

int main()
{
	freopen("fenjie.in","r",stdin);
	freopen("fenjie.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			printf("%lld\n",n/i);
			return 0;
		}
	}
	return 0;
}
