#include<cstdio>
#define ll long long
using namespace std;
int n;
ll q,p[]={2,3,5,7,11,13,17,37};
ll mul(ll a,ll b,ll p)
{
	ll ans=0;
	while(b!=0){
		if(b&1==1)ans+=a,ans%=p;
		a=a+a,a%=p;
		b>>=1; 
	}
	return ans;
}
ll fast_pow(ll a,ll b,ll p)
{
	if(b==0)return 1ll;
	ll c=fast_pow(a,b/2,p);
	c=mul(c,c,p);
	if(b&1)return mul(c,a,p);
	else return c;
}
bool millar_rabin(ll x,ll a)
{
	ll d=x-1,r=0;
	while(d%2==0){
		r++;
		d/=2;
	}
	d=fast_pow(a,d,x);
	if(d==1)return true;
	for(int i=0;i<r;i++)
	{
		if(d==x-1)return true;
		d=mul(d,d,x);
	}
	return false;
}
bool check(ll x)
{
	if(x<2)return false;
	for(int i=0;i<=7;i++)
	{
		if(x==p[i])return true;
		if(x%p[i]==0)return false;
		if(!millar_rabin(x,p[i]))return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&q);
		if(check(q))puts("YES");
		else puts("NO");
	}
}
