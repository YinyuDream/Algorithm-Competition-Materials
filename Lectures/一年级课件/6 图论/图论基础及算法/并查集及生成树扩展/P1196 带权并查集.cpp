#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=30000+10;
int fa[maxn];
int d[maxn];
int size[maxn];
int find(int x)
{
	if(x==fa[x]) return x;
	int root=find(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=root;
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;d[x]=size[y];
	size[y]+=size[x];
}
int main()
{
	//freopen("P1196.in","r",stdin);
	//freopen("P1196.out","w",stdout);
	int n;
	for(int i=1;i<=30000;i++) {fa[i]=i;size[i]=1;}
	scanf("%d",&n);getchar();
	for(int i=1;i<=n;i++)
	{
		char opt;
		int x,y;
		scanf(" %c ",&opt);
		scanf("%d%d",&x,&y);
		if(opt=='M') merge(x,y);
		else
		{
			int fx=find(x),fy=find(y);
			if(fx!=fy) printf("-1\n");
			else
			{
				//printf("%d %d\n",d[x],d[y]);
				printf("%d\n",abs(d[x]-d[y])-1);
			}
		}
		getchar();
	}
	return 0;;
}
