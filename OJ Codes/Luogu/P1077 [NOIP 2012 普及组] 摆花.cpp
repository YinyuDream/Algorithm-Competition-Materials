#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110,mod=1e6+7;
int n,m,ans;
int a[maxn],f[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)
	f[i][0]=1;
	for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
					for(int k=0;k<=a[i];k++)
					if(j-k>=0)
							f[i][j]+=f[i-1][j-k],
							f[i][j]%=mod;
	printf("%d",f[n][m]);	
}
