#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn=1000010;
int n,k,a[maxn],b[maxn],bo[maxn];
void dfs(int x)
{
	if(x==n+1)
	{
		if(bo[0]==1)
		{
			for(int i=1;i<=n;i++)
				printf("%d ",b[i]);
				exit(0);
		}
		bo[0]=1;
	}
	for(int i=bo[0]==0?a[x]:1;i<=n;i++)
	{
		if(bo[i]==0)
		{
			bo[i]=1;
			b[x]=i;
			dfs(x+1);
			bo[i]=0;
			b[x]=0;
		}
	}
}
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%d ",i);
	return 0;
}
