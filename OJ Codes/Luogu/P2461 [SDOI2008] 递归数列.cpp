#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=20;
ll b[N],c[N],sum[N];
ll k,n,m,p;
struct martix{
	ll a[N][N];
	martix(){
		memset(a,0,sizeof a);
	}
}A,E;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=k+1;i++)
		for(int j=1;j<=k+1;j++)
			for(int r=1;r<=k+1;r++)
				c.a[i][j]+=a.a[i][r]*b.a[r][j],
				c.a[i][j]%=p;
	return c;
}
martix qpow(martix a,ll b)
{
	martix c;
	for(int i=1;i<=k+1;i++)
		c.a[i][i]=1;
	while(b)
	{
		if(b&1)c=c*a;
		a=a*a;
		b>>=1;
	}
	return c;
}
ll query(ll x)
{
	if(x<=k)return sum[x]%p;
	martix B=A*qpow(E,x-k);
	return B.a[1][k+1]%p;
}
int main(){
	scanf("%lld",&k);
	for(int i=1;i<=k;i++)
		scanf("%lld",&b[i]);
	for(int i=1;i<=k;i++)
		scanf("%lld",&c[i]);
	scanf("%lld%lld%lld",&m,&n,&p);
	for(int i=1;i<=k;i++)
		sum[i]=(sum[i-1]+b[i])%p,
		A.a[1][i]=b[i]%p,c[i]%=p;
	for(int i=1;i<k;i++)
	 	E.a[i+1][i]=1;
	for(int i=1;i<=k;i++)
		E.a[i][k+1]=E.a[i][k]=c[k-i+1];
	E.a[k+1][k+1]=1;
	A.a[1][k+1]=sum[k];
	printf("%lld\n",((query(n)-query(m-1))%p+p)%p);
	return 0;
}
