#include<cstdio>
using namespace std;
int m,n,x,k,z;
int s;
int main()
{
	scanf("%d%d%d",&m,&n,&x);
	for(int i=m;i<=n;i++)
	{
		z=i;
		for(int j=1;j<=5;j++)
		{
			
			k=z%10;
			z=z/10;
			if(k==x)s++;	
		}	
	}
printf("%d",s);
return 0;	
}
