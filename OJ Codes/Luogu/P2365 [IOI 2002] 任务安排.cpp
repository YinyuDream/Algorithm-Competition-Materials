#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,s;
int a[maxn],sum[maxn],f[maxn],w[maxn],sumw[maxn];
int main(){
	memset(f,0x3f,sizeof f);
	f[0]=0;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&w[i]),
		sum[i]=sum[i-1]+a[i],
		sumw[i]=sumw[i-1]+w[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			f[i]=min(f[i],f[j]+sum[i]*(sumw[i]-sumw[j])+s*(sumw[n]-sumw[j]));
	printf("%d",f[n]);
	return 0;
}
