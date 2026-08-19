#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50;
int n,m,cnt_edge,t;
int a1,a2,a3,b1,b2,b3,ans=0x7f7f7f7f;
int a[maxn][maxn],b[maxn][maxn];
struct node{
	int to,next,wt;
}edge[maxn*maxn*maxn*maxn];
int head[maxn*maxn];
void add(int u,int v,int w)
{
	edge[++cnt_edge].to=v;
	edge[cnt_edge].next=head[u];
	edge[cnt_edge].wt=w;
	head[u]=cnt_edge;
}
int book[maxn*maxn],dis0[maxn*maxn],dis1[maxn*maxn],dis2[maxn*maxn];
priority_queue<pair<int,int> >q;
void dij(int s,int d[])
{
	memset(book,0,sizeof book);
	for(int i=1;i<=n*m;i++)
		d[i]=0x3f3f3f3f;
	d[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!book[v]&&d[v]>d[u]+edge[i].wt){
				
				d[v]=d[u]+edge[i].wt;
				q.push(make_pair(-d[v],v));
			}
		}
	}
}
int main(){
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=n;k++)
				for(int l=1;l<=m;l++)
					if(abs(k-i)+abs(l-j)<=b[i][j])
						add((i-1)*m+j,(k-1)*m+l,a[i][j]);
	scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3);
	dij((a1-1)*m+b1,dis0);
	dij((a2-1)*m+b2,dis1);
	dij((a3-1)*m+b3,dis2);
	if(ans>dis1[(a1-1)*m+b1]+dis2[(a1-1)*m+b1])
		ans=dis1[(a1-1)*m+b1]+dis2[(a1-1)*m+b1],t=0;
	if(ans>dis0[(a2-1)*m+b2]+dis2[(a2-1)*m+b2])
		ans=dis1[(a1-1)*m+b1]+dis2[(a1-1)*m+b1],t=1;
	if(ans>dis0[(a3-1)*m+b3]+dis1[(a3-1)*m+b3])
		ans=dis0[(a3-1)*m+b3]+dis1[(a3-1)*m+b3],t=2;
	if(t==0)puts("X");
	else if(t==1)puts("Y");
	else puts("Z");
	printf("%d",ans);
	return 0;
}
