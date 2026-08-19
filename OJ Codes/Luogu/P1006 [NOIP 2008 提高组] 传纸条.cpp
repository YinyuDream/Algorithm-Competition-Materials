#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,m;
int a[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	return 0;
}
