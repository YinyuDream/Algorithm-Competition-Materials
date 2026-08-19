#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int T,n,k;
int a[maxn],b[maxn];
bool cmp(int x,int y)
{
	if(a[x]!=a[y])return a[x]>a[y];
	else return x>y;
}
void solve()
{
	for(int i=1;i<=n;i++)
		b[i]=i;
	if(n==3){
		sort(b+1,b+n+1,cmp);
		if(a[b[1]]-a[b[3]]<a[b[2]])puts("3");
		else puts("1");
	}
}
int main(){
	//freopen("snakes.in","r",stdin);
	//freopen("snakes.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	solve();
	while(--T){
		scanf("%d",&k);
		for(int i=1,u,v;i<=k;i++)
			scanf("%d%d",&u,&v),a[u]=v;
		solve();
	}
	return 0;
}