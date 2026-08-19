#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=50000;
int n,m,ans,k;
struct Node{
	int w,id;
}a[maxn];
int head[maxn],head2[maxn];
struct node{
	int to,next,w;
}edge[maxn],tree[maxn];
int fa[maxn],v[maxn];
bool cmp(Node x,Node y)
{
	return x.w>y.w;
}
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].w=w;
	head[u]=k;
}
int main()
{
	freopen("chris.in","r",stdin);
	freopen("chris.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].w),a[i].id=i,fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	sort(a+1,a+n+1,cmp);
	return 0;
}
