#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
typedef __int128 ll;
ll k,m;
map<ll,ll>mp;
ll read() 
{
    ll x=0;
	char ch=getchar();
    while (ch<'0'||ch>'9')
	ch=getchar();
    while (ch>='0'&&ch<='9')x=x*10+ch-48,
	ch=getchar();
    return x;
}
void print(ll x){
    if(x>9)print(x/10);
    putchar(x%10+48);
}
ll ksm(ll a,ll b,ll p)//a^b mod p
{
	if(b==0)return 1;
	ll t=ksm(a,b/2,p);
	t=t*t%p;
	if(b&1)t=t*a%p;
	return t;
}
ll bsgs(ll a,ll k,ll m)//a^x mod m=k
{
	ll q=(ll)sqrt((double)m)+1;
    ll t=k;
	for(int i=0;i<q;i++)
	{
		mp[t]=i;
		t=t*a%m;
	}
	ll s=ksm(a,q,m);
	t=1;
	for(int i=1;i<=q+1;i++)
	{
		t=t*s%m;
		if(mp[t]&&i*q-mp[t]>=0)return i*q-mp[t];
	}
	return -1;
}
int main(){
	k=read(),m=read();
	k=9*k+1;
	print(bsgs(10,k%m,m));
	return 0;
}