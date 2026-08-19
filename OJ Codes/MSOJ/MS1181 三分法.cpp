#include<cstdio>
using namespace std;
const int maxn=15;
int n;
double a[maxn];
double f(double x)
{
	double ans=0;
	for(int i=n;i>=0;i--)
		ans=ans*x+a[i];
	return ans;	
}
int main(){
	double lef,rig;
	scanf("%d%lf%lf",&n,&lef,&rig);
	for(int i=n;i>=0;i--)
		scanf("%lf",&a[i]);
	while(rig-lef>=1e-6){
		double lmid=(rig-lef)/3.0+lef,rmid=rig-(rig-lef)/3.0;
		if(f(lmid)<=f(rmid))lef=lmid;
		else rig=rmid;	
	}	
	printf("%.5f",(lef+rig)/2);
	return 0;
}