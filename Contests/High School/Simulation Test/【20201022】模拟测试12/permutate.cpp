#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,mx;
int a[maxn],book[maxn],ans[maxn];
int main(){
	freopen("permutate.in","r",stdin);
	freopen("permutate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans[i]=++book[a[i]];
		mx=max(mx,book[a[i]]);
	}
	for(int i=1;i<n;i++)
		if(book[i]<book[i+1])
			return puts("-1"),0;
	printf("%d\n",mx);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
