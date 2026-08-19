#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,a,b,max_y;
struct point{
	int x,y;
}p[maxn];
bool cmp(point a,point b)
{
	return a.x<b.x;	
}
int f(int k,int x,int b)
{
	return k*x+b;
}
int check(int k,int b)
{
	int t1=0,t2=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i].y>=f(k,p[i].x,b))t1++;
		else t2++;
	}
	if(t2==0)return 1;
	if(b*t1>a*t2)return 0;
	else if(b*t1<a*t2)return 1;
	else return 2;
}
main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++)
	scanf("%lld%lld",&p[i].x,&p[i].y),max_y=max(max_y,p[i].y);
	sort(p+1,p+n+1,cmp);
	for(int i=-p[n].x;i<=max_y;i++)//b
	{
		//printf("fff%d\n",i);
		int l=1,r=1e12;//k
		while(l<=r)
		{
			int k=(l+r)/2,t=check(k,i);
			//printf("%lld\n",t);
			if(t==1)l=k+1;
			else if(t==0)r=k-1;
			else printf("%lld %lld %lld",k,0ll,i),exit(0);
		}
	}
}