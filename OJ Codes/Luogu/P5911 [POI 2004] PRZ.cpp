#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
const int maxn=18;
int n,w;
int t[maxn],c[maxn],dp[1<<maxn],m[1<<maxn],f[1<<maxn];
int main(){
	scanf("%d%d",&w,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&t[i],&c[i]);
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=n;j++)
			if(i&(1<<(j-1)))
				m[i]+=c[j],
				f[i]=max(f[i],t[j]);
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(int i=1;i<(1<<n);i++)
		for(int j=i;;j=(j-1)&i)
		{
			if(m[i^j]<=w)
				dp[i]=min(dp[i],dp[j]+f[i^j]);
			if(j==0)break;
		}
	printf("%d",dp[(1<<n)-1]);
}
