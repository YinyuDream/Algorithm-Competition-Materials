#include<cstdio>
using namespace std;
int x,n,sum;
int a,b,c;
int m[1000000+10];
int main()
{
	scanf("%d%d",&x,&n);
	for(int i=x;i<=x+n-1;i++)
	{
		if(i%7==6||i%7==0)m[i]=0;
		else m[i]=250;
	}
	for(int i=x;i<=x+n-1;i++)
	{
		sum=sum+m[i];
	}
	printf("%d",sum);
	return 0;
}
