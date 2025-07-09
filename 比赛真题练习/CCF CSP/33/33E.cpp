#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,m,cnt_edge;
int dfn[maxn],old[maxn],size[maxn],deep[maxn],tree[maxn],t[maxn],c[maxn],cnt;
ll d[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
int unused[maxn],point[maxn];
void add_edge(int u,int v)
{
	edge[++cnt_edge].to=v;
	edge[cnt_edge].next=head[u];
	head[u]=cnt_edge;
}
void dfs(int u)
{
	dfn[u]=++cnt;
	old[cnt]=u;
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		deep[v]=deep[u]+1;
		dfs(v);
		size[u]+=size[v];
	}
}
void add(int x,int val)
{
	while(x<=n){
		tree[x]+=val;
		x+=x&(-x);
	}
}
void ask(int x)
{
	x=dfn[x];
	int ans=0;
	while(x){
		ans+=tree[x];
		x-=x&(-x);
	}
	cout<<ans<<endl;
}
void merge(int u)
{
	unused[0]=point[0]=0;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		d[u]+=d[v];
		unused[++unused[0]]=i;
		for(int j=head[v];j;j=edge[j].next){
			point[++point[0]]=edge[j].to;
			unused[++unused[0]]=j;
		}
	}
	head[u]=0;
	for(int i=1;i<=point[0];i++){
		edge[unused[i]].to=point[i];
		edge[unused[i]].next=head[u];
		head[u]=unused[i];
	}
	cout<<point[0]<<" "<<d[u]<<endl;
	if(!point[0])return ;
	add(dfn[u]+1,-1);
	add(dfn[u]+size[u],1); 
}
int main(){
	cin>>n>>m;
	for(int i=2,fa;i<=n;i++){
		cin>>fa;
		add_edge(fa,i);
	}
	for(int i=1;i<=n;i++)
		cin>>d[i];
	deep[1]=1,dfs(1);
	for(int i=1;i<=n;i++)
		t[i]=deep[old[i]];
	for(int i=1;i<=n;i++)
		c[i]=t[i]-t[i-1];
	for(int i=1;i<=n;i++)
		add(i,c[i]);
	for(int i=1,opt,x;i<=m;i++){
		cin>>opt>>x;
		if(opt==1)merge(x);
		else ask(x);
	}
	return 0;
}