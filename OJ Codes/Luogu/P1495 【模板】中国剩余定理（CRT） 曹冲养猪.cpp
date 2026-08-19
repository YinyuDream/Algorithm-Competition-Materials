#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=11;
ll n,sum=1,a[maxn],m[maxn],b[maxn],t[maxn],tmp,ans;
void ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){
		x=1,y=0;
		return ;
	}
	ex_gcd(b,a%b,x,y);
	ll z=x;x=y;y=z-(a/b)*y;
}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&m[i],&a[i]),
		sum*=m[i];
	for(int i=1;i<=n;i++)
	b[i]=sum/m[i];
	for(int i=1;i<=n;i++)
	ex_gcd(b[i],m[i],t[i],tmp);
	for(int i=1;i<=n;i++)
		ans+=a[i]*b[i]*((t[i]>0)?t[i]:(t[i]+m[i])),ans%=sum;
	printf("%lld",ans);
	return 0;
}
