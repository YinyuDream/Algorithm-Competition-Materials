#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,k,top;
int a[maxn];
int mx[maxn][maxn],minx[maxn][maxn],fff[maxn*maxn];
int main(){
	freopen("kth.in","r",stdin);
	freopen("kth.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		mx[i][i]=minx[i][i]=a[i];
	for(int i=1;i<=n;i++)	
		for(int j=i+1;j<=n;j++)
			mx[i][j]=max(mx[i][j-1],a[j]),
			minx[i][j]=min(minx[i][j-1],a[j]);
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
		fff[++top]=mx[i][j]-minx[i][j];
	sort(fff+1,fff+top+1,greater<int>());
	printf("%d",fff[k]);
	return 0;
}
