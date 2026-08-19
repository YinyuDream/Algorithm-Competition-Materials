#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e3+10;
int n,k;
long long ans,a[maxn][maxn],sum[maxn][maxn],max_sum[maxn][4];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for(int i=k;i<=n;i++)
		for(int j=k;j<=n;j++)
			sum[i][j]=a[i][j]-a[i][j-k]-a[i-k][j]+a[i-k][j-k];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			max_sum[i][0]=max(max_sum[i][0],sum[i][j]);
		max_sum[i][0]=max(max_sum[i][0],max_sum[i-1][0]);
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++)
			max_sum[i][1]=max(max_sum[i][1],sum[i+k-1][j+k-1]);
		max_sum[i][1]=max(max_sum[i][1],max_sum[i+1][1]);
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++)
			max_sum[j][2]=max(max_sum[j][2],sum[i][j]);
		max_sum[j][2]=max(max_sum[j][2],max_sum[j-1][2]);
	}
	for(int j=n;j>=1;j--){
		for(int i=1;i<=n;i++)
			max_sum[j][3]=max(max_sum[j][3],sum[i+k-1][j+k-1]);
		max_sum[j][3]=max(max_sum[j][3],max_sum[j+1][3]);
	}
	for(int i=1;i<n;i++)
		ans=max(ans,max(max_sum[i][0]+max_sum[i+1][1],max_sum[i][2]+max_sum[i+1][3]));
	printf("%lld",ans);
	return 0;
}
