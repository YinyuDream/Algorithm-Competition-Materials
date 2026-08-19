#include<cstdio>
using namespace std;
typedef long long ll;
ll a,m,ola,b;
void Phi(ll x)
{
	ll t=x;
	ola=x;
	for(ll i=2;i*i<=t;i++)
	{
		if(x%i==0){
			ola-=ola/i;
			x/=i;
		}
		while(x%i==0)x/=i;
	}
	if(x>1)ola-=ola/x;
}
bool read(ll &x)
{
	bool flag=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		if(x>=ola){
			x%=ola;
			flag=true;
		}
		ch=getchar();
	}
	if(flag)x+=ola;
}
ll fast_pow(ll x,ll y,ll p)
{
	if(y==0)return 1;
	ll c=fast_pow(x,y/2,p);
	c=c*c%p;
	if(y&1)c=c*x%p;
	return c;
}
int main(){
	scanf("%lld%lld",&a,&m);
	Phi(m);
	read(b);
	printf("%lld",fast_pow(a,b,m));
	return 0;
}
