#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,k;
long long ans,a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]),ans+=a[i];
		long long mn=0x7f7f7f7f7f7f7f7fll;
		for(int i=1;i<=n;i++)
			b[i]=-i-a[i];
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)
			c[i]=c[i-1]+b[i],d[i]=(2ll*n-i+1)*i/2;
		for(int i=1;i<=k;i++){
			mn=min(mn,c[i]+d[i]);
		}
		if(mn<=0)ans+=mn;
		printf("%lld\n",ans);
	}
	return 0;
}