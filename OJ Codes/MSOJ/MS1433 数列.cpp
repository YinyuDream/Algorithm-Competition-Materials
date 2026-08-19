#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
const double eps=1e-9;
int n,L;
double l,r;
double a[maxn],b[maxn];
bool check(double x)
{
	double minx=0x7fffffff,ans=-0x7fffffff;
	for(int i=1;i<=n;i++)
		b[i]=a[i]-x;
	for(int i=1;i<=n;i++)
		b[i]+=b[i-1];
	for(int i=L;i<=n;i++)
	{
		minx=min(minx,b[i-L]);
		ans=max(ans,b[i]-minx);
	}
	return ans>=0;
}
int main(){
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	r=0x7ffffffff,l=-0x7fffffff;
	while(r-l>eps)
	{
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.0f\n",r*1000);
	return 0;
}
