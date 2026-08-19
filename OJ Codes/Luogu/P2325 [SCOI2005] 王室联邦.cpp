#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,b,cnt,num,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],root[maxn],block[maxn],st[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	int now=num;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			dfs(v,u);
			if(num-now>=b)
			{
				root[++cnt]=u;
				while(num>now)
				block[st[num--]]=cnt;
			}
		}
	}
	st[++num]=u;
}
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	while(num)block[st[num--]]=cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
	printf("%d ",block[i]);
	puts("");
	for(int i=1;i<=cnt;i++)
	printf("%d ",root[i]);
	return 0;
}
