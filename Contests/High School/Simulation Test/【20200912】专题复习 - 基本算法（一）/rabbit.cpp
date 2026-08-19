#include<cstdio>
#include<algorithm>
#pragma GCC optimize(3)
using namespace std;
const int maxn=2e6+10;
int n,m,k,t,ans;
int c[maxn],size[maxn];
int a[maxn];
struct node{
	int to,next;
}edge[maxn];
bool cmp(int x,int y)
{
	return c[x]+size[x]>c[y]+size[y];
}
int head[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	x=x*10+ch-48,ch=getchar();
	return x;
}
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u)
{
	for(int i=head[u];i;i=edge[i].next)
		dfs(edge[i].to);
	
	int tot=0;
	for(int i=head[u];i;i=edge[i].next)
	a[++tot]=edge[i].to;
	sort(a+1,a+tot+1,cmp);
	while(tot&&c[u]+size[u]+c[a[tot]]+size[a[tot]]-1<=m)
		ans++,c[u]+=c[a[tot]],size[u]+=size[a[tot]]-1,tot--;
}
int main(){
	//freopen("rabbit.in","r",stdin);
	//freoepn("rabbit.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<n;i++)
		c[i]=read();
	for(int i=0;i<n;i++)
	{
		size[i]=read();
		for(int j=1;j<=size[i];j++)
		add(i,read());
	}
	dfs(0);
	printf("%d",ans);
	return 0;
}
