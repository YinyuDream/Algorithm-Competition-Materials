#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=120;
int n;
char a[maxn];
long long ans;
int main(){
	scanf("%d\n%s",&n,a+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]=='B')
			ans+=1ll<<(n-i);
	printf("%lld",ans);
	return 0;
}
