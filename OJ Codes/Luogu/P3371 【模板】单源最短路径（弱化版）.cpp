#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,s,k;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],dis[maxn],book[maxn];
queue<int>q;
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
int main(){
	memset(dis,0x3f,sizeof dis);
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1,u,v,w;i<=m;i++)
	scanf("%d%d%d",&u,&v,&w),add(u,v,w);
	dis[s]=0;
	q.push(s);
	book[s]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		book[u]=0;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				if(book[v]==0){
					q.push(v);
					book[v]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]!=0x3f3f3f3f?dis[i]:0x7fffffff);
	return 0;
}
