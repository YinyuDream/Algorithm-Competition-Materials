#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int n,k1,k2,m;
int head1[maxn],head2[maxn],cnt[maxn];
struct node{
	int to,next;
}edge1[maxn*5],edge2[maxn*5];
void add1(int x,int y)
{
	edge1[++k1].to=y,
	edge1[k1].next=head1[x],
	head1[x]=k1;
}
void add2(int x,int y)
{
	edge2[++k2].to=y,
	edge2[k2].next=head2[x],
	head2[x]=k2;
}
stack<int>s;
int id,bo[maxn],sum[maxn];
void dfs1(int x)
{
	bo[x]=1;
	for(int i=head1[x];i>0;i=edge1[i].next)
		if(bo[edge1[i].to]==0)
			dfs1(edge1[i].to);
	s.push(x);
}
void dfs2(int x)
{
	bo[x]=id,sum[id]++;
	for(int i=head2[x];i>0;i=edge2[i].next)
		if(bo[edge2[i].to]==0)
			dfs2(edge2[i].to);
}
int main()
{
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),add1(u,v),add2(v,u);
	for(int i=1;i<=n;i++)
		if(bo[i]==0)
			dfs1(i);
	memset(bo,0,sizeof(bo));
	while(s.size())
	{
		if(bo[s.top()]==0)
		{
			id++;
			dfs2(s.top());
		}
		s.pop();
	}
	for(int i=1;i<=n;i++)
		for(int j=head1[i];j>0;j=edge1[j].next)
			if(bo[i]!=bo[edge1[j].to])
				cnt[bo[i]]++;
	int q=0,ans=0;
	for(int i=1;i<=id;i++)
		if(cnt[i]==0)
			{
				ans=sum[i],q++;
				if(q==2)
				{
					printf("0");
					return 0;
				}
			}
	printf("%d",ans);
	return 0;
}
