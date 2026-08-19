#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int t,n,k;
struct node{
	int from,to;
}edge[maxn];
int book[maxn],pos[maxn],ans[maxn],now[maxn];
void add(int u,int v)
{
	edge[++k].from=u;
	edge[k].to=v;
}
void update()
{
	for(int i=1;i<=n;i++)
		if(pos[i]<ans[i]){
			for(int i=1;i<=n;i++)ans[i]=pos[i];
			return ;
		}
		else if(pos[i]==ans[i])continue;
		else return ;
}
void dfs(int x)
{
	if(x==n-1){
		update();return ;
	}
	for(int i=1;i<n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			swap(pos[now[edge[i].from]],pos[now[edge[i].to]]);
			swap(now[edge[i].from],now[edge[i].to]);
			dfs(x+1);
			book[i]=0;
			swap(now[edge[i].from],now[edge[i].to]);
			swap(pos[now[edge[i].from]],pos[now[edge[i].to]]);
		}
	}
	
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		k=0;
		memset(ans,0x7f,sizeof ans);
		memset(book,0,sizeof book);
		memset(pos,0,sizeof pos);
		memset(now,0,sizeof now);
		memset(edge,0,sizeof edge);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&pos[i]),now[pos[i]]=i;
		int u,v;
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),add(u,v);
		dfs(0);
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
