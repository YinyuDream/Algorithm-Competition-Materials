#include<cstdio>
const int maxn=10+10;
int n,cnt=0;
int b[maxn];//b[i]=j表示i这个人借了j这本书 
int book[maxn];//book[i]表示i这本书是否被借 
int a[maxn][maxn];//a[i][j]表示第i个人对第j本书的喜爱情况，a[i][j]=0表示不喜欢，a[i][j]=1表示喜欢 
int res[4000000][11];//存借书方案的结果 
void dfs(int x)//第x个同学借书 
{
	if(x==n+1)//说明前n个同学已借好书，形成一个方案 
	{
		//输出一个可行的借书方案
		cnt++;
		for(int i=1;i<=n;i++) res[cnt][i]=b[i]; 
		return ; 
	}
	//第x个人开始借书
	for(int i=1;i<=n;i++)//枚举第x个人可以借书的范围(1--n) 
	{
		if(a[x][i]==1 && book[i]==0)//x这个人可以借i这本书 
		{
			book[i]=1;
			b[x]=i;
			dfs(x+1);
			book[i]=0;
			b[x]=0;
		}
	} 
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	dfs(1);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<n;j++){
			printf("%d ",res[i][j]);
		}
		printf("%d\n",res[i][n]);
	}
	return 0;
}
