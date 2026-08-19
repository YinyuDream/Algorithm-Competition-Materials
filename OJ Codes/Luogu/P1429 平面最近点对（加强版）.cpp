#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n;
struct point{
	double x,y;
}p[maxn],T[maxn];
bool cmp(point a,point b)
{
	return a.x<b.x;
}
bool cmp2(point a,point b)
{
	return a.y<b.y;
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double solve(int l,int r)
{
	if(r-l==1)return dis(p[l],p[r]);
	if(r-l==2)return min(dis(p[l],p[r]),min(dis(p[l],p[l+1]),dis(p[l+1],p[r])));
	int mid=(l+r)/2;
	double d=min(solve(l,mid),solve(mid+1,r));
	int k=0;
	for(int i=l;i<=r;i++)
	{
		if(abs(p[i].x-p[mid].x)<=d)
		T[++k]=p[i];
	}
	sort(T+1,T+k+1,cmp2);
	for(int i=1;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			if(T[j].y-T[i].y>=d)break;
			d=min(d,dis(T[i],T[j]));	
		}
	}
	return d;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	printf("%.4f",solve(1,n));
	return 0;
}
