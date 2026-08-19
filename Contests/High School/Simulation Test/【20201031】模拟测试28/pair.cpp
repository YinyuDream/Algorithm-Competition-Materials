#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,q;
int a[maxn],sum[maxn];
void update(int x)
{
	for(int i=x;i<=(1<<n);i+=i&(-i))
		sum[i]++;
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=i&(-i))
		ans+=sum[i];
	return ans;
}
int main(){
	freopen("pair.in","r",stdin);
	freopen("pair.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=(1<<n);i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1,k,ans;i<=q;i++){
		ans=0;
		scanf("%d",&k);
		for(int j=1;j<=(1<<n);j+=(1<<k))
		reverse(a+j,a+j+(1<<k));
		memset(sum,0,sizeof sum);
		for(int i=1<<n;i;i--){
			ans+=query(a[i]-1);
			update(a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
