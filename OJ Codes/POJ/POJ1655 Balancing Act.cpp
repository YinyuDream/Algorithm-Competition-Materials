#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,ans=0x7f7f7f7f,pos;
int t;
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
int Dfs(int x,int fa)
{
	int cnt=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)cnt+=Dfs(v,x);
	}
	return cnt+1;
}
void solve()
{
	pos=0,ans=0x7f7f7f7f,k=0;
	memset(head,0,sizeof head);
	memset(edge,0,sizeof edge); 
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	int max_cnt=0;
	for(int i=head[pos];i;i=edge[i].next){
		max_cnt=max(max_cnt,Dfs(edge[i].to,pos));
	}
	printf("%d %d\n",pos,max_cnt);
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}