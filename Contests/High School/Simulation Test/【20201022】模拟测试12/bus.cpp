#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=4e6+10,N=510;
int n,m,ans=0x7f7f7f7f;
int t[N],f[maxn],sum[maxn],cnt[maxn];
int q[maxn],head=1,tail=0;
inline int Y(int x){return f[x]+sum[x];}
inline int X(int x){return cnt[x];}
inline double slope(int x,int y){return (X(x)==X(y))?(Y(y)>Y(x)?2e9:-2e9):((1.0*Y(y)-Y(x))/(1.0*X(y)-X(x)));}
int work()
{
	for(int i=0;i<m;i++)
		f[i]=cnt[i]*i-sum[i];
	q[++tail]=0;
	for(int i=m;i<=t[n]+m;i++){
		while(head<tail&&slope(q[head],q[head+1])<=i)head++;
		f[i]=f[q[head]]+(cnt[i]-cnt[q[head]])*i-(sum[i]-sum[q[head]]);
		while(head<tail&&slope(q[tail-1],q[tail])>=slope(q[tail-1],i-m+1))tail--;
		q[++tail]=i-m+1;
	}
	for(int i=t[n];i<=t[n]+m;i++)
		ans=min(ans,f[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		cnt[t[i]]++;
		sum[t[i]]+=t[i];
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=t[n]+m;i++){
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	work();
	printf("%d",ans);
	return 0;
}
