#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,k,x,y,mxp[maxn];
ll a[maxn],sum[maxn],mx[maxn],ans;
int main(){
	//freopen("max.in","r",stdin);
	//freopen("max.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	mx[k]=sum[k],mxp[k]=1;
	for(int i=k+1;i<=n;i++){
		if(sum[i]-sum[i-k]>mx[i-1]){
			mx[i]=sum[i]-sum[i-k];
			mxp[i]=i-k+1;
		}else{
			mx[i]=mx[i-1];
			mxp[i]=mxp[i-1];
		}
	}
	for(int i=k+1;i<=n-k+1;i++)
		if(mx[i-1]+sum[i+k-1]-sum[i-1]>ans){
			ans=mx[i-1]+sum[i+k-1]-sum[i-1];
			x=mxp[i-1];
			y=i;
		}
	printf("%d %d",x,y);
	return 0;
}