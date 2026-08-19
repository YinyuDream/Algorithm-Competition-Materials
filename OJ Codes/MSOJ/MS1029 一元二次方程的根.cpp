#include<cstdio>
#include<cmath>
int a,b,c;
double X1,X2,k;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	k=b*b-4*a*c;
	if(k>=0)
	{
    	X1=(-b+sqrt(k))/(2*a);
		X2=(-b-sqrt(k))/(2*a);
		printf("%.2f %.2f",X1,X2);
	}
	else
	{
		printf("No Answer!");
	}
	return 0;
}