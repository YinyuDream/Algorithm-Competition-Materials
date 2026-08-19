#include<cstdio>
using namespace std;
double a,b,c,d;
double num(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
double solve1(double left,double right)
{
	while(right-left>=1e-4)
	{
		double mid=(right+left)/2;
		if(num(mid)==0)return mid;
		else if(num(mid)*num(left)<0)right=mid;
		else left=mid;
	}
	return (left+right)/2; 
}
void solve2(double left,double right){
	if(num(left)==0)printf("%.2f ",left);
}
int main(){
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(double i=-100;i<=99;i++)
	{
		if(num(i)*num(i+1)<0)printf("%.2f ",solve1(i,i+1));
		else if(num(i)*num(i+1)==0)solve2(i,i+1);
		else continue; 
	}
	return 0;
}