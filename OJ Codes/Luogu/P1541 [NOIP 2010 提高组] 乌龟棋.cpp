#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=41,N=350,M=5;
int n,m;
int a[N],cnt[M];
int dp[maxn][maxn][maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[0]),cnt[a[0]]++;
	dp[0][0][0][0]=a[1];
	for(int j=0;j<=cnt[1];j++)
		for(int k=0;k<=cnt[2];k++)	
			for(int p=0;p<=cnt[3];p++)	
				for(int q=0;q<=cnt[4];q++)
				{
					int t=j+2*k+3*p+4*q+1;
					if(j!=0)dp[j][k][p][q]=max(dp[j][k][p][q],dp[j-1][k][p][q]+a[t]);
					if(k!=0)dp[j][k][p][q]=max(dp[j][k][p][q],dp[j][k-1][p][q]+a[t]);
					if(p!=0)dp[j][k][p][q]=max(dp[j][k][p][q],dp[j][k][p-1][q]+a[t]);
					if(q!=0)dp[j][k][p][q]=max(dp[j][k][p][q],dp[j][k][p][q-1]+a[t]);	
				}		
	printf("%d",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);					
	return 0;
}
