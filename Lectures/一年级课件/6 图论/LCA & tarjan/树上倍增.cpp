/*树上倍增的思想
就是通过RMQ的思想，能够快速遍历到i点的祖先。
用ancestor[i][j]表示i点的第2^j个祖先，快速实现上层祖先的查找，转移方程：
ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1]
解决问题：NOIP 2013 day1-3，给定n个点,n-1条边，每条边上有一个权值，不停询问u-v路径上的最小权值
解决方法：如何快速遍历u到v上的点，并且找出最小值，所以加一个
dp_min[i][j]表示从i点到第2^j个祖先的最小值，转移方程：
dp_min[i][j]=min(dp[i][j-1],dp[ancestor[i][j-1]][j-1]) 
测试样例
8 7 6
1 2 5
1 3 1
1 8 6
2 4 4
2 5 2
4 6 3
3 7 9 
6 8
5 7
4 7
4 8
6 2
5 3
样例输出
3
1
1
4
3
1
*/ 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=30000+10;
const int maxm=30000+10;
const int maxl=17;
int n,m,q;
int head[maxn];
int k=0;
struct node
{
	int to,w,next;
} edge[maxm*2];
bool visit[maxn];
int fa[maxn][maxl],dp_min[maxn][maxl];
int deep[maxn];//deep[i]表示i点的深度 
void add(int u,int v,int w)
{
	edge[++k].w=w;
	edge[k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void read_data()
{
	int u,v,w;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	memset(visit,0,sizeof(visit));
	memset(dp_min,0x7f7f7f7f,sizeof(dp_min));
	memset(fa,0,sizeof(fa)); 
}
void dfs(int x)
{
	visit[x]=true;
	for(int i=1;(1<<i)<=deep[x];i++)//这里在完成x点到它上层祖先点的预处理 
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
		dp_min[x][i]=min(dp_min[x][i-1],dp_min[fa[x][i-1]][i-1]);
	} 
	for(int i=head[x];i>0;i=edge[i].next)
	{
		if(!visit[edge[i].to])
		{
			fa[edge[i].to][0]=x;
			dp_min[edge[i].to][0]=edge[i].w;
			deep[edge[i].to]=deep[x]+1;
			dfs(edge[i].to);
		}
	}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y]) swap(x,y);
	int t=deep[x]-deep[y];//计算深度差 
	for(int i=0;(1<<i)<=t;i++) if(t&(1<<i)) x=fa[x][i];//深度差调整到同一高度 
	if(x==y) return x;//x和y在一条链上 
	for(int i=17;i>=0;i--)//向上枚举找最近公共祖先，从根开始向下，思考为什么？ 
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}
int ask(int x,int f)
{
	int mm=0x7f7f7f;
	int t=deep[x]-deep[f];
	for(int i=0;(1<<i)<=t;i++)
	{
		if(t&(1<<i))
		{
			mm=min(mm,dp_min[x][i]);
			x=fa[x][i];
		}
	}
	return mm;
} 
int main()
{
	read_data();
	for(int i=1;i<=n;i++) if(!visit[i]) dfs(i);
	int  x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		int t=lca(x,y);
		printf("%d",min(ask(x,t),ask(y,t)));
	}
	return 0;
}

