#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=1e5+10;
int n,m,k,qp,l=0,r=1e7;
struct point{
	int to,next,wt;
}edge[maxn];
struct node{
	int id,wt;
	node(int _id,int _wt){
		id=_id,wt=_wt;
	}
	friend bool operator<(node a,node b)
	{
		return a.wt>b.wt;
	}
};
int head[maxn],dis[maxn],book[maxn];
void add(int u,int v,int w)
{
	edge[++k]={v,head[u],w};
	head[u]=k;
}
bool check(int len)
{
	priority_queue<node>q;
	memset(book,0,sizeof book);
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;q.push(node(1,0));
	while(q.size())
	{
		int p=q.top().id;q.pop();
		if(book[p])continue;
		book[p]=1;
		for(int i=head[p];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dis[v]>dis[p]+(edge[i].wt>len?1:0))
			{
				dis[v]=dis[p]+(edge[i].wt>len?1:0);
				q.push(node(v,dis[v]));
			}
		}
	}
	return dis[n]<=qp;
}
int main(){
	scanf("%d%d%d",&n,&m,&qp);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
		if(dis[n]==0x3f3f3f3f){
			puts("-1");
			return 0;
		}
	}
	printf("%d",l);
	return 0;
}
