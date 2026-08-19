#include<cstdio>
using namespace std;
const int maxn=1e3+10,maxm=2e2+10,p=1e9+7;
int n,m,k;
long long f[2][maxm][maxm][2];
char a[maxn],b[maxm];
int main(){
	scanf("%d%d%d\n%s\n%s",&n,&m,&k,a+1,b+1);
	f[0][0][0][0]=f[1][0][0][0]=1;
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=m;j++)
			for(int l=1;l<=k;l++){
				if(a[i]==b[j])f[i&1][j][l][1]=(f[(i&1)^1][j-1][l-1][0]+f[(i&1)^1][j-1][l][1]+f[(i&1)^1][j-1][l-1][1])%p;
				else f[i&1][j][l][1]=0;
				f[i&1][j][l][0]=(f[(i&1)^1][j][l][0]+f[(i&1)^1][j][l][1])%p;
			}
	printf("%lld",(f[n&1][m][k][1]+f[n&1][m][k][0])%p);
}
