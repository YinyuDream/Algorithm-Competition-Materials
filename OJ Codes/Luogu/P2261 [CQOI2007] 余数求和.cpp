#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,ans;
int main(){
	scanf("%lld%lld",&n,&k);
	ans=n*k;
	n=min(n,k);
	for(int l=1,r;l<=n;l=r+1)
	{
		if(k/l!=0)
		r=min(k/(k/l),n);
		ans-=(r-l+1)*(k/l)*(l+r)/2;
	}
	printf("%lld",ans);
	return 0;
}
