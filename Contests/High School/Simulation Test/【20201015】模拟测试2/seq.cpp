#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=4,p=1e9+7;
int T,n;
struct martix{
	int num[N][N];
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
				c.num[i][j]=(c.num[i][j]+1ll*a.num[i][k]*b.num[k][j])%p;
	return c;
}
martix qpow(martix a,int b)
{
	martix c;
	if(b==0){
		for(int i=1;i<N;i++)
			c.num[i][i]=1;
			return c;
	}
	c=qpow(a,b/2);
	c=c*c;
	if(b&1)c=c*a;
	return c;
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	t.num[1][1]=t.num[1][2]=t.num[1][3]=1;
	e.num[1][3]=e.num[2][1]=e.num[3][2]=e.num[3][3]=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		martix ans=t*qpow(e,n-1);
		printf("%d\n",ans.num[1][1]);
	}
	return 0;
}
