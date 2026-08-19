#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=20;

int n,d,z[maxn][2],y[maxn<<1],f[1<<maxn];

int main()
{
	scanf("%d%d",&n,&d);
	for (int a=1;a<=n;a++)
		scanf("%d%d",&z[a][0],&z[a][1]);
	for (int a=0;a<(1<<n);a++)
	{
		int cnt=0;
		for (int b=1;b<=n;b++)
			if (a&(1<<(b-1)))
			{
				y[++cnt]=z[b][0];
				y[++cnt]=z[b][1];
			}
		sort(y+1,y+cnt+1);
		bool able=true;
		for (int b=1;b<=cnt;b+=2)
			if (y[b+1]-y[b]>d) able=false;
		if (able) f[a]=1;
		else f[a]=-0x3f3f3f3f;
	}
	f[0]=0;
	for (int a=1;a<(1<<n);a++)
		for (int b=a;b;b=(b-1)&a)
			f[a]=max(f[a],f[a^b]+f[b]);
	if (f[(1<<n)-1]<0) printf("-1\n");
	else printf("%d\n",n-f[(1<<n)-1]);

	return 0;
}
