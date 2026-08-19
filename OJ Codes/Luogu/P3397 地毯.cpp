#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,m;
int cf[maxn][maxn],sum[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a1,b1,a2,b2;
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		cf[a1][b1]++;
		cf[a1][b2+1]--;
		cf[a2+1][b1]--;
		cf[a2+1][b2+1]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+cf[i][j],
		printf("%d%c",sum[i][j],j==n?'\n':' ');
	return 0;
}
