#include<cstdio>
using namespace std;
int n;
long long a[100]; 
long long f(int x)
{
	if(x==1||x==2)
	{
		return 1;a[x]=1;
	}
	if(a[x]!=0)return a[x];
	else return a[x]=f(x-1)+f(x-2);
}
int main()
{
	scanf("%d",&n);
	printf("%lld",f(n));
}