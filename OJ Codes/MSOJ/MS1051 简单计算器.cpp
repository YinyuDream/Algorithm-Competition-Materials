#include<cstdio>
using namespace std;
int a,b;
char c;
int main()
{
	scanf("%d%d %c",&a,&b,&c);
	if(c=='+')printf("%d",a+b);
	else if(c=='-')printf("%d",a-b);
	else if(c=='*')printf("%d",a*b);
	else if(c=='/')
	{
		if(b==0)printf("Divided by zero!");
		else printf("%d",a/b);
	}
	else printf("Invalid operator!");
	return 0;
}
