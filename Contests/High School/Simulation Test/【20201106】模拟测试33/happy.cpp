#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=6;
const ll p=998244353;
ll n;
struct martix{
	ll num[N][N];
	martix(){
		memset(num,0,sizeof num);
	}
}e,t;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			for(int k=1;k<N;k++)
				c.num[i][j]=(c.num[i][j]+a.num[i][k]*b.num[k][j])%p;
	return c;
}
martix qpow(const martix &a,ll b)
{
	martix c;
	if(b==0){
		for(int i=1;i<N;i++){
			c.num[i][i]=1;
		}
		return c;
	}
	c=qpow(a,b/2);
	c=c*c;
	if(b&1)c=c*a;
	return c;
}
void init()
{
	e.num[1][1]=e.num[1][2]=e.num[1][5]=1;
	e.num[2][1]=e.num[2][5]=1;
	e.num[3][1]=e.num[3][3]=e.num[3][4]=e.num[3][5]=1;
	e.num[4][3]=1;
	e.num[5][5]=1;
	t.num[1][1]=t.num[1][3]=2;
	t.num[1][2]=t.num[1][4]=1;
	t.num[1][5]=3;
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%lld",&n);
	init();
	t=t*qpow(e,n-1);
	printf("%lld",t.num[1][5]);
}
