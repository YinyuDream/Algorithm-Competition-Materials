#include<cstdio>
using namespace std;
long long m,n;
long long f(long long x,long long y)
{
	if(x%y==0)return y;
	return f(y,x%y);
}
int main()
{
	scanf("%lld%lld",&m,&n);
	printf("%lld",f(m,n)); 
}
