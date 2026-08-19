#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}
ll n,c,sum,a[maxn];
int main(){
	//freopen("disanti.in","r",stdin);
	//freopen("disanti.out","w",stdout);
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum+=a[i];
	for(int i=1;i<=n;i++){
		ll fz=n*a[i]+c-sum,fm=n,t=gcd(fz,fm);
		fz/=t,fm/=t;
		if(fm==1)printf("%lld\n",fz);
		else printf("%lld/%lld\n",fz,fm);
	}
	return 0;
}
