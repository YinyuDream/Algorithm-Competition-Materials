#include<cstdio>
using namespace std;

int n;

struct node
{
	int fa,l,r;
};
node nod[100];
int cnt;
void dfs(int k)
{
	
	if(nod[k].l>0)dfs(nod[k].l);
	printf("%d ",k);
	if(nod[k].r>0)dfs(nod[k].r);
}
int main()
{
	scanf("%d",&n);
	int a,b;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		nod[a].fa=b;
		if(nod[b].l==0)nod[b].l=a;
		else nod[b].r=a;
	}
	for(int i=1;i<=n;i++)
	{
		if(nod[i].fa==0)
		{
			dfs(i);
			return 0;
		}
	}
	return 0;
}
