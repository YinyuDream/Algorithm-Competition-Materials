#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn=1e4+10;
const db eps=1e-10;
int n,m,k;
db l,r;
struct node{
	int to,next;
	db wt;
}edge[maxn];
int head[maxn];
void add(int u,int v,db w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
int book[maxn];
db dis[maxn];
bool spfa(int u,db x)
{
	book[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(dis[v]>dis[u]+edge[i].wt-x){
			dis[v]=dis[u]+edge[i].wt-x;
			if(book[v]||spfa(v,x))return true;
		}
	}
	book[u]=0;
	return false;
}
bool check(db x)
{
	memset(book,0,sizeof book);
	for(int i=1;i<=n;i++)
		dis[i]=0;
	for(int i=1;i<=n;i++)
		if(spfa(i,x))
			return true;
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		db w;
		scanf("%d%d%lf",&u,&v,&w);
		add(u,v,w);
	}
	r=1e7,l=-1e7;
	while(r-l>=eps){
		db mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.8f",l);
	return 0;
}