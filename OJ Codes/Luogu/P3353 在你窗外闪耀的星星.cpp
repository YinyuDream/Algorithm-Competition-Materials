#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,w,ans;
int a[maxn];
int main(){
	scanf("%d%d",&n,&w);
	for(int i=1,pos,val;i<=n;i++){
		scanf("%d%d",&pos,&val);
		a[pos]+=val;
	}
	for(int i=1;i<maxn;i++)
		a[i]+=a[i-1];
	for(int i=w;i<maxn;i++)
		ans=max(ans,a[i]-a[i-w]);
	printf("%d",ans);
	return 0;
}
