#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt;
int x[15];
bool a[15];//列标记
bool b[30];//对角线y=x标记 
bool c[30];//对角线y=-x标记
int ans[100000][15]; 
void dfs(int k)
{
	if(k==n+1)
	{
		cnt++;
		for(int j=1;j<=n;j++)ans[cnt][j]=x[j];
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0&&b[k+i-1]==0&&c[k-i+n]==0)//可以放 
			{
				x[k]=i;
				a[i]=1;//第i列不能再放；
				b[k+i-1]=1; //第k+i-1条对角线x=y不能再放； 
				c[k-i+n]=1;
				dfs(k+1);
				a[i]=0;
				b[k+i-1]=0;
				c[k-i+n]=0;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1); 
	for(int i=1;i<=min(cnt,3);i++)
	{
		for(int j=1;j<n;j++)printf("%d ",ans[i][j]);
		printf("%d\n",ans[i][n]);
	}	
	printf("%d\n",cnt); 
	return 0;
}