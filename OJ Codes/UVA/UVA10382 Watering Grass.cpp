#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int T;
struct node{
	double l,r;
}e[maxn];
double f(double x,double y)
{
	if(x*x-y*y<0)return -1;
	return sqrt(x*x-y*y);
}
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main(){
	while(1)
	{
		int n,cnt=0,ans=0;
		double l,w,pos,r,lmax=0,rmax=0;
		if(scanf("%d%lf%lf",&n,&l,&w)==EOF)break;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&pos,&r);
			double t=f(r,w/2);
			if(t<0)continue;
			e[++cnt].l=pos-t;
			e[cnt].r=pos+t;
		}
		sort(e+1,e+cnt+1,cmp);
		while(rmax<l)
		{
			double lmax=rmax;
			for(int i=1;i<=cnt;i++)
				if(e[i].l<=rmax&&e[i].r>lmax)
				lmax=e[i].r;
			if(lmax==rmax){
				ans=-1;
				break;
			}
			rmax=lmax;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}