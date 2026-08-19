#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10,p=201314;
int n,k,q,flag=1;
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn];
int deep[maxn],fa[maxn][20];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	deep[u]=deep[f]+1;
	for(int i=1;i<=19;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
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
namespace subtask1
{
	void work()
	{
		for(int i=1,l,r,z,ans;i<=q;i++){
			ans=0;
			scanf("%d%d%d",&l,&r,&z);
			for(int j=l;j<=r;j++)
				ans=(ans+deep[lca(j,z)])%p;
			printf("%d\n",ans);
		}
	}
}
namespace subtask2
{
	int sum[maxn];
	void work()
	{
		for(int i=1;i<=n;i++)
			sum[i]=(sum[i-1]+deep[i])%p;
		for(int i=1,l,r,z;i<=q;i++){
			scanf("%d%d%d",&l,&r,&z);
			if(deep[r]<=deep[z])printf("%d\n",(sum[r]-sum[l-1]+p)%p);
			else if(deep[r]>deep[z]&&deep[l]<=deep[z])printf("%d\n",(sum[z]-sum[l-1]+1ll*(r-z)*deep[z]%p+p)%p);
			else printf("%d\n",(1ll*(r-l+1)*deep[z])%p);
		}
	}
}
namespace subtask3
{
	int sum[maxn],_flag=0;
	void work()
	{
		for(int i=1,l,r,z;i<=q;i++){
			scanf("%d%d%d",&l,&r,&z);
			if(!_flag){
				for(int j=1;j<=n;j++)
					sum[j]=(sum[j-1]+deep[lca(j,z)])%p;
				_flag=1;
			}
			printf("%d\n",(sum[r]-sum[l-1]+p)%p);
		}
	}
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=2,v;i<=n;i++){
		scanf("%d",&v);
		flag&=(v==i-1);
		add(v,i);
		add(i,v);
	}
	dfs(1,0);
	if(n<=1000)subtask1::work();
	else if(flag)subtask2::work();
	else subtask3::work();
	return 0;
}
