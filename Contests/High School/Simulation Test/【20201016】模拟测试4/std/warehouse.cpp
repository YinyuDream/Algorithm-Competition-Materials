#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
#define re register
const int N=2e5+10;
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
ll ans[N],dis[N],f[N][17];
int head[N],k=0,n,m,size[N];
struct M{
	int to,next,val;
}edge[N*2];
void build(int x,int y,int z){
	edge[++k].next=head[x];
	edge[k].to=y;
	edge[k].val=z;
	head[x]=k;
}
void dfs1(int x,int fa){
	size[x]=1,dis[x]=0,f[x][0]=1;
	for(int j=1;j<16;j++) f[x][j]=0;
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa) continue;
		dfs1(v,x);
		for(int j=0;j<16;j++) f[x][(j+edge[i].val)%16]+=f[v][j];
		size[x]+=size[v];
		dis[x]+=dis[v]+size[v]*edge[i].val;
	}
}
void dfs2(int x,int fa,ll sum){
	ans[x]=sum;
	for(int i=1;i<16;i++) ans[x]-=f[x][i]*i;
	f[x][0]--;
	for(int i=0;i<16;i++) ans[x]+=f[x][i]*(i^m);
	f[x][0]++;
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa) continue;
		for(int j=0;j<16;j++) f[x][(j+edge[i].val)%16]-=f[v][j];
		for(int j=0;j<16;j++) f[v][(j+edge[i].val)%16]+=f[x][j];
		dfs2(v,x,sum+edge[i].val*(n-size[v]*2));
		for(int j=0;j<16;j++) f[v][(j+edge[i].val)%16]-=f[x][j];
		for(int j=0;j<16;j++) f[x][(j+edge[i].val)%16]+=f[v][j];
	}
}
void work(){
	dfs1(1,1);
	dfs2(1,1,dis[1]);
	for(re int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}
int main()
{
	freopen("warehouse.in","r",stdin);
	freopen("warehouse.out","w",stdout);
	int x,y,z;
	n=read(),m=read();
	for(re int i=1;i<n;i++){
		x=read(),y=read(),z=read();
		build(x,y,z),build(y,x,z);
	}work();
	return 0;
}
