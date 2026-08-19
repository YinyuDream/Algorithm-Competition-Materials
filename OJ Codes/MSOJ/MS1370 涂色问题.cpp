#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=55;
int n,m,t;
int a[maxn][maxn],sum[maxn][maxn];
int f[maxn][maxn][maxn*maxn];
int main(){
	//freopen("paint.in","r",stdin);
	//freopen("paint.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++){
		char s[maxn];
		scanf("\n%s",s+1);
		for(int j=1;j<=m;j++)
			a[i][j]=(s[j]=='1');
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j]=sum[i][j-1]+a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t;j++)
			f[i][0][j]=f[i-1][m][j];
		for(int j=1;j<=m;j++)
			for(int k=1;k<=t;k++)
				for(int l=0;l<j;l++){
					int trans=0;
					trans=max(trans,f[i][l][k-1]+sum[i][j]-sum[i][l]);
					trans=max(trans,f[i][l][k-1]+j-l-(sum[i][j]-sum[i][l]));
					trans=max(trans,f[i][l][k]);
					f[i][j][k]=max(f[i][j][k],trans);
				}
	}											  
	printf("%d",f[n][m][t]);
	return 0;
}