#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=55;
int n,dp[maxn][maxn];
char a[maxn];
bool query(int l,int r,char c)
{
	for(int i=l;i<=r;i++)
		if(a[i]==c)return false;
	return true;
}
int main(){
	memset(dp,0x3f,sizeof dp);
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++)
		dp[i][i]=1;
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++)
		{
			if(a[l]==a[l+len-1])
			dp[l][l+len-1]=min(dp[l+1][l+len-1],dp[l][l+len-2]);
			else
				for(int k=l;k<l+len-1;k++)
					dp[l][l+len-1]=min(dp[l][l+len-1],dp[l][k]+dp[k+1][l+len-1]);
		}
	printf("%d\n",dp[1][n]);
	return 0;
}
