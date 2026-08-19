#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e2+10,K=20,inf=0x3f3f3f3f;
int n,m,k,ans;
int mp[maxn][maxn];
int p[maxn],l[maxn],r[maxn],t[maxn],c[maxn];
int f[1<<K][K],sum[1<<K],num[1<<K];
int main(){
	memset(mp,0x3f,sizeof mp);
	memset(f,0x3f,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v]=mp[v][u]=min(mp[u][v],w);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d%d%d",&p[i],&l[i],&r[i],&t[i],&c[i]);
	for(int u=1;u<=n;u++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][u]+mp[u][j]);
	for(int i=1;i<=n;i++)
		mp[i][i]=0;
	for(int i=1;i<(1<<k);i++)
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1)))
				sum[i]+=c[j];
	for(int i=1;i<=k;i++)
		num[1<<(i-1)]=i;
	for(int i=1;i<(1<<k);i++){
		if(num[i]&&mp[1][p[num[i]]]<=r[num[i]]){
			f[i][num[i]]=max(mp[1][p[num[i]]],l[num[i]])+t[num[i]];
			continue;
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				for(int u=1;u<=k;u++){
					if((i&(1<<u-1))&&j!=u&&f[i^(1<<(j-1))][u]!=inf){
						if(f[i^(1<<(j-1))][u]+mp[p[u]][p[j]]<l[j]){
							f[i][j]=min(f[i][j],l[j]+t[j]);
						}else if(f[i^(1<<(j-1))][u]+mp[p[u]][p[j]]>=l[j]&&f[i^(1<<(j-1))][u]+mp[p[u]][p[j]]<=r[j]){
							f[i][j]=min(f[i][j],f[i^(1<<(j-1))][u]+mp[p[u]][p[j]]+t[j]);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<(1<<k);i++)
		for(int j=1;j<=k;j++)
			if(f[i][j]!=inf)
				ans=max(ans,sum[i]);
	printf("%d",ans);
	return 0;
}
