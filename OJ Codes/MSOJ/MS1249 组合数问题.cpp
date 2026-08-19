#include<cstdio>
using namespace std;
const int maxn=2e3+10;
int t,k;
int c[maxn][maxn],sum[maxn][maxn];
bool book[maxn][maxn];
int main(){
	scanf("%d%d",&t,&k);
	for(int i=0;i<=2000;i++)
		c[i][0]=1;
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]%k+c[i-1][j]%k)%k;
	
	for(int i=0;i<=2000;i++)
		for(int j=0;j<=i;j++)
			if(c[i][j]%k==0)book[i][j]=1;
	for(int i=0;i<=2000;i++)
	{
		for(int j=0;j<=i;j++)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if(book[i][j])sum[i][j]++;
		}
		sum[i][i]=sum[i][i-1];
	}
	for(int i=1;i<=t;i++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d\n",sum[n][m<n?m:n]);
	}
	return 0;
}