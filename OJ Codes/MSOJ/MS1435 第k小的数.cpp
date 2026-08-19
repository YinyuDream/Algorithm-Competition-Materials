#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll n,m,k,l,r,ans,a[maxn],b[maxn];
ll check(ll x)//xµÄÅÅÃû
{
	ll p=m,cnt=0;
	for(int i=1;i<=n;i++)
	{
		while(a[i]*b[p]>x)p--;
		cnt+=p;
	}
	return cnt;
} 
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	l=a[1]*b[1],r=a[n]*b[m];
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)>=k)r=mid-1;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}
