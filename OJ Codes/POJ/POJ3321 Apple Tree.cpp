#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct node{
	int to,next;
}edge[maxn<<1];
int head[maxn];
int L[maxn],R[maxn];
int sum[maxn],a[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int x,int fa)
{
	L[x]=++k;
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa)dfs(v,x); 
	}
	R[x]=k;
	 
}
void update(int pos,int val)
{
	while(pos<=n)sum[pos]+=val,pos+=(pos&-pos);
}
int ask(int pos)
{
	int ans=0;
	while(pos)ans+=sum[pos],pos-=(pos&-pos);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),add(u,v),add(v,u);
	k=0;
	dfs(1,1);
	for(int i=1;i<=n;i++)
		update(i,1),a[i]=1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		char opt;
		int val;
		scanf("\n%c %d",&opt,&val);
		if(opt=='C')
			if(a[L[val]]==1)update(L[val],-1),a[L[val]]=0;
			else update(L[val],1),a[L[val]]=1;
		else printf("%d\n",ask(R[val])-ask(L[val]-1)); 
	}
	return 0;
}