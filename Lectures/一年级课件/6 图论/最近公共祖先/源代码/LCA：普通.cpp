#include<cstdio>
using namespace std;

int a,b,n;
int x,y;
int fa[100],h[100];
void dfs(int k)
{
	if(fa[k]==0)
	{
		h[k]=1;
		return;
	}
	if(h[k]>0)return;
	dfs(fa[k]);
	h[k]=h[fa[k]]+1;
}
int main()
{
	scanf("%d",&n);
	scanf("%d%d",&x,&y);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		fa[a]=b;	
	}
	dfs(x);
	dfs(y);
	while(h[x]>h[y])
	{
		x=fa[x];
	}
	while(h[y]>h[x])
	{
		y=fa[y];
	}
	while(x!=y)
	{
		x=fa[x];y=fa[y];
	}
	printf("%d",x);
	return 0;
} 
