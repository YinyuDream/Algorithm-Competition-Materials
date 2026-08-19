#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,m,s,q=1;
ll p[19];
struct martix{
	ll a[5][5];
	martix(){
		memset(a,0,sizeof a);
	}
}e,t,k;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j],
				c.a[i][j]%=m;
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
	scanf("%lld%lld",&n,&m);
	e.a[2][1]=e.a[2][2]=e.a[3][1]=e.a[3][2]=e.a[3][3]=1;
	k.a[1][3]=1;
	p[0]=1;
	for(int i=1;i<=18;i++)
		p[i]=p[i-1]*10;
	while(s<=n-p[q]+p[q-1]){
		t=e;
		t.a[1][1]=p[q]%m;
		k=k*qpow(t,p[q]-p[q-1]);
		s+=p[q]-p[q-1];
		q++;
		if(q==19)break;
	}
	t=e;
	t.a[1][1]=p[q]%m;
	k=k*qpow(t,n-s);
	printf("%lld\n",k.a[1][1]%m);
	return 0;
}
