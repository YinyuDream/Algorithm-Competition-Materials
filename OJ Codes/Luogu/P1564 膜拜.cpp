#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3e3+10;
int n,m;
int a[maxn],dp[maxn];
int suma[maxn],sumb[maxn];
bool check(int l,int r)
{
	int t=abs((suma[r]-suma[l-1])-(sumb[r]-sumb[l-1]));
	return t==(r-l+1)||t<=m;
}
int main(){
	memset(dp,0x7f,sizeof dp);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		suma[i]=suma[i-1]+(a[i]==1),
		sumb[i]=sumb[i-1]+(a[i]==2);
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int k=1;k<i;k++)
			if(check(k+1,i))
				dp[i]=min(dp[i],dp[k]+1);
		if(check(1,i))
			dp[i]=1;
	}
	printf("%d",dp[n]);
	return 0;
}
