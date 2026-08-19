/*tarjan lca
问题：给定n个点，n-1条边，q个询问x--y之间的最近公共祖先，根据询问一一输出答案
样例：
5 5
1 2
2 3
2 4
1 5
1 5
3 5
3 4
2 5
4 5  
*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005;
const int maxq=10005; 
struct node
{
	int to,next;
};
struct qnode
{
	int id,to,next,ans;
}qedge[maxq*2];//q个查询 
node edge[maxn+5];
int head[maxn];
int qhead[maxn];
int fa[maxn];
int n,q,k=0;
int father[maxn]; 
bool visit[maxn];
int u,v;
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void addq(int id,int u,int v)
{
	qedge[++k].id=id;//记录第几个查询
	qedge[k].to=v;
	qedge[k].ans=0;
	qedge[k].next=qhead[u];
	qhead[u]=k;
}
void read_data()
{
	memset(fa,0,sizeof(fa));
	memset(edge,0,sizeof(edge));
	//memset(qedge,0,sizeof(qedge));
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		fa[v]=u;
		add(u,v);
	}
	k=0;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		//printf("%d %d %d\n",i,x,y);
		addq(i,x,y);
		addq(i,y,x); 
	}
}
int find(int x)
{
	return father[x]==x?x:father[x]=find(father[x]);
}
bool compare(qnode p1,qnode p2)
{
	return p1.id<p2.id;
}
void tarjan(int x)
{
	father[x]=x;
	for(int i=head[x];i>0;i=edge[i].next)
	{
		if(!visit[edge[i].to])
		{
			visit[edge[i].to]=true;
			tarjan(edge[i].to);
			father[edge[i].to]=x;
		}
	}
	for(int i=qhead[x];i>0;i=qedge[i].next)//枚举与x相关的查询 
	{
		if(visit[qedge[i].to])//如果这个点被访问过 
		{
			qedge[i].ans=find(qedge[i].to);//原来访问过节点的顶级容器 
			//printf("%d,%d--%d\n",x,qedge[i].to,qedge[i].ans);
		}
	}
}
void work()
{
	memset(visit,false,sizeof(visit));
	for(int i=1;i<=n;i++) if(fa[i]==0) tarjan(i);//从根开始做
	sort(qedge+1,qedge+2*q+1,compare);
	for(int i=1;i<=2*q;i+=2)
	{
		if(qedge[i].ans!=0)
			printf("%d:%d---%d\n",qedge[i].id,qedge[i].to,qedge[i].ans);
		else
			printf("%d:%d---%d\n",qedge[i+1].id,qedge[i+1].to,qedge[i+1].ans);
	}
}
int main()
{
	read_data();
	work();
	system("pause");
	return 0;
} 
