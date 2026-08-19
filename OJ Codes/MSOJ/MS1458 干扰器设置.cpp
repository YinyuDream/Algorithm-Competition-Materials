#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,ans;
int a[maxn],p[maxn],v[maxn],head[maxn],f[maxn];
struct edge{
	int to,next;
}e[maxn];
struct node{
	int l,r,mx;
}tree[maxn];
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
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r)return ;
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void update(int id,int p,int c)
{
	if(tree[id].l==p&&tree[id].r==p){
		tree[id].mx=max(tree[id].mx,c);
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(p<=mid)update(id*2,p,c);
	else update(id*2+1,p,c);
	tree[id].mx=max(tree[id*2].mx,tree[id*2+1].mx); 
} 
int query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return tree[id].mx;
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return max(query(id*2,l,mid),query(id*2+1,mid+1,r));
}
int main(){
	//freopen("set.in","r",stdin);
	//freopen("set.out","w",stdout);
	n=read(),m=read();
	for(int i=1,x,y;i<=m;i++)
		x=read(),y=read(),add(x,y);
	build(1,1,n);
	for(int i=1;i<=n;i++)
		p[i]=read();
	for(int i=1;i<=n;i++)
		v[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=e[j].next)
			if(e[j].to!=1)f[e[j].to]=query(1,1,e[j].to-1)+v[i]+p[e[j].to];
			else f[e[j].to]=v[i]+p[e[j].to];
		for(int j=head[i];j;j=e[j].next)
			update(1,e[j].to,f[e[j].to]),ans=max(ans,f[e[j].to]);
	}
	printf("%d",ans);
	return 0;
}