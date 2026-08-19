#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll m,a,c,x0,n,g;
struct martix{
	ll a[5][5];
	martix(){
		memset(a,0,sizeof a);
	}
}x,p;
ll qmul(ll x,ll y,ll mod) 
{
	ll ans=0;
	while(y!=0){
		if(y&1==1)ans+=x,ans%=mod;
		x=x+x,x%=mod;
		y>>=1; 
	}
	return ans;
}
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				c.a[i][j]=(c.a[i][j]+qmul(a.a[i][k],b.a[k][j],m)%m)%m;
	return c;
}
martix qpow(martix a,ll b)
{
	if(b==0){
		martix c;
		for(int i=1;i<=3;i++)
			c.a[i][i]=1;
			return c;
	}
	martix c=qpow(a,b/2);
	if(b&1)return c*c*a;
	else return c*c;
}
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&m,&a,&c,&x0,&n,&g);
	x.a[1][1]=x0,x.a[1][2]=1;
	p.a[1][1]=a,p.a[2][1]=c,p.a[2][2]=1;
	x=x*qpow(p,n);
	printf("%lld",x.a[1][1]%g);
	return 0;
}
