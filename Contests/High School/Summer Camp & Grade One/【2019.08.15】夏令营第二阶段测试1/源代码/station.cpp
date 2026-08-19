#include<cstdio>
using namespace std;

const int maxn=1e6+10;
int n,stack[maxn],top,t;
long long b[maxn],maxx=-1e9;
struct station
{
	int h,v;
};
station a[maxn];
int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].h,&a[i].v);
	for(int i=1;i<=n;i++)
	{
		int temp=i,cnt;
		if(a[i+1].h>a[i].h)b[i+1]+=a[i].v;
		if(a[i-1].h>a[i].h)b[i-1]+=a[i].v;
	}
	for(int i=1;i<=n;i++)
		if(maxx<b[i])
			maxx=b[i];
	printf("%lld",maxx);
	return 0;
}
