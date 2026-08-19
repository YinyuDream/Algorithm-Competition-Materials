#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,q,p;
int t[maxn],mp[maxn][maxn];
void work(int x)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]=min(mp[i][j],mp[i][x]+mp[x][j]);
}
int main(){
	memset(mp,0x3f,sizeof mp);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		u++,v++;
		mp[u][v]=mp[v][u]=w;
	}
	for(p=1;p<=n;p++)
		if(!t[p])work(p);
		else break;
	scanf("%d",&q);
	for(int i=1,x,y,w;i<=q;i++){
		scanf("%d%d%d",&x,&y,&w);
		x++,y++;
		while(t[p]<=w&&p<=n)work(p),p++;
		printf("%d\n",(mp[x][y]!=0x3f3f3f3f&&t[x]<=w&&t[y]<=w)?mp[x][y]:-1);
	}
	return 0;
}
