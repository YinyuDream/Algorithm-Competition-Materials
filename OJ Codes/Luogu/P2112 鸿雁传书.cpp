#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,k;
double sum[maxn],dp[maxn][maxn],avg;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		char word[25];
		scanf("%s",word+1);
		int len=strlen(word+1);
		avg+=len,sum[i]=sum[i-1]+len;
	}
	avg/=k;
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=0x7f7f7f7f;
	for(int i=1;i<=n;i++)
		dp[1][i]=(sum[i]-avg)*(sum[i]-avg);
	for(int i=2;i<=k;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=j;k++)
				dp[i][j]=min(dp[i-1][k]+(sum[j]-sum[k]-avg)*(sum[j]-sum[k]-avg),dp[i][j]);
	printf("%.1f",dp[k][n]/k);
	return 0;
}
