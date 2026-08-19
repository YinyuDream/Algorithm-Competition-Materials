#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10,maxd=2e4+10,p=998244353;
int n,mx,mn=0x7f7f7f7f,d,ans;
int a[maxn],dp[maxn][maxd*2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		dp[i][0]=1,
		mx=max(mx,a[i]),
		mn=min(mn,a[i]);
	d=mx-mn;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
				dp[i][a[i]-a[j]+maxd]+=dp[j][a[i]-a[j]+maxd],
				dp[i][a[i]-a[j]+maxd]%=p,
				dp[i][a[i]-a[j]+maxd]+=dp[j][0],
				dp[i][a[i]-a[j]+maxd]%=p;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=maxd+d;j++)
			ans+=dp[i][j],ans%=p;
	printf("%d",ans);
	return 0;
}