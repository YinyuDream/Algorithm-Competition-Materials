#include<cstdio>
#include<algorithm>
const int maxn=2e5+10;
using namespace std;
int a[maxn];
int n,c,ans;
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)ans+=upper_bound(a+1,a+n+1,a[i]+c)-lower_bound(a+1,a+n+1,a[i]+c);
	printf("%d",ans);	
}
