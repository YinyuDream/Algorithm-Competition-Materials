#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int m,n,s,e,k;
int a[100010],dp[100010][20];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]),
		dp[i][0]=a[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
			dp[i][j]=__gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&s,&e),
		k=log(e-s+1)/log(2),
		printf("%d\n",__gcd(dp[s][k],dp[e-(1<<k)+1][k]));	
	return 0;
}
