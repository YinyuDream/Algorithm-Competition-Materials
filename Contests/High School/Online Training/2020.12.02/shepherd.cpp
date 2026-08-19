#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k,ans,flag=1;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],a[maxn],book[maxn],pos[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
namespace subtask1{
	void work(){
		sort(a+1,a+m+1);
		a[m+1]=a[m];
		for(int i=1;i<=m;i++){
			if(book[i])continue;
			book[i]=1;
			if((a[i+1]-a[i])%2==0)
				book[i+1]=1;
			pos[++ans]=(a[i+1]+a[i])/2;
		}
		printf("%d\n",ans);
		for(int i=1;i<=ans;i++)
			printf("%d ",pos[i]);
	}
}
namespace subtask2{
	int fa[maxn][20],deep[maxn];
	bool cmp(int a,int b)
	{
		return deep[a]>deep[b];
	}
	void dfs(int u,int f)
	{
		for(int i=1;i<=19;i++)
			fa[u][i]=fa[fa[u][i-1]][i-1];
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(v!=f){
				deep[v]=deep[u]+1;
				fa[v][0]=u;
				dfs(v,u);
			}
		}
	}
	int lca(int u,int v)
	{
		if(deep[u]<deep[v])swap(u,v);
		int delta=deep[u]-deep[v];
		for(int i=0;i<=19;i++)
			if(delta&(1<<i))
				u=fa[u][i];
		if(u==v)return u;
		for(int i=19;i>=0;i--)
			if(fa[u][i]!=fa[v][i])
				u=fa[u][i],v=fa[v][i];
		return fa[u][0];
	}
	int query(int u)
	{
		int mn=0x3f3f3f3f;
		for(int i=1;i<=m;i++)
			mn=min(mn,deep[u]+deep[a[i]]-2*deep[lca(u,a[i])]);
		return mn;
	}
	void jump(int u)
	{
		int now=u;
		while(deep[u]-deep[fa[now][0]]==query(fa[now][0])&&now>1)now=fa[now][0];
		for(int i=1;i<=m;i++)
			if(deep[now]+deep[a[i]]-2*deep[lca(now,a[i])]==deep[u]-deep[now])
				book[a[i]]=1;
		pos[++ans]=now;
	}
	void work()
	{
		dfs(1,1);
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(book[a[i]])continue;
			book[a[i]]=1;
			jump(a[i]);
		}
		printf("%d\n",ans);
		for(int i=1;i<=ans;i++)
			printf("%d ",pos[i]);
	}
}
int main(){
	freopen("shepherd.in","r",stdin);
	freopen("shepherd.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		flag&=(v==u+1);
	}
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	if(flag)subtask1::work();
	else subtask2::work();
	return 0;
}
