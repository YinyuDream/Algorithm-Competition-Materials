#include<cstdio>
#include<cmath>
const int maxn=2e5+10;
using namespace std;
int t;
double H,h,D;
double f(double x){
	return D+H-x-(H-h)*D/x;
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lf%lf%lf",&H,&h,&D);
		double left=D*(H-h)/H,right=D;
		while(right-left>=1e-8){
			double lmid=left+(right-left)/3,rmid=right-(right-left)/3;
			if(f(lmid)>=f(rmid))right=rmid;
			else left=lmid;
		}
		printf("%.3f\n",f((left+right)/2));
	}
	return 0;
}