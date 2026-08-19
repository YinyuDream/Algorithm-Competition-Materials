#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,ans;
int a[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			a[i][j]=max(a[i-1][j-1],a[i-1][j])+a[i][j];
	for(int i=1;i<=n;i++)
		ans=max(ans,a[n][i]);
	printf("%d",ans);
	return 0;
}
