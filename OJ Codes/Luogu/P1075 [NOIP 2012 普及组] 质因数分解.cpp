#include<cstdio>
#include<cmath>
using namespace std;
long long a;
int main()
{
	scanf("%d",&a); 
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			printf("%lld",a/i);
			return 0;
		}
	}
	return 0;
}