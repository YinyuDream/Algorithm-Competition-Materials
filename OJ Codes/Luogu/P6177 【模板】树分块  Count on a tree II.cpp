#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e6+10;
int n,m,k,lastans;
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
void pre()
{
	int t=sqrt(n);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&val[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	pre();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		u^=lastans;
		lastans=find(u,v);
		printf("%d\n",lastans);
	}
	return 0;
}
