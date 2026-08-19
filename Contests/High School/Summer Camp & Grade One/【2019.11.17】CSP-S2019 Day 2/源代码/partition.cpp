#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=4e7+10,mod=1<<30;
int n,type;
ll a[maxn],b[maxn];
ll sum[maxn];
struct node{
	ll sum,lmn;	
}dp[maxn];

void init()
{
	int x,y,z,b1,b2,m;
	scanf("%d%d%d%d%d%d%d",&x,&y,&z,&b1,&b2,&m);
	b[1]=b1,b[2]=b2;
	for(int i=3;i<=n;i++)
	{
		b[i]=(x*b[i-1]+y*b[i-2]+z)%mod;
	}
}
void dpf(){
	for(int i=1;i<=n;i++)dp[i].sum=1LL<<63-1;
	dp[1].sum=a[1]*a[1],dp[1].lmn=a[1];
	for(int k=2;k<=n;k++)
		for(int j=1;j<=k;j++)
			if(dp[j].lmn<=sum[k]-sum[j]&&k!=j)
				dp[k].sum=min(dp[k].sum,dp[j].sum+(sum[k]-sum[j])*(sum[k]-sum[j])),
				dp[k].lmn=sum[k]-sum[j];
			else if(k==j)
				if(sum[j]*sum[j]<=dp[k].sum)
					if(sum[j]*sum[j]==dp[k].sum)dp[k].lmn=min(dp[k].lmn,sum[j]);
					else dp[k].sum=sum[j]*sum[j],dp[k].lmn=sum[j];
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&type);
	if(type==0)for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	else init();
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	dpf();
	printf("%lld",dp[n].sum);
	return 0;
}
