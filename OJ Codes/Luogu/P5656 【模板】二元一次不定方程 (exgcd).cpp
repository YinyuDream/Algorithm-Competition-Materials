#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int T;
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-y*(a/b);
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		ll a,b,c,x,y,p,q;
		scanf("%lld%lld%lld",&a,&b,&c);
		ll d=gcd(a,b);
		if(c%d!=0){
			puts("-1");
			continue;
		}
		ll t=c/d,k;
		exgcd(a,b,x,y);
		x*=t,y*=t,p=b/d,q=a/d;
		if(x<0)k=ceil((1.0-x)/p),x+=p*k,y-=q*k;
		else k=(x-1)/p,x-=p*k,y+=q*k;
		if(y<=0)
			printf("%lld %lld\n",x,y+q*(ll)ceil((1.0-y)/q));
		else
			printf("%lld %lld %lld %lld %lld\n",(y-1)/q+1,x,(y-1)%q+1,x+(y-1)/q*p,y);
	}
	return 0;
}
