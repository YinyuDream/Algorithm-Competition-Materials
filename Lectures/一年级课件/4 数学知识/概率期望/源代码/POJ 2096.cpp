#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
int n,m;
double dp[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&m);
	dp[n][m]=0;//±ß½ç
	for(int i=n;i>=0;i--){
		for(int j=m;j>=0;j--){
			if(i!=n || j!=m){
				dp[i][j]+=dp[i+1][j]*(n-i)*j;
				dp[i][j]+=dp[i][j+1]*i*(m-j);
				dp[i][j]+=dp[i+1][j+1]*(n-i)*(m-j);
				dp[i][j]+=n*m;
				dp[i][j]=dp[i][j]/(n*m-i*j);
			}
		}
	} 
	printf("%.4f\n",dp[0][0]);
	return 0;
}
