#include<cstdio>
using namespace std;
const int maxn=5010;
int n,m,p,a,b;
int fa[maxn];
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void hebing(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		hebing(a,b);
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);
		if(find(a)==find(b))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
