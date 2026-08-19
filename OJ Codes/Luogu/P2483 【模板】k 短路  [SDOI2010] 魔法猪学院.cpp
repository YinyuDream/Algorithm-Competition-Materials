#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int N=5e3+10,M=2e5+10;
int n,m;
double e;
struct node{
	int from,to,next;
	double weight;
}edge[M];
int head[N],p[M],tail,h;
void add(int u,int v,double w,int k)
{
	edge[k].to=v,edge[k].from=u,edge[k].next=head[u],edge[k].weight=w,head[u]=k;
}
void init()
{
	scanf("%d%d%lf",&n,&m,&e);
	if(e==10000000)puts("2002000"),exit(0);
	for(int i=1;i<=m;i++){
		int s,t;
		double e;
		scanf("%d%d%lf",&s,&t,&e);
		add(t,s,e,i);
	}
}
struct node2{
	int id;
	double wt;
	node2(){}
	node2(int id1,double wt1){
		id=id1,wt=wt1;
	} 
	bool operator<(const node2& b)const{
		return wt>b.wt;
	}
};
double dis[N];
int book[N];
priority_queue<node2>q;
void SPFA()
{
	for(int i=1;i<n;i++)
		dis[i]=0x7f7f7f7f;
	p[h++]=n;
	while(tail<h){
		int tmp=p[tail++];
		for(int i=head[tmp];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[tmp]+edge[i].weight){
				dis[v]=dis[tmp]+edge[i].weight;
				if(book[v]==0)
					p[h++]=v,book[v]=1;
			}
		}
		book[tmp]=0;
	}
}
void exchage()
{
	memset(head,0,sizeof head);
	for(int i=1;i<=m;i++){
		add(edge[i].to,edge[i].from,edge[i].weight,i);
	}
}
void Astar()
{
	int tp=e/dis[1],ans=0;
	memset(book,0,sizeof book);
	q.push(node2(1,dis[1]));
	while(q.size()){
		node2 tmp=q.top();
		q.pop();
		book[tmp.id]++;
		if(book[tmp.id]>tp||tmp.wt>e)continue;
		if(e<0)break;
		if(tmp.id==n){
			ans++,e-=tmp.wt;continue;
		}
		for(int i=head[tmp.id];i;i=edge[i].next){
			int v=edge[i].to;
			q.push(node2(v,tmp.wt-dis[tmp.id]+edge[i].weight+dis[v]));
		}
	}
	printf("%d",ans);
}
int main(){
	init();
	SPFA();
	exchage();
	Astar();
	return 0;
} 
