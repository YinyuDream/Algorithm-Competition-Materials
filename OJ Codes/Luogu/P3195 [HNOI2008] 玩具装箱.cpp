#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n;
long long L,a[maxn],sum[maxn],f[maxn];
int q[maxn],head=1,tail;
inline long long Y(int x){return f[x]+(x+sum[x])*(x+sum[x]);}
inline long long X(int x){return x+sum[x];}
inline double slope(int x,int y){return (1.0*Y(x)-Y(y))/(1.0*X(x)-X(y));} 
int main(){
	scanf("%d%lld",&n,&L);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	L++;
	q[++tail]=0;
	for(int i=1;i<=n;i++){
		while(head<tail&&slope(q[head],q[head+1])<=2*(i+sum[i]-L))head++;
		f[i]=f[q[head]]+(i-q[head]+sum[i]-sum[q[head]]-L)*(i-q[head]+sum[i]-sum[q[head]]-L);
		while(head<tail&&slope(q[tail-1],q[tail])>=slope(q[tail-1],i))tail--;
		q[++tail]=i;
	}
	printf("%lld",f[n]);
	return 0;
}
