#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,ans;
int c[maxn*maxn],dis[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=2;i<=m;i++)
		ans+=dis[c[i-1]][c[i]];
	printf("%d",ans);
	return 0;
}
