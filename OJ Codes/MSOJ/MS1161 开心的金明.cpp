#include<cstdio>
#include<algorithm> 
using namespace std;
const int maxn=1e5+10;
int n,v,c[maxn],w[maxn];
int dp[maxn];
int main(){
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&c[i],&w[i]),w[i]=w[i]*c[i];
	for(int i=1;i<=n;i++)
		for(int j=v;j>=1;j--)
			if(j>=c[i])
				dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
	printf("%d",dp[v]);
	return 0;
}