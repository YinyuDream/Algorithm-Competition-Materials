#include<cstdio>
using namespace std;
int n,cnt;
bool a[20][20];
int b[20];
int c[50000][11];
bool book [20]; 
void kfs(int k)
{
	if(k==n+1)
	{
		cnt++;
		for(int j=1;j<=n;j++)c[cnt][j]=b[j];
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[k][i]==1&&book[i]==0)
		{
			book[i]=1;
			b[k]=i;
			kfs(k+1);
			book[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	kfs(1);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<n;j++){
			printf("%d ",c[i][j]);
		}
		printf("%d\n",c[i][n]);
	}
	return 0;
}
