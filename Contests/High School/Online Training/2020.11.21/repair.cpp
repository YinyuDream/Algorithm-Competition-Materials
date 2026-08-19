#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=20;
const ll p=1e9+7;
int n;
ll k,a[maxn],f[1<<maxn],g[1<<maxn],h[1<<maxn];
ll js(ll a,ll b)
{
	return a==b?a+1:max(a,b);
}
int main(){
	//freopen("repair.in","r",stdin);
	//freopen("repair.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		f[1<<(i-1)]=a[i],h[1<<(i-1)]=1;
	for(int i=1;i<(1<<n);i++){
		if(i==(i&(-i)))continue;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				if(f[i]<js(f[i^(1<<(j-1))],a[j])){
					f[i]=js(f[i^(1<<(j-1))],a[j]);
					g[i]=(g[i^(1<<(j-1))]+h[i^(1<<(j-1))]*js(f[i^(1<<(j-1))],a[j]))%p;
					h[i]=h[i^(1<<(j-1))];
				}else if(f[i]==js(f[i^(1<<(j-1))],a[j])){
					(g[i]+=g[i^(1<<(j-1))]+h[i^(1<<(j-1))]*js(f[i^(1<<(j-1))],a[j]))%=p;
					(h[i]+=h[i^(1<<(j-1))])%=p;
				}
			}
		}
	}
	printf("%lld %lld\n",f[(1<<n)-1],(k*g[(1<<n)-1]+h[(1<<n)-1]*((1<<(n-1))-n))%p);
	return 0;
}
