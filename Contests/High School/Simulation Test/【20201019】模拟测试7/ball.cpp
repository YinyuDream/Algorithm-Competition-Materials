#include<cstdio>
using namespace std;
const int maxn=120;
int n;
char a[maxn];
long long ans;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d\n%s",&n,a+1);
	for(int i=1;i<=n;i++)
		if(a[i]=='B')
			ans+=1<<(n-i);
	printf("%lld",ans);
	return 0;
}
