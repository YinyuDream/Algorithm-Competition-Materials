#include<cstdio>
#include<cstring>
using namespace std;
const int N=51,mod=45989;
int n,m,t,a,b;
struct martix{
	int a[N][N];
	martix(){
		memset(a,0,sizeof a);
	}
}dp;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j],
				c.a[i][j]%=mod;
	return c;
}
martix fast_pow(martix a,int b)
{
	if(b==0){
		martix c;
		for(int i=1;i<=n;i++)
			c.a[i][i]=1;
		return c;
	}
	martix c=fast_pow(a,b/2);
	c=c*c;
	if(b&1)c=c*a;
	return c;
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&t,&a,&b);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u++;v++;
		dp.a[u][v]++;
	}
	dp=fast_pow(dp,t);
	printf("%d",dp.a[1][n]);
	return 0;
}
