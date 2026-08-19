#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn];
int p[maxn],book[maxn],ans[maxn];
int sum(int dis)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	sum+=(p[i]*p[i+dis]);
	return sum; 
}
void pre()
{
	do{
		for(int i=0;i<=n/2;i++)
		ans[i]=max(ans[i],sum(i));
	}
	while(next_permutation(p+n+1,p+2*n+1)&&next_permutation(p+1,p+n+1));
}
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	p[i+n]=p[i]=i;
	pre();
	for(int i=1;i<=m;i++)
	{ 
		int k;
		scanf("%d",&k);
		printf("%d\n",ans[k]);
	}
	return 0;
}
