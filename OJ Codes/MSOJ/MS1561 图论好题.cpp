#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,a[maxn];
double ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ans=max(ans,(1.0*a[u]+a[v])/w);
	}
	printf("%.2f",ans);
	return 0;
}
