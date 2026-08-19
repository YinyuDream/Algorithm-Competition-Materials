#include<cstdio>
#include<cmath>
using namespace std;
int a;
bool bo=0;
int main()
{
	scanf("%d",&a);
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			bo=1;
			break;
		}
	}
	if(bo==0)printf("Y");
	else printf("N");
	return 0;
}
