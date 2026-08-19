#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,tp,lt,rt,md,md2,num,len,max_dis;
int head[maxn],dis[maxn];
struct node{
	int to,next;
}edge[maxn];
void add(int u,int v){
	edge[++num].to=v;
	edge[num].next=head[u];
	head[u]=num;
}
bool book[maxn],is_2;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs1(int x,int u){
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!book[v]&&v!=x){
			book[v]=1;
			dis[v]=dis[u]+1;
			dfs1(u,v);
		}
	}
}
int pre[maxn];
void dfs2(int x,int u){
	pre[u]=x;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!book[v]&&v!=x){
			book[v]=1;
			dis[v]=dis[u]+1;
			dfs2(u,v);
		}
	}
}
int dist[maxn];
int dfs3(int u,int pre)
{
	int mx=0;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=pre&&!book[v]){
			book[v]=1;
			mx=max(mx,dfs3(v,u));
		}
	}
	return dist[u]=mx+1;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	memset(dis,0x7f,sizeof dis);
	dis[1]=0,book[1]=1,dfs1(1,1);
	lt=rt=1;
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[lt])
			lt=i;
	memset(dis,0x7f,sizeof dis);
	memset(book,0,sizeof book);
	dis[lt]=0,book[lt]=1,dfs2(lt,lt);
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[rt])
			rt=i;
	md=rt,len=dis[rt];
	while(max(dis[md],len-dis[md])>max(dis[pre[md]],len-dis[pre[md]]))
		md=pre[md];
	if(max(dis[md],len-dis[md])==max(dis[pre[md]],len-dis[pre[md]]))
		is_2=true,md2=pre[md];
	memset(book,0,sizeof book);
	book[md]=1;
	if(is_2)book[md2]=1;
	dist[md]=dfs3(md,md);
	if(is_2)dist[md2]=dfs3(md2,md2);
	sort(dist+1,dist+n+1,cmp);
	printf("%d\n",dist[k+1]);
	return 0;
}