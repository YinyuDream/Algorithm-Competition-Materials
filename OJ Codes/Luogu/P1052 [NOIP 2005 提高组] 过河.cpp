#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int L,S,T,M,ans=0x3f3f3f3f;
int a[maxn],far[maxn],stone[maxn],dp[maxn];
int main(){
	scanf("%d",&L);
	scanf("%d%d%d",&S,&T,&M);
	for(int i=1;i<=M;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+M+1);
	if(S==T)
	{
		ans=0;
		for(int i=1;i<=M;i++)
			if(a[i]%S==0)ans++;
		printf("%d",ans);
		return 0;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=M;i++)
		far[i]=(a[i]-a[i-1])%90; 
	for(int i=1;i<=M;i++)
		a[i]=far[i]+a[i-1];
	for(int i=1;i<=M;i++)
		stone[a[i]]=1;
	for(int i=1;i<=a[M]+T;i++)
		for(int j=S;j<=T;j++)
			if(j<=i)
				dp[i]=min(dp[i-j]+stone[i],dp[i]);
	for(int i=a[M];i<=a[M]+T;i++)ans=min(ans,dp[i]);
	printf("%d",ans);
	return 0;
}