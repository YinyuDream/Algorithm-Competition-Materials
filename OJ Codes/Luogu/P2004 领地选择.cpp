#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,c,ans=-0x7f7f7f7f,ansx,ansy;
int a[maxn][maxn];
int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for(int i=1;i+c-1<=n;i++)
		for(int j=1;j+c-1<=n;j++)
			if(ans<a[i+c-1][j+c-1]-a[i+c-1][j-1]-a[i-1][j+c-1]+a[i-1][j-1])
			ans=a[i+c-1][j+c-1]-a[i+c-1][j-1]-a[i-1][j+c-1]+a[i-1][j-1],
			ansx=i,ansy=j;
	printf("%d %d\n",ansx,ansy);
}
