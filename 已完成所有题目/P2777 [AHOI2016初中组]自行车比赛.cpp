#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,ans=1,mx;
int a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		b[i]=n-i+1;
	sort(a+1,a+n+1);
	mx=a[n]+1;
	for(int i=n-1;i;i--)
		if(a[i]+n>=mx)ans++,mx=max(mx,a[i]+b[i]);
		else break;
	printf("%d",ans);
	return 0;
}