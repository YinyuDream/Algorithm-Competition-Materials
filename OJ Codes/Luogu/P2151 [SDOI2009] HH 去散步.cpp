#include<cstdio>
#include<cstring>
using namespace std;
const int N=125,p=45989;
int n,m,t,a,b,ans;
struct edge{
	int u,v;
}e[N];
struct martix{
	int a[N][N];
	martix(){
		memset(a,0,sizeof a);
	}
}dp;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=m*2;i++)
		for(int j=1;j<=m*2;j++)
			for(int k=1;k<=m*2;k++)
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
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&t,&a,&b);
	a++,b++;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u++;v++;
		e[i]={u,v};
		e[i+m]={v,u};
	}
	for(int i=1;i<=m*2;i++)
		for(int j=1;j<=m*2;j++)
			if(e[i].v==e[j].u&&j-i!=m&&i-j!=m)
				dp.a[i][j]=1;
	dp=qpow(dp,t-1);
	for(int i=1;i<=m*2;i++)
		for(int j=1;j<=m*2;j++)
			if(e[i].u==a&&e[j].v==b)
				ans+=dp.a[i][j],ans%=p;
	printf("%d\n",ans);
			
}
