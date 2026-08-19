#include<cstdio>
#include<cmath>
using namespace std;
int a,n=0,j=2;
bool bo;
int main()
{
	scanf("%d",&a);
	for(int i=2;1;i++)
	{
		j=2;bo=0;
		for(;j<=sqrt(i);j++)
		{
			if(i%j==0){bo=1;break;}
		}
		if(bo==0)n=n+1;
		if(n==a){printf("%d",i);break;}	
	}
	return 0;
}
