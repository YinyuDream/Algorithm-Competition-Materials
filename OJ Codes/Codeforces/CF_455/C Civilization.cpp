#include<cstdio>
#include<algorithm> 
using namespace std;
const int maxn=1e6+10;
int n,m,k,q,pos1,pos2,max_dis;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],fa[maxn],dis[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	fa[fx]=fy; 
} 
void dfs1(int u,int fa,int len)
{
	if(max_dis<len)max_dis=len,pos1=u;	
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa)dfs1(v,u,len+1); 
	}
}
void dfs2(int u,int fa,int len)
{
	if(max_dis<len)max_dis=len,pos2=u;	
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa)dfs2(v,u,len+1); 
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int v,u;
		scanf("%d%d",&v,&u);
		add(v,u),add(u,v);
		merge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(fa[i]==i){
			max_dis=pos1=pos2=0;
			dfs1(i,-1,0);
			dfs2(pos1,-1,0);
			dis[i]=max_dis;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int opt,x,y;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&x);
			printf("%d\n",dis[find(x)]);
		}else{
			scanf("%d%d",&x,&y);
			int fx=find(x),fy=find(y);
			if(fx==fy)continue;
			dis[fy]=max(max((dis[fx]+1)/2+(dis[fy]+1)/2+1,dis[fx]),dis[fy]);
			merge(x,y);
		}
	}
	return 0;
}