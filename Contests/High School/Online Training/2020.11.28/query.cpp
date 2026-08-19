#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int fa[maxn][20],deep[maxn];
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
	for(int i=19;i>=0;i--)
		if(delta&(1<<i))
			u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
vector<pair<int,int> >q[maxn];
int l[maxn],r[maxn],ance[maxn],ans[maxn],book[maxn][2];
void solve(int u,int f)
{
	book[deep[u]+u][0]++;
	book[u-deep[u]+n][1]++;
	for(int i=0;i<q[u].size();i++){
		int id=q[u][i].first,opt=q[u][i].second;
		if(opt==0)ans[id]+=book[deep[l[id]]][0];
		else if(opt==1)ans[id]-=book[deep[l[id]]][0];
		else if(opt==2)ans[id]+=book[deep[l[id]]-2*deep[ance[id]]+n][1];
		else ans[id]-=book[deep[l[id]]-2*deep[ance[id]]+n][1];
		
	}
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f)
			solve(v,u);
	}
	book[deep[u]+u][0]--;
	book[u-deep[u]+n][1]--;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l[i],&r[i]);
		ance[i]=lca(l[i],r[i]);
		q[l[i]].push_back(make_pair(i,0));
		q[fa[ance[i]][0]].push_back(make_pair(i,1));
		q[r[i]].push_back(make_pair(i,2));
		q[fa[ance[i]][0]].push_back(make_pair(i,3));
	}
	solve(1,1);
	for(int i=1;i<=m;i++)
		if(ance[i]==deep[l[i]]-deep[ance[i]])
			ans[i]--;
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
