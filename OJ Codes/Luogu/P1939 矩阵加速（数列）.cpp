#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=4,mod=1e9+7;
int T,n;
struct martix{
	ll a[N][N];
	martix(){
		memset(a,0,sizeof a);
	}
	
};
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			for(int k=1;k<N;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
	return c;
}
martix fast_pow(martix a,int b)
{
	martix c;
	if(b==0){
		for(int i=1;i<N;i++)
			c.a[i][i]=1;
			return c;
	}
	c=fast_pow(a,b/2);
	c=c*c;
	if(b&1)c=c*a;
	return c;
}
int main(){
	scanf("%d",&T);
	martix base,a;
	base.a[1][3]=base.a[2][1]=base.a[3][2]=base.a[3][3]=1;
	a.a[1][1]=a.a[1][2]=a.a[1][3]=1;
	while(T--)
	{
		scanf("%d",&n);
		martix t=fast_pow(base,n-1);
		t=a*t;
		printf("%lld\n",t.a[1][1]%mod);	
	} 
	return 0;
}
