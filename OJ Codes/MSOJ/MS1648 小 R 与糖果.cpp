#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,p=10000007,N=4;
int n,k,ans;
int a[maxn];
struct martix{
	int num[N][N];
	martix(){
		memset(num,0,sizeof num);
	}
}t,e;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			for(int k=1;k<N;k++)
				c.num[i][j]=(c.num[i][j]+1ll*a.num[i][k]*b.num[k][j])%p;
	return c; 
}
martix qpow(const martix &a,int b)
{
	martix c;
	if(!b){
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
	//freopen("candy.in","r",stdin);
	//freopen("candy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		ans=(ans+a[i])%p;
	if(a[n]<0&&a[n-1]<0)return printf("%d",((ans+1ll*k*(a[n]+a[n-1]))%p+p)%p),0;
	if(a[n-1]<0&&a[n]>0){
		while(a[n-1]<0&&k>0){
			ans=(a[n-1]+a[n]+p)%p;
			a[n-1]+=a[n];
			k--;
		}
	}
	if(!k)return printf("%d",ans),0;
	e.num[1][1]=e.num[1][2]=e.num[1][3]=e.num[2][1]=e.num[2][3]=e.num[3][3]=1;
	t.num[1][1]=t.num[1][3]=1;
	t=t*qpow(e,k-1);
	ans=(ans+1ll*a[n-1]*t.num[1][3])%p;
	t=t*e;
	ans=(ans+1ll*a[n]*(t.num[1][3]-1))%p;
	printf("%d",ans);
	return 0;
}