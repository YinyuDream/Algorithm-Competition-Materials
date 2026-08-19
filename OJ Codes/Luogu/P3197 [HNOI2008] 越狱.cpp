#include<cstdio>
using namespace std;
const long long p=100003;
long long n,m;
long long f(long long x,long long k)
{
	//printf("%lld %lld\n",x,k);
	if(k==0)return 1;
	if(k==1)return x;
	long long a=f(x,k/2)%p;
	if(k%2==0)return ((a%p)*(a%p))%p;
	else return ((a%p)*(a%p)*(x%p))%p;
}
int main(){
	scanf("%lld%lld",&m,&n);
	printf("%lld",(f(m,n)%p-((m%p)*(f(m-1,n-1)%p))%p+p)%p);
	return 0;
}
