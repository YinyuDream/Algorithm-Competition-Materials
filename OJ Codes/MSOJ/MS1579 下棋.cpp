#include<cstdio>
using namespace std;
const int maxn=1e2+10,p=9999973;
int n,m;
long long f[maxn][maxn][maxn],ans;
int main(){
	//freopen("chess.in","r",stdin);
	//freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1][m][0]=1,f[1][m-1][1]=m,f[1][m-2][2]=m*(m-1)/2;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m;k++){
				f[i][j][k]=(f[i][j][k]+f[i-1][j][k])%p;
				f[i][j][k]=(f[i][j][k]+(k+1)*f[i-1][j][k+1]+(j+1)*f[i-1][j+1][k-1])%p;
				f[i][j][k]=(f[i][j][k]+(k+2)*(k+1)*f[i-1][j][k+2]/2+(j+2)*(j+1)*f[i-1][j+2][k-2]/2+(j+1)*k*f[i-1][j+1][k])%p; 
			}
		}
	}
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			ans=(ans+f[n][i][j])%p;
	printf("%lld",ans);
	return 0;
}