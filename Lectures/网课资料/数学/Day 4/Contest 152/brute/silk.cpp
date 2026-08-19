#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=1010;
const int mo=999999599;

int v,n,m,C[maxn][maxn];

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
	scanf("%d%d%d",&v,&n,&m);
	int p=mo-1;
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
	printf("%d\n",mul(v,C[n][m],mo));

	return 0;
}

