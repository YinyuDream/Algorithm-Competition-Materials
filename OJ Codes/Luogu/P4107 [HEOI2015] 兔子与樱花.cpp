#include<cstdio>
#include<queue>
using namespace std;
const int maxn=2e6+10;
int n,m,k,t,ans;
int c[maxn],size[maxn];
struct node{
	int to,next;
}edge[maxn];
struct point{
	int ci,s;
	point(int _ci,int _s){
		ci=_ci;s=_s;
	}
	friend bool operator<(point a,point b){
		return a.ci+a.s>b.ci+b.s;
	}
};
priority_queue<point>q;
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u)
{
	for(int i=head[u];i;i=edge[i].next)
		dfs(edge[i].to);
	while(q.size())q.pop();
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		q.push(point(c[v],size[v]));
	}
	while(q.size()&&c[u]+size[u]+q.top().ci+q.top().s-1<=m)
		ans++,c[u]+=q.top().ci,size[u]+=q.top().s-1,q.pop();
}
int main(){
	//freopen("rabbit.in","r",stdin);
	//freoepn("rabbit.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	for(int i=0;i<n;i++)
	{
		int son;
		scanf("%d",&size[i]);
		for(int j=1;j<=size[i];j++)
		scanf("%d",&son),
		add(i,son);
	}
	dfs(0);
	printf("%d",ans);
	return 0;
}