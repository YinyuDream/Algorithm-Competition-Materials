#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e6+10;
int n,m,p,k;
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
queue<int>q;
int book[maxn],dis[maxn];
void bfs(int s)
{
	q.push(s);
	book[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!book[v]){
				book[v]=1;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1,a,b,c,d;i<=m;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int j=a;j<=b;j++)
			for(int k=c;k<=d;k++)
				if(j!=k)
					add(j,k),add(k,j);
	}
	bfs(p);
	for(int i=1;i<=n;i++)
		printf("%d\n",dis[i]);
	return 0;
}
