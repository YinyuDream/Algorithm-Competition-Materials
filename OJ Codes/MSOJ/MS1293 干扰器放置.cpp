#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,ans;
int a[maxn],p[maxn],v[maxn],head[maxn],f[maxn],tree[maxn];
struct edge{
	int to,next;
}e[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'|ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,
	ch=getchar();
	return x;
}
void add(int u,int v)
{
	e[++k].to=v;
	e[k].next=head[u];
	head[u]=k;
}
void update(int x,int val)
{
	for(int i=x;i<=n;i+=i&(-i))
		tree[i]=max(tree[i],val);
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=i&(-i))
		ans=max(ans,tree[i]);
	return ans;
}
int main(){
	//freopen("set.in","r",stdin);
	//freopen("set.out","w",stdout);
	n=read(),m=read();
	for(int i=1,x,y;i<=m;i++)
		x=read(),y=read(),add(x,y);
	for(int i=1;i<=n;i++)
		p[i]=read();
	for(int i=1;i<=n;i++)
		v[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=e[j].next)
			if(e[j].to!=1)f[e[j].to]=query(e[j].to-1)+v[i]+p[e[j].to];
			else f[e[j].to]=v[i]+p[e[j].to];
		for(int j=head[i];j;j=e[j].next)
			update(e[j].to,f[e[j].to]),ans=max(ans,f[e[j].to]);
	}
	printf("%d",ans);
	return 0;
}