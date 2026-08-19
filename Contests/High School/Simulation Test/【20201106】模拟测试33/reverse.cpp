#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,k,m,s,d;
int book[maxn];
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
int dis[maxn];
void bfs()
{
	queue<int>q;
	memset(dis,-1,sizeof dis);
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("reverse.in","r",stdin);
	freopen("reverse.out","w",stdout);
	scanf("%d%d%d%d",&n,&d,&m,&s);
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		book[x]=1;
	}
	for(int i=1;i<=n-d+1;i++)
		for(int j=i;j<=i+d-1;j++)
			if(!book[j]&&!book[2*i+d-j-1])
				add(j,2*i+d-j-1);
	bfs();
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
}
