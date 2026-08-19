#include<stdio.h>
using namespace std;
const int N=300005;
int read() {
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct Edge {
	int v,nxt;
}e[N<<1];
int head[N],size;
void add(int u,int v) {
	e[++size].v=v;
	e[size].nxt=head[u];
	head[u]=size;
}
int n,m,deg[N],dfn[N];
void init() {
	for(int i=1;i<=n;++i)deg[i]=head[i]=dfn[i]=0;
	for(int i=1;i<=size;++i)e[i].nxt=e[i].v=0;
	size=0;
}
bool dfs(int u,int fa) {
	if(!dfn[u])dfn[u]=1;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].v;
		if(dfn[u]==-1&&dfn[v])continue;
		if(v==fa||dfn[v]==-1)continue;
		if(dfn[v])return 0;
		if(!dfs(v,u))return 0;
	}
	return 1;
}
int max(int a,int b){return a>b?a:b;}
int work() {
	n=read();m=read();
	init();
	int MX=0;
	for(int i=1;i<=m;++i) {
		int u=read(),v=read();
		add(u,v);
		add(v,u);
		++deg[u];
		++deg[v];
	}
	int ji=0;
	for(int i=1;i<=n;++i)ji+=deg[i]&1,MX=max(MX,deg[i]);;
	if(ji>2)return -1;
	else {
		if(ji)for(int i=1;i<=n;++i) {
			if(deg[i]%2==0)continue;
			for(int j=1;j<=n;++j)dfn[j]=0;
			dfn[i]=-1;
			if(dfs(i,0))return printf("ss%d\n",i),1;
		}
		else for(int i=1;i<=n;++i) {
			if(deg[i]!=MX)continue;
			for(int j=1;j<=n;++j)dfn[j]=0;
			dfn[i]=-1;
			if(dfs(i,0))return 1;
		}
	}
	return -1;
}
int main() {
	//freopen("walk.in","r",stdin);
	//freopen("walk.out","w",stdout);
	int T=read();
	while(T--)printf(work()>0?"YES\n":"NO\n");
	return 0;
}
