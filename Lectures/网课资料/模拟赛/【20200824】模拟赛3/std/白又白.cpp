#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=18;

int n;

long long m,z[maxn<<1],y[1<<maxn],x[1<<maxn];

void dfs(long long *z,int n,int p,long long sum,long long *x,int &cnt)
{
	if (p==n) x[cnt++]=sum;
	else
	{
		dfs(z,n,p+1,sum,x,cnt);
		sum+=z[p];
		if (sum>=m) sum-=m;
		dfs(z,n,p+1,sum,x,cnt);
	}
}

int main()
{
	scanf("%d%lld",&n,&m);
	for (int a=0;a<n;a++)
	{
		scanf("%lld",&z[a]);
		z[a]%=m;
	}
	if (n&1) n++;
	int cnt=0;
	dfs(z,n>>1,0,0,y,cnt);
	cnt=0;
	dfs(z+(n>>1),n>>1,0,0,x,cnt);
	sort(x,x+cnt);
	sort(y,y+cnt);
	long long ans=x[cnt-1]+y[cnt-1];
	if (ans>=m) ans-=m;
	int p1=0,p2=cnt-1;
	while (p1<cnt)
	{
		while (p2>=0 && x[p1]+y[p2]>=m)
			p2--;
		if (p2<0) p2++;
		if (x[p1]+y[p2]<m && x[p1]+y[p2]>ans) ans=x[p1]+y[p2];
		p1++;
	}
	printf("%lld\n",ans);

	return 0;
}
