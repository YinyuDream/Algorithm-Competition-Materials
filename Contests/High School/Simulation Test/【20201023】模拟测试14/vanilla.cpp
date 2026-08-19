#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=21;
int n,m,ans=0x3f3f3f3f;
int mp[maxn][maxn],f[1<<maxn][maxn],g[1<<maxn][maxn];
int check(int x)
{
	int cnt=0;
	for(int i=x;i;i-=i&(-i))cnt++;
	return cnt;
}
int work(int x)
{
	int val=0;
	for(int i=0;i<n;i++)
	val+=(((x>>i)&1)^1)<<(n-i-1);
	return val;
}
int main(){
	//freopen("vanilla.in","r",stdin);
	//freopen("vanilla.out","w",stdout);
	memset(mp,0x3f,sizeof mp);
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v]=mp[v][u]=min(mp[u][v],w);
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	f[1][0]=0;
	for(int i=2;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				for(int k=0;k<n;k++){
					if(k!=j&&i&(1<<k)){
						f[i][j]=min(f[i][j],f[i^(1<<j)][k]+mp[k][j]);
					}
				}
			}
		}
	}
	g[1][n-1]=0;
	for(int i=2;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<(n-j-1))){
				for(int k=0;k<n;k++){
					if(k!=j&&i&(1<<(n-k-1))){
						g[i][j]=min(g[i][j],g[i^(1<<(n-j-1))][k]+mp[k][j]);
					}
				}
			}
		}
	}
	for(int i=1,p;i<(1<<n);i++)
		if(check(i)==(n-2)/2+1&&(1&i)&&!((1<<(n-1))&i)){
			p=work(i);
			for(int j=1;j<n-1;j++){
				for(int k=1;k<n-1;k++){
					if((i&(1<<j))&&(i&(1<<k)))
						ans=min(ans,f[i][j]+g[p+(1<<(n-j-1))][j]+g[(i|(1<<(n-1)))-1][k]+f[((p+(1<<(n-k-1)))^(1<<(n-1)))+1][k]),
						printf("ss%d %d %d\n",j,i,p+(1<<(n-j-1)));
				}
			}
		}
	printf("%d",ans);
	return 0;
}
