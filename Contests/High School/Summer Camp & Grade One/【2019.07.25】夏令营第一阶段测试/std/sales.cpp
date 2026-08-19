#include<cstdio>
using namespace std;

int n,mapp[30][30],book[30];
int ans=0x7f7f7f7f;

void dfs(int k,int num,int s)
{
	if(num==n)
	{
		if(s+mapp[k][1]<ans)ans=s+mapp[k][1];
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(mapp[k][i]>0 && book[i]==0)
		{
			if(s+(n-num)+1>ans)continue;
			book[i]=1;
			dfs(i,num+1,s+mapp[k][i]);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("sales.in","r",stdin);
	freopen("sales.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		scanf("%d",&mapp[i][j]);
	}
	book[1]=1;
	dfs(1,1,0);
	printf("%d\n",ans);
	return 0;
 } 
