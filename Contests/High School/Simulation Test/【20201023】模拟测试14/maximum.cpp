#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,ans=0x7f7f7f7f;
int a[maxn],b[maxn],help[maxn],book[maxn],bk[maxn];
void lsh()
{
	for(int i=1;i<=n;i++)
		help[i]=a[i],help[i+n]=b[i];
	sort(help+1,help+n*2+1);
	int cnt=unique(help+1,help+n*2+1)-help-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(help+1,help+cnt+1,a[i])-help,
		b[i]=lower_bound(help+1,help+cnt+1,b[i])-help;
}
int main(){
	freopen("maximum.in","r",stdin);
	freopen("maximum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	lsh();
	for(int i=1;i<=n;i++){
		bk[a[i]]++;
		book[a[i]]++;
		if(a[i]!=b[i])
		book[b[i]]++;
	}
	for(int i=1;i<=n*2;i++){
		if(book[i]>=n/2+(n&1)){
			ans=min(ans,max(n/2+(n&1)-bk[i],0));
		}
	}
	if(ans==0x7f7f7f7f)puts("Impossible");
	else printf("%d\n",ans);
	return 0;
}
