#include<cstdio>
#include<cstring>
using namespace std;
const int N=5,p=19260817;
typedef long long ll;
int T;
ll n;
struct martix{
	ll a[N][N];
	martix(){
		memset(a,0,sizeof a);
	}
}A,B,E;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j],
				c.a[i][j]%=p;
	return c;
}
martix qpow(martix a,ll b)
{
	if(b==0){
		martix c;
		c.a[1][1]=c.a[2][2]=c.a[3][3]=1;
		return c;
	}
	martix c=qpow(a,b/2);
	if(b&1)return c*c*a;
	else return c*c;
}
int main(){
	E.a[1][1]=E.a[1][2]=E.a[2][1]=E.a[2][3]=E.a[3][1]=1;
	A.a[1][1]=A.a[1][2]=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		B=A*qpow(E,n-1);
		printf("%lld\n",(B.a[1][1]+B.a[1][2]+B.a[1][3])%p);
	}
	return 0;
}
