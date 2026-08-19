#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=2e7+10;
int n,ans=0x7f7f7f7f;
int a[maxn];
int main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		a[i+n]=a[i];
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			cnt+=abs(a[j+i]-j);
		}
		ans=min(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}
