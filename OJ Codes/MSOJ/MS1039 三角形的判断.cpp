#include<cstdio>
using namespace std;
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a+b>c&&a+c>b&&c+b>a)
	{
		if(a==b&&b==c)//等边三角形 
		{
			printf("1");	
		}
		else
		{
			if((a==b&&a*a+b*b==c*c)||(b==c&&b*b+c*c==a*a)||(c==a&&c*c+a*a==b*b))//等腰直角三角形 
			{
				printf("3");
			}
			else
			{
				if((a==b&&a*a+b*b!=c*c)||(b==c&&b*b+c*c!=a*a)||(c==a&&c*c+a*a!=b*b))//等腰三角形 
				{
				printf("2");
				}
				else if((a*a+b*b==c*c||b*b+c*c==a*a||a*a+c*c==b*b)&&(a!=b&&b!=c&&c!=a))//直角三角形 
				{
					printf("4");
				}
				else
				{
					printf("5"); //一般三角形 
				}
				 
			}
			
		}
		
	}
	else
	{
		printf("6");//不能构成三角形 
	}
	return 0;
}