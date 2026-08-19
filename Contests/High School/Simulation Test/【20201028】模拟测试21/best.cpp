#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10,maxm=10;
int n,m,k,ans;
int a[maxn],bit_cnt[1<<maxm],f[maxn][1<<maxm];
int main(){
	freopen("best.in","r",stdin);
	freopen("best.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<(1<<maxm);i++)
		for(int j=i;j;j-=j&(-j))
			bit_cnt[i]++;
	for(int i=1;i<(1<<m);i++)
		if(bit_cnt[i]<=k)
			for(int j=1;j<=m;j++)
				if(i&(1<<(j-1)))
					f[m][i]+=a[j];
	for(int i=m+1;i<=n;i++)
		for(int j=0;j<(1<<m);j++)
			if(bit_cnt[j]<=k){
				if(bit_cnt[(j>>1)^(1<<(m-1))]<=k)
				f[i][j]=max(f[i-1][j>>1],f[i-1][(j>>1)^(1<<(m-1))])+(j&1)*a[i];
				else f[i][j]=f[i-1][j>>1]+(j&1)*a[i];
			}
	for(int i=0;i<(1<<m);i++)
		if(bit_cnt[i]<=k)
			ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}
