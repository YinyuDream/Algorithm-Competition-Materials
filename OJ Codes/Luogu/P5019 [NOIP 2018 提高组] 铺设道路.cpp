#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,ans;
int a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n+1;i++)
		if(a[i]<a[i-1])
			ans+=a[i-1]-a[i];
	printf("%d",ans);
	return 0;
}
