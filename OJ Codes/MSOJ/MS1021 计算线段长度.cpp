#include<cstdio>
#include<math.h>
double a,b,c,d,e;
int main(){
	scanf("%lf%lf",&a,&b);
	scanf("%lf%lf",&c,&d);
	e=(a-c)*(a-c)+(b-d)*(b-d);
	e=sqrt(e);
	printf("%.3f",e);
	return 0;
}
