#include<cstdio>
#include<cmath>
using namespace std;
double x1,y,x2,y2,x3,y3,a,b,c;
int main(){
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y,&x2,&y2,&x3,&y3);
	a=sqrt((x1-x2)*(x1-x2)+(y-y2)*(y-y2)),
	b=sqrt((x1-x3)*(x1-x3)+(y-y3)*(y-y3)),
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	printf("%.2f",a+b+c);
	return 0;
}
