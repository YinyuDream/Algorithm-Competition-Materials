#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,sum,mx,a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	for(int i=2;i<=n;i++)
		mx=max(mx,a[i]+a[i+1]);
	mx=max(mx,a[n]+a[1]);	
	printf("%d\n",max((int)ceil(1.0*sum/(n/2)),mx));
	return 0;
}