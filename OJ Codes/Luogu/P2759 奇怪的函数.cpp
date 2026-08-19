#include<cstdio>
#include<cmath>
using namespace std;
long long n,l=1,r=250000000;
bool check(long long x)
{
	return floor(x*log10(x)+1)>=n;
}
int main(){
	scanf("%lld",&n);
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}