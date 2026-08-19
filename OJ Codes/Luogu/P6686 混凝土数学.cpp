#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=2e5+10;
int n,ans,sum[(int)2e5+10],maxm;
int cnt2[maxn],cnt3[maxn];
int a[(int)2e5+10],book[(int)2e5+10],cnt[(int)2e5+10];
int c(int x,int y)
{
	if(y==2)return x*(x-1)/2;
	if(y==3)return x*(x-1)*(x-2)/6;
}
bool cmp(int a,int b)
{
	return a>b;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]),book[a[i]]++,maxm=max(maxm,a[i]);
	for(int i=1;i<=maxm;i++)
	{
		if(book[i]>=2)
		cnt2[i]=c(book[i],2)%mod;
		if(book[i]>=3)
		cnt3[i]=c(book[i],3)%mod;
	}
	for(int i=1;i<=maxm;i++)
	sum[i]=(sum[i-1]+cnt2[i])%mod;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	ans+=sum[a[i]-1]-sum[a[i]/2],ans%=mod;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	ans+=sum[maxm]-sum[a[i]],ans%=mod;
	for(int i=1;i<=maxm;i++)
	if(book[i]>=3)
	ans+=cnt3[i],ans%=mod;
	printf("%lld\n",ans%mod);
	return 0;
}