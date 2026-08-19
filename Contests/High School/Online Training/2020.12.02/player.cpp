#include<cstdio>
using namespace std;
typedef unsigned long long ull;
const int maxn=55,maxm=1505,p=1e9+7;
int n,m,ans;
char s[maxn][maxm][maxn];
int f[maxn][maxm];
ull _pow[maxn],a[maxn][maxm][maxn];
int main(){
	freopen("player.in","r",stdin);
	freopen("player.out","w",stdout);
	scanf("%d%d",&n,&m);
	_pow[0]=1;
	for(int i=1;i<=n;i++)
		_pow[i]=_pow[i-1]*131ull;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%s",s[i][j]+1);
			for(int k=1;k<=i;k++){
				a[i][j][k]=a[i][j][k-1]*131ull+s[i][j][k];
			}
		}
	}
	for(int i=1;i<=m;i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				if(a[i-1][k][i-1]==a[i][j][i-1]||a[i-1][k][i-1]==a[i][j][i]-a[i][j][1]*_pow[i-1])
					(f[i][j]+=f[i-1][k])%=p;
	for(int i=1;i<=m;i++)
		(ans+=f[n][i])%=p;
	printf("%d",ans);
	return 0;
}
