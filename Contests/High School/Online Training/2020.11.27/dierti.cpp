#include<cstdio>
using namespace std;
const int maxn=1e6+10,p=1e9+7;
int n,root,k,ans=1,fa[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn],book[maxn],sum[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int st[maxn],top;
void get_sum(int u)
{
	sum[u]=book[u];
	for(int i=head[u];i;i=edge[i].next)
		get_sum(edge[i].to),sum[u]+=sum[edge[i].to];
}
int solve()
{
	if(!book[st[top]])return 0;
	int tot=1;
	for(int i=top-1;i>=1;i--){
		if(book[st[i]])tot++;
		else if(!book[st[i]]&&sum[st[i]]-sum[st[i+1]])tot++;
	}
	return tot;
}
int dfs(int u)
{
	int sum=0;
	st[++top]=u;
	for(int i=head[u];i;i=edge[i].next)
		(sum+=dfs(edge[i].to))%=p;
	(sum+=solve())%=p;
	top--;
	return sum;
}
int main(){
	freopen("dierti.in","r",stdin);
	freopen("dierti.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&fa[i]);
		if(!fa[i])root=i;
		add(fa[i],i);
	}
	for(int i=1;i<=n;i++)
		book[i]=1,get_sum(root),ans=1ll*ans*dfs(root)%p;
	printf("%d\n",ans);
	return 0;
}
