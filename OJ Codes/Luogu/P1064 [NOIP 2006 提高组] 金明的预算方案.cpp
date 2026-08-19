#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m;
int w[maxn],v[maxn],a[maxn],b[maxn],c[maxn];
int dp[maxn];//前i个物品放入体积为v的背包中物品个数为k的最大价值 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&v[i],&w[i],&c[i]);
		if(a[c[i]])b[c[i]]=i;
		else a[c[i]]=i;
	}
	
	for(int i=1;i<=m;i++)
	{
		if(c[i])continue;
		for(int j=n;j>=0;j--)
		{
			dp[j]=max(dp[j],dp[j]);
			if(j-v[i]>=0)dp[j]=max(dp[j],dp[j-v[i]]+v[i]*w[i]);
			if(j-v[i]-v[a[i]]>=0)dp[j]=max(dp[j],dp[j-v[i]-v[a[i]]]+v[i]*w[i]+v[a[i]]*w[a[i]]);
			if(j-v[i]-v[b[i]]>=0)dp[j]=max(dp[j],dp[j-v[i]-v[b[i]]]+v[i]*w[i]+v[b[i]]*w[b[i]]);
			if(j-v[i]-v[a[i]]-v[b[i]]>=0)dp[j]=max(dp[j],dp[j-v[i]-v[a[i]]-v[b[i]]]+v[i]*w[i]+v[a[i]]*w[a[i]]+v[b[i]]*w[b[i]]);
		}
	}
	printf("%d",dp[n]);
	return 0;
}
