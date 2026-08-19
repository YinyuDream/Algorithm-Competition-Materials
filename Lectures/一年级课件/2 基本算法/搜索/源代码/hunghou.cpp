#include<cstdio>
const int maxn=8+10;
int n;
int cnt=0;
int col[maxn],d1[maxn+maxn],d2[maxn+maxn];
int b[maxn];//b[i]=j表示第i个皇后放在第j列。
int res[maxn*maxn][maxn];//res[i][j]表示第i个方案的第j个皇后方的列数 
void dfs(int k)//放第k个皇后(自动放在第k行，以避免行重复)
{
	if(k==n+1)//说明已放好n个皇后，则表示形成了一个放置方案 
	{
		cnt++;
		for(int i=1;i<=n;i++) res[cnt][i]=b[i]; 
		return ;4
	}
	//开始放第k个皇后
	for(int i=1;i<=n;i++)//枚举第k个皇后可以放的列的范围(1--n)
	{
		if(col[i]==0 && d1[k+i]==0 && d2[k-i+n]==0)//第k个皇后能否放在i列的条件 
		{
			b[k]=i;
			col[i]=1;d1[k+i]=1;d2[k-i+n]=1;
			dfs(k+1);
			col[i]=0;d1[k+i]=0;d2[k-i+n]=0;
		}
	} 
} 
int main()
{
	scanf("%d",&n);
	dfs(1); 
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<n;j++) printf("%d ",res[i][j]);
		printf("%d\n",res[i][n]);
	}
	return 0;
}
