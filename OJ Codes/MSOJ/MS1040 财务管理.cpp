#include<cstdio>
using namespace std;
double a;
double sum=0;
int main(){
	for(int i=1;i<=12;i++)
	{
	scanf("%lf",&a);
	sum=sum+a;	
	}
	sum=sum/12;
	printf("%.2f",sum);
	return 0;
}