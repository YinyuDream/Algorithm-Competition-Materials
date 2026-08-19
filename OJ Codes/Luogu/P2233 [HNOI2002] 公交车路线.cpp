#include<cstdio>
#include<cstring>
using namespace std;
const int N=9,p=1000;
int n;
struct martix{
	int a[N][N]={
		{0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,1},
		{0,1,0,1,0,0,0,0,0},
		{0,0,1,0,1,0,0,0,0},
		{0,0,0,1,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,1,0},
		{0,0,0,0,0,0,1,0,1},
		{0,1,0,0,0,0,0,1,0}
	};
	void clear(){
		memset(a,0,sizeof a);
	}
}t;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	c.clear();
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			for(int k=1;k<N;k++)
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%p;
	return c;			
}
martix qpow(martix a,int b)
{
	martix c;
	c.clear();
	if(b==0){
		for(int i=1;i<N;i++)
			c.a[i][i]=1;
		return c;
	}
	c=qpow(a,b/2);
	c=c*c;
	if(b&1)c=c*a;
	return c;
}
int main(){
	scanf("%d",&n);
	t=qpow(t,n);
	printf("%d",t.a[1][5]);
	return 0;
}
