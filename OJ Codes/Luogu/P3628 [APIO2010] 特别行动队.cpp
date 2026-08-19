#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n;
long long A,B,C,a[maxn],sum[maxn],dp[maxn];
int q[maxn],head=1,tail;
inline long long f(int x){return A*x*x+B*x+C;}
inline long long Y(int x){return dp[x]+A*sum[x]*sum[x]-B*sum[x];}
inline long long X(int x){return sum[x];}
inline double slope(int x,int y){return (1.0*Y(y)-Y(x))/(1.0*X(y)-X(x));}
int main(){
	scanf("%d%lld%lld%lld",&n,&A,&B,&C);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	q[++tail]=0;
	for(int i=1;i<=n;i++){
		while(head<tail&&slope(q[head],q[head+1])>=2*A*sum[i])head++;
		dp[i]=dp[q[head]]+f(sum[i]-sum[q[head]]);
		while(head<tail&&slope(q[tail-1],q[tail])<=slope(q[tail-1],i))tail--;
		q[++tail]=i;
	}
	printf("%lld",dp[n]);
	return 0;
}
