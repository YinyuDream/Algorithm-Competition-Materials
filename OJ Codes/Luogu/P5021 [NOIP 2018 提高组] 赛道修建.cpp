#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,l,r;
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
int dfs(int u,int f)
{
	]for
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		add(u,v,w);
		add(v,u,w);
		r+=w;
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
