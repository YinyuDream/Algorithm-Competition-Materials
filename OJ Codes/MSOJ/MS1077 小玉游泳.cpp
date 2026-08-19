#include<cstdio>
using namespace std;
int x,n=0,j;
double s=0,k=1;
int main()
{
	scanf("%d",&x);
	
	while(s<x)
	{ 
		j=1;
		k=2;
			for(;j<=n;j++)
			{	
				k=k*0.98;
			}
		s=s+k;
		n++;	
	}
printf("%d",n);
return 0;		
}