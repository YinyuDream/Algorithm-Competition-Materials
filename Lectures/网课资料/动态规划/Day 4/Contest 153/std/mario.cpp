#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=110;
const int INF=0x3f3f3f3f;

int n,k,z[maxn],f[maxn][maxn][maxn];

int main()
{
	scanf("%d%d",&n,&k);
	for (int a=1;a<=n;a++)
		scanf("%d",&z[a]);
	memset(f,0x3f,sizeof(f));
	for (int a=1;a<=n;a++)
		f[a][1][a]=0;
	for (int a=1;a<=n;a++)
		for (int b=1;b<k;b++)
			for (int c=1;c<=a;c++)
				if (f[a][b][c]!=INF)
					for (int d=a+2;d<=n;d++)
						f[d][b+1][c] = min(f[d][b+1][c],f[a][b][c]+abs(z[d]-z[a]));
	int ans=INF;
	for (int a=1;a<=n;a++)
		for (int b=a+2*k-2;b<=n;b++)
			if (a==1 && b==n) continue;
			else ans=min(ans,f[b][k][a]+abs(z[a]-z[b]));
	printf("%d\n",ans);

	return 0;
}
