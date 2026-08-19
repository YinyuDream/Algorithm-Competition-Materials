#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int T,K;
map<ll,ll>book;
ll fast_pow(ll a,ll b,ll mod)
{
	if(b==0)return 1ll%mod;
	ll c=fast_pow(a,b/2,mod);
	c=c*c%mod;
	if(b&1)c=a*c%mod;
	return c%mod;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-y*(a/b);
	return d;
}
ll BSGS(ll a,ll b,ll p)//a^x¡Ôb(mod p)
{
	book.clear();
	if(a%p==0&&b)return -1;
	if(b%p==1)return 0;
	ll t=sqrt(p),num=1;
	for(int i=1;i<=t;i++)
	{
		num=1ll*num*a%p,
		book[num]=i;
		if(num%p==b)return i;
	}
	ll q=fast_pow(a,t,p);
	for(int i=2;i<=t+1;i++)
	{
		ll s=fast_pow(q,i-1,p);
		s=fast_pow(s,p-2,p);
		if(book[b*s%p])return book[b*s%p]+(i-1)*t;	
	}
	return -1;
}
int main(){
	scanf("%d%d",&T,&K);
	for(int i=1;i<=T;i++)
	{
		ll y,z,p;
		scanf("%lld%lld%lld",&y,&z,&p);
		if(K==1)
		printf("%lld\n",fast_pow(y,z,p));
		else if(K==2){
			ll x,k;
			ll d=exgcd(y,p,x,k);
			if(z%d){
				puts("Orz, I cannot find x!");
				continue;
			}
			while(x<0)x+=p/d;
			printf("%lld\n",((x*z/d)%(p/d)+p/d)%(p/d));
		}
		else if(K==3){
			ll ans=BSGS(y,z,p);
			if(ans==-1)puts("Orz, I cannot find x!");
			else printf("%lld\n",ans);
		}
	}
}
