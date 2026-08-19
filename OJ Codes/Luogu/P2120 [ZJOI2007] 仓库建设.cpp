#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n;
ll ans=0x7f7f7f7f7f7f7f7fll,f[maxn];
int d[maxn],c[maxn],w[maxn],sum[maxn];
int q[maxn],head=1,tail;
double slope(int x,int y)
{
	return (1.0*f[x]-f[y])/(1.0*d[x]-d[y]);
}
int main(){
	memset(f,0x7f,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&d[i],&c[i],&w[i]);
	f[n]=w[n];
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+c[i];
	for(int i=1;i<=n;i++)
		f[n]+=1ll*(d[n]-d[i])*c[i];
	q[++tail]=n;
	for(int i=n-1;i;i--){
		while(head<tail&&slope(q[head],q[head+1])>=sum[i])head++;
		f[i]=f[q[head]]-1ll*sum[i]*(d[q[head]]-d[i])+w[i];
		while(head<tail&&slope(q[tail],q[tail-1])<=slope(i,q[tail-1]))tail--;
		q[++tail]=i;
	}
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]);
	printf("%lld",ans);
	return 0;
}
