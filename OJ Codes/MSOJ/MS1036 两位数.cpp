//输入一个整数，判断这个整数是否是两位数，是用“Yes”表示，不是用“No”表示 
#include<cstdio>
int a;
int main()
{
	scanf("%d",&a);
	if(a<100&&a>=10)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
    return 0;
}