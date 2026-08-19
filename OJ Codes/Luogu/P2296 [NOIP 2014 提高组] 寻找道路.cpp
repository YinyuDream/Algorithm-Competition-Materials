#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,s,t,k1,k2;
struct node{
	int to,next;
}edge1[maxn],edge2[maxn];
int head1[maxn],head2[maxn];
void add(int u,int v,int opt)
{
	if(opt==1)
	edge1[++k1].to=v,
	edge1[k1].next=head1[u],
	head1[u]=k1;
	else
	edge2[++k2].to=v,
	edge2[k2].next=head2[u],
	head2[u]=k2;
}
int book[maxn];
void dfs(int u)
{
	book[u]=1;
	for(int i=head2[u];i;i=edge2[i].next)
	{
		int v=edge2[i].to;
		if(book[v]==0)
		dfs(v);
	}
}
struct node2{
	int id,dis;
	node2(){}
	node2(int Id,int Dis){id=Id,dis=Dis;}
	bool operator<(const node2 &a)const {
		return dis<a.dis;
	}
};
queue<pair<int,int> >q;
int dis[maxn],flag[maxn];
int bfs(int s,int t)
{
	if(book[s]==0)return -1;
	q.push(make_pair(s,0));
	flag[s]=1;
	while(q.size())
	{
		pair<int,int>u=q.front();
		q.pop();
		if(u.first==t)return u.second;
		for(int i=head1[u.first];i;i=edge1[i].next)
		{
			int v=edge1[i].to;
			if(book[v]&&!flag[v])
			q.push(make_pair(v,u.second+1)),flag[v]=1;
		}
	}
	return -1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(u==v)continue;
		add(u,v,1);
		add(v,u,2);
	}
	scanf("%d%d",&s,&t);
	dfs(t);
	for(int i=1;i<=n;i++)
	if(book[i]==0)
		for(int j=head2[i];j;j=edge2[j].next)
			flag[edge2[j].to]=1;
	printf("%d",bfs(s,t));
	return 0;
}
