//WA don't konw why
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
double f[maxn][2],ans=0;
int n,m,r,l;
int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&l,&r)&&(n|m|r|l))
	{
		memset(f,0,sizeof(f));
		int cur=0;ans=0;f[1][cur]=1;
		for(int i=1,x;i<=m;i++)
		{
			scanf("%d",&x);
			x%=n;cur^=1;
			for(int j=1;j<=n;j++)
			{
				int t1=j-x,t2=j+x;
				if(t1<1) t1+=n;
				if(t2>n) t2-=n; 
				f[j][cur]+=f[t1][cur^1]*0.5;
				f[j][cur]+=f[t2][cur^1]*0.5;
			}
		}
		for(int i=l;i<=r;i++) ans+=f[i][cur];
		printf("%.4lf\n",ans);
	}
	return 0;
}
