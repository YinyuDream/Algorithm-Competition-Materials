#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e6+10;
int n,k=1,ans;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
int book[maxn],cir[maxn],e[maxn],fae[maxn],fa[maxn],top;
bool get_circle(int u,int fr)
{
	book[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(i!=fr^1){
			if(book[v]){
				int t=v;
				while(t!=u){
					cir[++top]=t;
					e[top]=fae[t];
					t=fa[t];
				}
				cir[++top]=t;
				return true;
			}
			fae[v]=i;
			fa[v]=u;
			if(get_circle(v,u))return true;
		}
	}
}
void dfs1(int u,int fr,int &l,int &dis,int d,int cur)
{
	if(d>dis)dis=d,l=u;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(i!=fr^1&&i!=cur&&i!=cur^1){
			dfs1(v,i,l,dis,d+edge[i].wt,cur);
		}
	}
}
void dfs2(int u,int fr,int &r,int &dis,int d,int cur)
{
	if(d>dis)dis=d,r=u;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(i!=fr^1&&i!=cur&&i!=cur^1){
			dfs2(v,i,r,dis,d+edge[i].wt,cur);
		}
	}
}
int solve(int x)
{
	int num=0,l=0,r=0;
	top=0;
	get_circle(x,0);
	for(int i=1,d=0;i<top;i++){
		d=0;
		dfs1(cir[1],-1,l,d,0,e[i]);
		d=0;
		dfs2(l,-1,r,d,0,e[i]);
		num=max(num,d);
	}
	return num;
}
int main(){
	freopen("island.in","r",stdin);
	freopen("island.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,v,w;i<=n;i++){
		scanf("%d%d",&v,&w);
		add(i,v,w);
		add(v,i,w);
	}
	for(int i=1;i<=n;i++)
		if(!book[i])
			ans+=solve(i);
	printf("%d",ans);
	return 0;
}
