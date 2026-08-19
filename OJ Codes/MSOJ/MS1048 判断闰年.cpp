#include<cstdio>
using namespace std;
int a;
int main()
{
	scanf("%d",&a);
	if(a%4!=0)
	{
		printf("N"); 
	}
	else
	{
		if((a%3200==0)||((a%100==0)&&(a%400!=0)))
		{
			printf("N");
		}
		else
		{
			printf("Y"); 
		}
	}
	return 0; 
}