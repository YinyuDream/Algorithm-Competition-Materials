#include<cstdio>
using namespace std;
const int maxn=110;
int n,m; 
int a[maxn];
int f[maxn][maxn*10];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)
		f[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]+=f[i-1][j]; 
			if(j-a[i]>=0){
				f[i][j]+=f[i-1][j-a[i]];
			}
		} 
	}
	printf("%d",f[n][m]);
	return 0;
}