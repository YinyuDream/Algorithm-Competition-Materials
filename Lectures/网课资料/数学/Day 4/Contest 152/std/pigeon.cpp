#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int maxn=52;
const int mo=1000000007;

int n,m,k,C[maxn*maxn][maxn],f[maxn][maxn];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	C[0][0]=1;
	for (int a=1;a<=2500;a++)
	{
		C[a][0]=1;
		for (int b=1;b<=a && b<=50;b++)
		{
			C[a][b]=C[a-1][b-1]+C[a-1][b];
			if (C[a][b]>=mo) C[a][b]-=mo;
		}
	}
	f[1][0]=1;
	for (int a=2;a<=n;a++)
		for (int b=a-1;b<=C[a][2] && b<=m;b++)
		{
			f[a][b] = C[C[a][2]][b];
			for (int c=1;c<a;c++)
				for (int d=c-1;d<=C[c][2] && d<=b;d++)
				{
					f[a][b] = f[a][b] - 1ll*f[c][d]*C[a-1][c-1]%mo*C[C[a-c][2]][b-d]%mo;
					if (f[a][b]<0) f[a][b]+=mo;
				}
		}
	int ans=0;
	if (k==0) ans=f[n][m];
	else if (k==1)
	{
		ans = 1ll*C[n-1][2]*f[n-1][m-2]%mo;
		for (int a=1;a<=n-2;a++)
			for (int b=a-1;b<=C[a][2] && b<=m-2;b++)
			{
				ans = ans + 1ll*f[a][b]*f[n-1-a][m-2-b]%mo*a*(n-a-1)%mo*C[n-2][a-1]%mo;
				if (ans >= mo) ans-=mo;
			}
	}
	else
	{
		ans = 1ll*f[n-2][m-3]*(n-2)*(n-2)%mo;
		for (int a=1;a<=n-3;a++)
			for (int b=a-1;b<=C[a][2] && b<=m-3;b++)
			{
				ans = ans + 1ll*f[a][b]*f[n-2-a][m-3-b]%mo*a*(n-a-2)*2%mo*C[n-3][a-1]%mo;
				if (ans >= mo) ans-=mo;
			}
		ans = ans + 1ll*f[n-2][m-4]*C[n-2][2]%mo*C[n-2][2]%mo;
		if (ans >= mo) ans-=mo;
		for (int a=1;a<=n-3;a++)
			for (int b=a-1;b<=C[a][2] && b<=m-4;b++)
			{
				ans = ans + 1ll*f[a][b]*f[n-2-a][m-4-b]%mo*C[n-3][a-1]%mo*(1ll*C[n-2][2]*C[n-2][2]-C[a][2]*C[n-a-2][2]*2-C[a][2]*C[a][2]-C[n-a-2][2]*C[n-a-2][2])%mo;
				if (ans >= mo) ans-=mo;
			}
		for (int a=1;a<=n-4;a++)
			for (int b=a-1;b<=C[a][2] && b<=m-4;b++)
				for (int c=1;a+c<=n-3;c++)
					for (int d=c-1;d<=C[c][2] && b+d<=m-4;d++)
					{
						ans = ans + 1ll*f[a][b]*f[c][d]%mo*C[n-3][a-1]%mo*C[n-3-a][c-1]%mo*f[n-2-a-c][m-4-b-d]%mo*a*c%mo*(n-2-a-c)*(n-2)*2%mo;
						if (ans >= mo) ans-=mo;
					}
	}
	printf("%d\n",ans);

	return 0;
}
