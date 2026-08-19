#include<cstdio>
#include<algorithm>
using namespace std;
const int p=10007;
long long a,b,k,n,m;
long long r[1010][1010];
long long f(long long x,long long k)
{
	if(k==1)return x;
	if(k==0)return 1;
	int a=f(x,k/2);
	if(k%2==0)return (a%p)*(a%p)%p;
	else return (a%p)*(a%p)*(x%p)%p; 
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
	a=f(a,n),b=f(b,m);
	int t1=(a%p)*(b%p)%p;
	for(int i=0;i<=k;i++)r[i][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)
			r[i][j]=(r[i-1][j-1]%p+r[i-1][j]%p)%p;
	printf("%lld",(r[k][n]%p)*(t1%p)%p);
	return 0;
}
