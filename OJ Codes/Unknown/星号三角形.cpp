#include<cstdio>
using namespace std;
int a;
int main(){
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	

    return 0;   
}
