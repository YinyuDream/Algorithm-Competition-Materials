#include<cstdio>
using namespace std;
int a;
bool x,y,z;
int main()
{
	scanf("%d",&a);
	x=a%3;y=a%5;z=a%7;
	if(x==1&&y==1&&z==1)
	{
		printf("n");}
	else if(x==0&&y==1&&z==1)
	{
		printf("3");
	}
	else if(x==1&&y==0&&z==1)
	{
		printf("5");
	}
	else if(x==1&&y==1&&z==0)
	{
		printf("7");
	}
	else if(x==0&&y==0&&z==1)
	{
		printf("3 5");
	}
	else if(x==1&&y==0&&z==0)
	{
		printf("5 7");
	}
	else if(x==0&&y==1&&z==0)
	{
		printf("3 7");
	}
	else
	{
		printf("3 5 7");
	}				
	return 0;
}