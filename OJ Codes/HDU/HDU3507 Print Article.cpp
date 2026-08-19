#include<cstdio>
using namespace std;
const int maxn=5e5+10;
int n,m;
long long a[maxn],dp[maxn],sum[maxn];
int L=1,R=1,q[maxn];
double slop(int k,int j)
{
	return (double)(dp[j]+sum[j]*sum[j]-dp[k]-sum[k]*sum[k])/(2*(sum[j]-sum[k]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp)
		scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
		else{
			i--,n--;continue;
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(L<R&&slop(q[L],q[L+1])<=sum[i])L++;
		dp[i]=dp[q[L]]+(sum[i]-sum[q[L]])*(sum[i]-sum[q[L]])+m;
		while(L<R&&slop(q[R-1],q[R])>slop(q[R],i))R--;
		q[++R]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}