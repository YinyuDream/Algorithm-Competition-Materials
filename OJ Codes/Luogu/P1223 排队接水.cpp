#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,sum[maxn];
long long ans;
struct node{
	int t,id;
}a[maxn];
bool cmp(node a,node b)
{
	if(a.t!=b.t)return a.t<b.t;
	else return a.id<b.id;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].t),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i].id);
	puts("");
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i].t;
	for(int i=1;i<=n;i++)
		ans+=sum[i];
	printf("%.2f",((double)ans-sum[n])/n); 
	return 0;
} 
