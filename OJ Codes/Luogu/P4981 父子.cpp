#include<cstdio>
using namespace std;
const int p=1e9+9;
long long T,n;
long long ksm(long long a,long long b)
{
	if(b==0)return 1;
	long long t=ksm(a,b/2);
	t=(t*t)%p;
	if(b&1)t=(t*a)%p;
	return t;
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		printf("%lld\n",ksm(n,n-1));
	}
	return 0;
}
