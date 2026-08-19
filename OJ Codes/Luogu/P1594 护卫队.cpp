#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e3+10;
int wt,len,n;
int w[maxn],s[maxn],sum[maxn];
double dp[maxn],t[maxn][maxn],tme[maxn];
signed main(){
	scanf("%lld%lld%lld",&wt,&len,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&w[i],&s[i]);
		sum[i]=sum[i-1]+w[i];
		tme[i]=60.0*len/s[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[i][j]=max(t[i][j-1],tme[j]);
		}
	}
	for(int i=1;i<=n;i++)
		dp[i]=0x3f3f3f3f3f3f3f3f;
	dp[1]=t[1][1];
	for(int i=2;i<=n;i++){
		for(int j=i-1;sum[i]-sum[j]<=wt&&j>=0;j--){
			dp[i]=min(dp[i],dp[j]+t[j+1][i]);
		}
	}
	printf("%.1f",dp[n]);
	return 0;
} 
