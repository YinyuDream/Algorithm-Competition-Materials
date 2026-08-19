#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,t,k;
int fa[maxn],num[maxn*2],help[maxn*2];
struct node{
	int u,v,w;
}a[maxn];
pair<int,int>p[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void lsh()
{
	for(int i=1;i<=n;i++)
	num[i*2-1]=a[i].u,num[i*2]=a[i].v;
	for(int i=1;i<=n*2;i++)
	help[i]=num[i];
	sort(help+1,help+2*n+1);
	int cnt=unique(help+1,help+n*2+1)-help-1;
	for(int i=1;i<=n*2;i++)
	num[i]=lower_bound(help+1,help+cnt+1,num[i])-help;
	for(int i=1;i<=n;i++)
	a[i].u=num[i*2-1],a[i].v=num[i*2];
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n*2;j++)
			fa[j]=j;
		k=0;
		for(int j=1;j<=n;j++)
			scanf("%d%d%d",&a[j].u,&a[j].v,&a[j].w);
		lsh();
		for(int j=1;j<=n;j++)
		{
			int u=a[j].u,v=a[j].v;
			if(a[j].w==1)
			{
				int fx=find(u),fy=find(v);
				if(fx!=fy)
				fa[fx]=fy;
			}
			else 
			p[++k]=make_pair(u,v);
		}
		bool book=0;
		for(int j=1;j<=k;j++)
		{
			int u=p[j].first,v=p[j].second;
			if(find(u)==find(v))
			{
				puts("NO");
				book=1;
				break;
			}
		}
		if(!book)
		puts("YES");
	}
	return 0;
}
