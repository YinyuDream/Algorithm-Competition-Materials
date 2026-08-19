#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int mo=1000000007;

int n,k;

int mul(int a,int b,int mo)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=1ll*ans*a%mo;
		a=1ll*a*a%mo;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	n=(n>>1)+(n&1);
	printf("%d\n",mul(k,n,mo));

	return 0;
}
