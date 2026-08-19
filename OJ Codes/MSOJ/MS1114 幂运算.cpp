#include<cstdio>
using namespace std;
int g,k;
long long f(int a,int n)
{
	if(n==1)return a%123456;
	if(n==0)return 1;
	long long b=((f(a,n/2)%123456)*(f(a,n/2)%123456))%123456;
	if(n%2==1)b=(b%123456*a%123456)%123456;
	return b;
}
int main()
{
	scanf("%d%d",&g,&k);
	if(g!=0)printf("%lld",f(g,k));
	else printf("0"); 
	return 0;
}