#include<cstdio>
#include<cstring>
using namespace std;
const int N=90;
int n,t;
int mapp[N][N];
struct martix{
	int a[N][N];
	martix(){
		memset(a,0,sizeof a);
	}
};
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j],
				c.a[i][j]%=p;
	return c;
}
martix qpow(martix a,ll b)
{
	if(b==0){
		martix c;
		c.a[1][1]=c.a[2][2]=1;
		return c;
	}
	martix c=qpow(a,b/2);
	if(b&1)return c*c*a;
	else return c*c;
}
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		char t;
		scanf("%c",)
	}
	return 0;
}
