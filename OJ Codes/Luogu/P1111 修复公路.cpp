#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m;
int fa[maxn],cnt,k[maxn];
struct node{
	int x,y,t;
}a[maxn];
bool cmp(node x,node y)
{
	return x.t<y.t;
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool check()
{
	int a=find(1);
	for(int i=2;i<=n;i++)
		if(find(i)!=a)return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i,k[i]=1;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy)continue;
		else
		{
			fa[fx]=fa[fy];
			if(check()){
				printf("%d",a[i].t);return 0;
			}
		}
	}
	printf("-1");
	return 0;
}
