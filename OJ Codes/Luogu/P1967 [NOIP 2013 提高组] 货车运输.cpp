#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
int n,m,q,k,fa[maxn],deep[maxn],head[maxn],book[maxn];
struct node{
	int to,next,val;
}edge_tree[maxn],edge[5*maxn];
struct tree{
	int fa,wt;
}a[maxn][20];
bool cmp(node x,node y){
	return x.val>y.val;
}
void add(int u,int v,int w){
	edge_tree[++k].to=v,edge_tree[k].val=w,edge_tree[k].next=head[u],head[u]=k;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void dfs(int x){
	book[x]=true;
	for(int i=1;(1<<i)<=deep[x];i++)a[x][i].fa=a[a[x][i-1].fa][i-1].fa,a[x][i].wt=min(a[x][i-1].wt,a[a[x][i-1].fa][i-1].wt);
	for(int i=head[x];i;i=edge_tree[i].next)if(!book[edge_tree[i].to])deep[edge_tree[i].to]=deep[x]+1,a[edge_tree[i].to][0].fa=x,a[edge_tree[i].to][0].wt=edge_tree[i].val,dfs(edge_tree[i].to);
}
int LCA(int x,int y){
	if(find(x)!=find(y))return -1;
	if(deep[x]<deep[y])swap(x,y);
	int ans=0x3f3f3f3f,dep=deep[x]-deep[y];
	for(int i=0;(1<<i)<=dep;i++)if((1<<i)&dep)ans=min(ans,a[x][i].wt),x=a[x][i].fa;
	if(x==y)return ans;
	for(int i=19;i>=0;i--)if(a[x][i].fa!=a[y][i].fa)ans=min(ans,min(a[x][i].wt,a[y][i].wt)),x=a[x][i].fa,y=a[y][i].fa;
	return ans=min(ans,min(a[x][0].wt,a[y][0].wt));
}
int main(){
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u,&v,&w),edge[i].next=u,edge[i].to=v,edge[i].val=w;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(edge[i].next),fy=find(edge[i].to);
		if(fx!=fy)fa[fx]=fy,add(edge[i].next,edge[i].to,edge[i].val),add(edge[i].to,edge[i].next,edge[i].val);
	}
	scanf("%d",&q);
	for(int i=1;i<=n;i++)if(!book[i])deep[i]=1,a[i][0].fa=i,a[i][0].wt=0x3f3f3f3f,dfs(i);	
	for(int i=1;i<=q;i++)scanf("%d%d",&u,&v),printf("%d\n",LCA(u,v));
	return 0;
}
