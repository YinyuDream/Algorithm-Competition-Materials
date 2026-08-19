#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
double a,b,c,xx,yy,ans;
inline double f(double m){
	return -sqrt((m-xx)*(m-xx)+(a*m*m-yy)*(a*m*m-yy));
}
inline double g(double x){
	return a*x*x;
}
int main(){
	double left,right;
	scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&xx,&yy);
	if(a==0)printf("%.3f",yy),exit(0);
	yy=yy-(4*a*c-b*b)/(4*a);xx=xx-(-(b/(2*a)));
	if(a<0)a=-a,yy=-yy;
	if(g(xx)<yy)
		if(xx<0)left=-1e5,right=xx;
		else left=xx,right=1e5;
	else
		if(xx<0)left=xx,right=0;
		else left=0,right=xx;
	while(right-left>=1e-5)
	{
		double lmid=left+(right-left)/3,rmid=right-(right-left)/3;
		if(f(lmid)>=f(rmid))right=rmid,ans=f(lmid);
		else left=lmid,ans=f(rmid);
	}
	printf("%.3f",-ans);
	return 0;
}