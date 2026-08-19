#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
const int maxn=1e6+10;
int n,k,ans=0x7f7f7f7f;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],size[maxn],size2[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void order(int &a,int &b,int &c)
{
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
}
pii dfs(int u,int f,int sz)
{
	pii p(0,0x3f3f3f3f),q;
	size2[u]=1;
	for(int i=head[u],a,b;i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			q=dfs(v,u,sz);
			a=q.first,b=q.second;
			if(b-a<p.second-p.first)p.second=b,p.first=a;
			size2[u]+=size2[v];
			a=size2[v],b=sz-size2[v];
			if(a>b)swap(a,b);
			if(b-a<p.second-p.first)p.first=a,p.second=b;
		}
	}
	return p;
}
void solve(int u,int f)
{
	size[u]=1;
	for(int i=head[u],a,b,c;i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			solve(v,u);
			size[u]+=size[v];
			if(size[v]>1){
				pii t=dfs(v,u,size[v]);
				a=n-size[v],b=t.first,c=t.second;
				order(a,b,c);
				ans=min(ans,c-a);
			}
			if(n-size[v]>1){
				pii t=dfs(u,v,n-size[v]);
				a=size[v],b=t.first,c=t.second;
				order(a,b,c);
				ans=min(ans,c-a);
			}
		}
	}
}
int main(){
	freopen("chilli.in","r",stdin);
	freopen("chilli.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	solve(1,1);
	printf("%d\n",ans);
	return 0;
}
