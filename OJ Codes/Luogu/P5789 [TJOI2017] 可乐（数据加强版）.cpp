#include<cstdio>
#include<cstring>
using namespace std;
const int N=105,p=2017;
int n,m,t,ans;
struct martix{
	int a[N][N];
	martix(){
		memset(a,0,sizeof a);
	}
}dp;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n+1;j++)
			for(int k=1;k<=n+1;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j],
				c.a[i][j]%=p;
	return c;
}
martix qpow(martix a,int b)
{
	if(b==0){
		martix c;
		for(int i=1;i<=m*2;i++)
			c.a[i][i]=1;
		return c;
	}
	martix c=qpow(a,b/2);
	if(b&1)return c*c*a;
	else return c*c;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		dp.a[u][v]=dp.a[v][u]=1;
	}
	scanf("%d",&t);
	for(int i=1;i<=n+1;i++)
		dp.a[i][i]=dp.a[i][n+1]=1;
	dp=qpow(dp,t);
	for(int i=1;i<=n+1;i++)
		ans+=dp.a[1][i],ans%=p;
	printf("%d",ans);
	return 0;
}
