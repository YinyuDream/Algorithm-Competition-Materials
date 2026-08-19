#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int T,n,k,ans;
int a[maxn],w[maxn];
void dfs(int pos)
{
	if(pos==n+1){
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=a[i]*w[i];
		ans=max(sum,ans);
		return ;
	}
	for(int i=pos-k+1;i<=pos;i++)
		a[i]^=1;
	dfs(pos+1);
	for(int i=pos-k+1;i<=pos;i++)
		a[i]^=1;
	dfs(pos+1);
}
int main(){
	freopen("challenge.in","r",stdin);
	freopen("challenge.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		dfs(k);
		printf("%d\n",ans);
	}
	return 0;
}
