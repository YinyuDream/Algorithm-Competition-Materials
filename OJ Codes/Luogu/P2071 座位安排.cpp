#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int n,cnt,k,a;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
int result[maxn],use[maxn];
bool dfs(int x)
{
	for(int j=head[x];j;j=edge[j].next)
	{
		int i=edge[j].to;
		if(use[i]!=a)
		{
			use[i]=a;
			if(!result[i]||dfs(result[i]))
			{
				result[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(i,u);add(i,v);add(i,u+n);add(i,v+n);
	}
	for(int i=1;i<=n*2;i++)
	{
		a++;
		if(dfs(i))cnt++;
	}
	printf("%d",cnt);
	return 0;
}
