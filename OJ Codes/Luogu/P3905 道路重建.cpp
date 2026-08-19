#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e2+10;
int n,m,d,a,b;
int dis[maxn][maxn],book[maxn][maxn];
int main(){
	memset(dis,0x3f,sizeof dis);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v]=dis[v][u]=w;
	}
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		book[u][v]=book[v][u]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dis[i][j]!=0x3f3f3f3f&&book[i][j]==0)
				dis[i][j]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)	
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	scanf("%d%d",&a,&b);
	printf("%d",dis[a][b]);
	return 0;
}
