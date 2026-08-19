#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,ans=0x7f7f7f7f,pos,min_dis;
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
int dfs(int x,int fa)
{
	int sum=0,Max=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		{
			int t=dfs(v,x);
			Max=max(Max,t);
			sum+=t;
		} 
	}
	Max=max(Max,n-sum-1);
	if(Max<ans)ans=Max,pos=x;
	else if(Max==ans&&x<pos)pos=x;
	return sum+1;
}
void Dfs(int x,int fa,int dis)
{
	int sum=0;
	min_dis+=dis;
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)Dfs(v,x,dis+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1),Dfs(pos,pos,0);
	printf("%d %d",pos,min_dis);
	return 0;
}
