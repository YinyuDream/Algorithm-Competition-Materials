#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,p=1e9+9;
int n,m;
int ans[maxn],sum[maxn];
int main(){
	scanf("%d%d",&m,&n);
	ans[1]=sum[1]=1;
	for(int i=2;i<=min(m-1,n);i++)
		ans[i]=(ans[i-1]*2)%p,sum[i]=(sum[i-1]+ans[i])%p;
	for(int i=m;i<=n;i++)
		ans[i]=(sum[i-1]-sum[i-m-1]+p)%p,sum[i]=(sum[i-1]+ans[i])%p;
	printf("%d\n",ans[n]%p);
	return 0;
}
