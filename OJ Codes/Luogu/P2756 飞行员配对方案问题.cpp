#include<cstdio>
using namespace std;
const int maxn=500;
int n,m,k,a;
int edge[maxn][maxn],use[maxn],result[maxn];
bool dfs(int x)
{
	for(int i=m+1;i<=n;i++)
	{
		if(edge[x][i]&&use[i]!=a)
		{
			use[i]=a;
			if(!result[i]||dfs(result[i]))
			{
				result[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&m,&n);
	while(1){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==-1&&b==-1)break;
		edge[a][b]=1;
	}
	for(int i=1;i<=m;i++)
	{
		a++;
		if(dfs(i))k++;
	}
	printf("%d\n",k);
	for(int i=m+1;i<=n;i++)
		if(result[i])
			printf("%d %d\n",result[i],i);
	return 0;
}
