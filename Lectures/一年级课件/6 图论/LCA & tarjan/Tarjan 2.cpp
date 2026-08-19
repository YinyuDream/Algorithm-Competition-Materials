/*tarjan：求强连通分量，tarjan算法 
描述：n个点，m条有向边，求出图中所有的强连通分量 
参考
输入样例：
6 8
1 3
1 2
4 1
3 4
2 4
3 5
4 6
5 6
输出样例
6
5
1 2 3 4 
3
*/ 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=100000;
const int maxm=1000000;
int m,n;
int k=0;
int head[maxn];
struct node{
	int to,next;
}e[maxm+10];
bool visit[maxn],instack[maxn];
int dfn[maxn],low[maxn];
stack<int> s;
int total=0; 
void add(int u,int v)
{
	e[++k].to=v;
	e[k].next=head[u];
	head[u]=k;
}
void read_data()
{
	int u,v;
	scanf("%d%d",&n,&m);
	memset(head,0,sizeof(head));
	memset(e,0,sizeof(e));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	memset(visit,false,sizeof(visit));
	memset(instack,false,sizeof(instack));
}
void tarjan(int x)
{
	dfn[x]=low[x]=++k;
	s.push(x);
	visit[x]=true;
	instack[x]=true;
	for(int i=head[x];i>0;i=e[i].next)
	{
		if(!visit[e[i].to])//判断e[i].to点是否访问过 
		{
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if(instack[e[i].to])//判断点e[i].to是否在栈中 
		{
			low[x]=min(low[x],dfn[e[i].to]); 
		}
	}
	//printf("%d %d %d\n",x,dfn[x],low[x]);
	if(dfn[x]==low[x])//找到一个强连通分量 
	{
		total++;
		int v=0;
		while(v!=x)
		{
			v=s.top();
			printf("%d ",v);
			s.pop();
			instack[v]=false;
		}
		printf("\n");
	}
} 
int main()
{
	read_data();//数据读入
	for(int i=1;i<=n;i++)//求解非联通模块的强连通分量 
	{
		if(!visit[i])
		{
			k=0;
			tarjan(i);
		}
	} 
	//tarjan(1); 
	printf("%d\n",total);
} 
