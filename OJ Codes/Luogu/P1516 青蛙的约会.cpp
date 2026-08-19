#include<cstdio>
using namespace std;
typedef long long ll;
ll _x,_y,_n,_m,_l,x,y,a,b,t,gcd,k;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-y*(a/b);
	return d;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&_x,&_y,&_m,&_n,&_l);
	t=_x-_y,a=_n-_m,b=_l;
	if(a<0)a=-a,t=-t;
	gcd=exgcd(a,b,x,y);
	if(t%gcd!=0)return puts("Impossible"),0;
	x*=t/gcd;
	k=b/gcd;
	x=(x%k+k)%k;
	printf("%lld",x);
	return 0;
}
