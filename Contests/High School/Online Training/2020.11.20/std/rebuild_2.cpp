#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define mo 998244353
#define maxn 505
#define clear(a) memset(a,0,sizeof(a))
using namespace std;

int n,u,v,i,j,k,fa[maxn*2],sz[maxn*2],tot;
ll f[maxn*2][maxn],g[maxn*2],fct[maxn];
struct edge{int x,y,z;} e[maxn];
int cmp(edge a,edge b){return a.z<b.z;}

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

int bz[maxn*2],vis[maxn*2],E[maxn*2][maxn*2],bz0[maxn*2],a[maxn*2][maxn*2];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}
void merge(int x,int p){
	a[p][++a[p][0]]=bz0[x];
	if (sz[bz0[x]]) g[p]=g[p]*sz[bz0[x]]%mo;
	vis[x]=1,fa[bz0[x]]=p,sz[p]+=sz[bz0[x]];
	for(int i=1;i<=E[x][0];i++) if (!vis[E[x][i]])
		merge(E[x][i],p);
}
void build(){
	for(i=1;i<n;i=j){
		for(j=i;j<n&&e[j].z==e[i].z;j++);
		memset(bz,0,sizeof(bz));
		memset(vis,0,sizeof(vis));
		int cnt=0;
		for(k=i;k<j;k++){
			int x=father(e[k].x); if (!bz[x]) bz[x]=++cnt,bz0[cnt]=x,E[cnt][0]=0;
			int y=father(e[k].y); if (!bz[y]) bz[y]=++cnt,bz0[cnt]=y,E[cnt][0]=0;
			E[bz[x]][++E[bz[x]][0]]=bz[y];
			E[bz[y]][++E[bz[y]][0]]=bz[x];
		}
		for(k=1;k<=cnt;k++) if (!vis[k]){
			tot++,g[tot]=1,fa[tot]=tot,merge(k,tot);
			g[tot]=g[tot]*ksm(sz[tot],a[tot][0]-2)%mo;
		}
	}
}

ll F[maxn][maxn][2],G[maxn][maxn][2],cnt[maxn*2][2],h[maxn],tmp[maxn];
void dfs(int x){
	if (x<=n){
		cnt[x][0]=(x==u),cnt[x][1]=(x==v);
		if (x!=u&&x!=v) f[x][0]=1; f[x][1]=1;
		return;
	}
	for(int i=1;i<=a[x][0];i++) {
		dfs(a[x][i]);
		cnt[x][0]+=cnt[a[x][i]][0];
		cnt[x][1]+=cnt[a[x][i]][1];
	}
	for(int i=1;i<=a[x][0];i++) if (cnt[a[x][i]][0]&&cnt[a[x][i]][1]){
		memcpy(f[x],f[a[x][i]],sizeof(f[x]));
		ll tmp=g[x];
		for(int j=1;j<=a[x][0];j++) if (i!=j) 
			tmp=tmp*f[a[x][j]][0]%mo;
		for(int j=1;j<=sz[x];j++)
			f[x][j]=f[x][j]*tmp%mo;
		return;
	}
	int Sz=0,Cnt=0; clear(F),F[0][0][0]=1;
	for(int now=1;now<=a[x][0];now++) {
		int y=a[x][now];
		if (cnt[y][0]||cnt[y][1]) continue;
		clear(G);
		for(int i=0;i<=Cnt;i++) for(int j=0;j<=Sz;j++) for(int t=0;t<2;t++)	if (F[i][j][t]){
			(G[i][j][t]+=F[i][j][t]*f[y][0]%mo*sz[y]%mo*sz[x])%=mo;
			if (t<1) (G[i][j][t+1]+=F[i][j][t]*f[y][0]%mo*sz[y]%mo*sz[y]%mo*sz[x])%=mo;
			for(int k=1;k<=sz[y];k++)
				(G[i+1][j+k][t]+=F[i][j][t]*f[y][k])%=mo;
		}
		memcpy(F,G,sizeof(F));
		Cnt++,Sz+=sz[y];
	}
	if (!cnt[x][0]&&!cnt[x][1]){
		ll inv=ksm(sz[x],mo-2);
		f[x][0]=F[0][0][0]*inv%mo;
		for(int i=1;i<=Cnt;i++) for(int j=1;j<=Sz;j++) 
			(f[x][j]+=(F[i][j][0]*sz[x]-F[i][j][1])%mo*fct[i])%=mo;
		for(int j=0;j<=Sz;j++) f[x][j]=f[x][j]*inv%mo;
		return;
	} 
	memset(h,0,sizeof(h));
	for(int i=0;i<=Cnt;i++) for(int j=0;j<=Sz;j++) 
		(h[j]+=(F[i][j][0]*sz[x]-F[i][j][1])%mo*fct[i]%mo)%=mo;
	if (cnt[x][0]) 
		for(int now=1;now<=a[x][0];now++) if (cnt[a[x][now]][0]){
			int y=a[x][now];
			for(int i=1;i<=sz[y];i++)
				for(int j=0;j<=Sz;j++)
					(f[x][i+j]+=f[y][i]*h[j])%=mo;
			Sz+=sz[y];
		}
	if (cnt[x][1])
		for(int now=1;now<=a[x][0];now++) if (cnt[a[x][now]][1]){
			int y=a[x][now];
			if (cnt[x][0]){
				memset(tmp,0,sizeof(tmp));
				for(int i=1;i<=Sz;i++) 
					for(int j=1;j<=sz[y];j++)
						(tmp[i+j]+=f[x][i]*f[y][j])%=mo;
				memcpy(f[x],tmp,sizeof(tmp));
			} else {
				for(int i=1;i<=sz[y];i++)
					for(int j=0;j<=Sz;j++)
						(f[x][i+j]+=f[y][i]*h[j])%=mo;
			}
		}
	ll inv=ksm(sz[x],mo-2);
	for(int i=1;i<=sz[x];i++) 
		f[x][i]=f[x][i]*inv%mo;
}
	

int main(){
	freopen("rebuild.in","r",stdin);
	freopen("rebuild.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	scanf("%d%d",&u,&v);
	fct[0]=1;for(i=1;i<=n;i++) fct[i]=fct[i-1]*i%mo;
	sort(e+1,e+n,cmp),tot=n;
	for(i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	build();
	dfs(tot);
	for(i=1;i<=n;i++) printf("%lld ",(f[tot][i]+mo)%mo);
}
