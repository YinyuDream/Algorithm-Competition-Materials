#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int maxn=1010;

int n,p,C[maxn][maxn];

int mul(int a,long long b,int mo)
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
	scanf("%d%d",&n,&p);
	C[0][0]=1;
	for (int a=1;a<=n;a++)
	{
		C[a][0]=1;
		for (int b=1;b<=a;b++)
		{
			C[a][b]=C[a-1][b-1]+C[a-1][b];
			if (C[a][b]>=p) C[a][b]-=p;
		}
	}
	int ans=0;
	for (int a=0;a<=n;a++)
		for (int b=0;b<=a;b++)
		{
			ans += 1ll*C[a][b]*C[a][b]%p;
			if (ans>=p) ans-=p;
		}
	ans = 1ll*ans*mul(p-1,p-2,p)%p;
	printf("%d\n",ans);

	return 0;
}

