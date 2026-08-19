#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
const int N=105;
const ull inf=(1ull<<63)-1;
int n,k;
ull a[N],b[N];
struct martix{
	ull a[N][N];
	martix(){
		memset(a,0,sizeof a);
	}
}A,E;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			for(int r=1;r<=k;r++)
				c.a[i][j]|=a.a[i][r]&b.a[r][j];
	return c;
}
martix qpow(martix a,int b)
{
	martix c;
	for(int i=1;i<=k;i++)
		c.a[i][i]=inf;
	while(b)
	{
		if(b&1)c=c*a;
		a=a*a;
		b/=2;
	}
	return c;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
		scanf("%llu",&a[i]);
	for(int i=0;i<k;i++)
		scanf("%llu",&b[i]);
	for(int i=1;i<=k;i++)
		A.a[1][i]=a[i-1];
	for(int i=1;i<k;i++)
		E.a[i+1][i]=inf;
	for(int i=1;i<=k;i++)
		E.a[i][k]=b[i-1];
	A=A*qpow(E,n);
	printf("%llu",A.a[1][1]);
}
