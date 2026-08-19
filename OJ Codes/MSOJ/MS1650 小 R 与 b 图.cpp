#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e3+10,inf=0x3f3f3f3f;
int n,m,k,ans,mx;
int w[maxn];
struct node{
	int to,next,op;
}edge[maxn];
int head[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	x=x*10+ch-48,ch=getchar();
	return x;
}
void add(int u,int v,int op)
{
	edge[k].to=v;
	edge[k].next=head[u];
	edge[k].op=op;
	head[u]=k++;
}
int dis[maxn][maxn],flag[maxn],book[maxn];
priority_queue<pii>q;
void dij(int s)
{
	memset(book,0,sizeof book);
	q.push(make_pair(-w[s],s));
	dis[s][s]=w[s];
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(!book[v]&&!flag[i]){
				int d=edge[i].op?(20*dis[s][u]+19)/19:dis[s][u]+1;
				if(dis[s][v]>d){
					if(edge[i].op)
						while(d-1-(d-2)/20-1>=dis[s][u])
							d--;
					dis[s][v]=d;
					q.push(make_pair(-dis[s][v],v));
				}
			}
		}
	}
}
int work(int cur)
{
	memset(dis,0x3f,sizeof dis);
	flag[cur]=flag[cur^1]=1;
	for(int i=1;i<=n;i++)
		dij(i);
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]!=inf){
				sum+=dis[i][j];
			}else{
				flag[cur]=flag[cur^1]=0;
				return -1;
			}
		}
	}
	flag[cur]=flag[cur^1]=0;		
	return sum;
}
int main(){
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	memset(head,-1,sizeof head);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		w[i]=read();
	for(int i=1,u,v,op;i<=m;i++){
		u=read(),v=read(),op=read();
		add(u,v,op);
		add(v,u,op);
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
		dij(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans+=dis[i][j];
	for(int i=1;i<=m;i++)
		mx=max(mx,work((i-1)*2));
	printf("%d %d",ans,mx);
	return 0;
}