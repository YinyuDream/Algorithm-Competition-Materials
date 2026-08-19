#include<cstdio>
#include<cmath>
using namespace std;
unsigned long long n;
int main()
{
	scanf("%lld",&n);
	printf("%lld",n*(n-1)/2*(n-2)/3*(n-3)/4);	
} 