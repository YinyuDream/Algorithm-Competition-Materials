#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,ans;
int a[maxn],b[maxn];
int f[maxn][35];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)a[i]=1;
		else b[i]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			f[i][j+1]=max(f[i-1][j+1],f[i-1][j])+((j&1)?b[i]:a[i]);
	for(int i=0;i<=m;i++)
		ans=max(ans,f[n][i+1]);
	printf("%d",ans);
	return 0;
}
