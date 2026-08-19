#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int T,ans,n;
int a[maxn];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			int mx=0,mn=0x7f7f7f7f;
			for(int j=i;j<=n;j++){
				mx=max(a[j],mx);
				mn=min(a[j],mn);
				ans+=mx-mn;
			}
		}
		printf("%d",ans);	
	}
}
