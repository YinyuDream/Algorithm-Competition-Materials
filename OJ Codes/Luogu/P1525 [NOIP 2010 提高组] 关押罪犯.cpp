#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int n,m;
int fa[maxn],empty[maxn];
struct node{
	int x,y,val;
}a[maxn];
bool cmp(node a,node b)
{
	return a.val>b.val;
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].val);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy)
		{
			printf("%d",a[i].val);
			return 0;
		}
		if(!empty[a[i].x])empty[a[i].x]=a[i].y;
		else fa[find(empty[a[i].x])]=find(a[i].y);
		if(!empty[a[i].y])empty[a[i].y]=a[i].x;
		else fa[find(empty[a[i].y])]=find(a[i].x);
	}
	printf("0");
	return 0;
}
