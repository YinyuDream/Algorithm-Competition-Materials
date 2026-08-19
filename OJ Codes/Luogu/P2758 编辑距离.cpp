#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2010;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int main(){
	scanf("%s %s",a+1,b+1);
	memset(dp,0x7f,sizeof dp);
	for(int i=0;i<maxn;i++)
		dp[0][i]=i;
	for(int i=0;i<maxn;i++)
		dp[i][0]=i;
	for(int i=1;i<=strlen(a+1);i++){
		for(int j=1;j<=strlen(b+1);j++){
			if(a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
			}
		}
	}
	printf("%d",dp[strlen(a+1)][strlen(b+1)]);
	return 0;
}