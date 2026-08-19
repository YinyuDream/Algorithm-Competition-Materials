#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e4+10,p=1e9+7,inf=0x3f3f3f3f;
int n,m,k;
struct node{
	int to,next,wt;
}edge[maxn],edge2[maxn];
int head[maxn],head2[maxn];
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0,sign=1;
    while(!(ch>='0'&&ch<='9')){
    	if(ch=='-')sign=-sign;
    	ch=nc();
    }
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum*sign;
}
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
	swap(u,v);
	edge2[k].to=v;
	edge2[k].next=head2[u];
	edge2[k].wt=w;
	head2[u]=k;
}
int book[maxn],dis[maxn];
queue<int>q;
void spfa(int s)
{
	memset(dis,0x3f,sizeof dis);
	memset(book,0,sizeof book);
	dis[s]=0;
	book[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		book[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				if(!book[v]){
					q.push(v);
					book[v]=1;
				}
			}
		}
	}
}
int deg[maxn],deg2[maxn],f[maxn],g[maxn],ans[maxn];
void topo(int s)
{
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(dis[edge[j].to]==dis[i]+edge[j].wt&&dis[i]!=inf&&dis[edge[j].to]!=inf)
				deg[edge[j].to]++,deg2[i]++,book[j]=1;
	for(int i=1;i<=n;i++)
		if(dis[i]!=0x3f3f3f3f&&!deg2[i])
			q.push(i);
	for(int i=1;i<=n;i++)
		g[i]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head2[u];i;i=edge2[i].next){
			if(!book[i])continue;
			int v=edge2[i].to;
			g[v]=(g[u]+g[v])%p;
			if(--deg2[v]==0)q.push(v);
		}
	}
	q.push(s);
	f[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			if(!book[i])continue;
			int v=edge[i].to;
			f[v]=(f[v]+f[u])%p;
			if(--deg[v]==0)q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(book[j])
				ans[j]=(1ll*f[i]*g[edge[j].to]+ans[j])%p;	
}
int main(){
    n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++){
	    u=read(),v=read(),w=read();
		add(u,v,w);
	}
	for(int i=1;i<=n;i++)
		spfa(i),topo(i);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}