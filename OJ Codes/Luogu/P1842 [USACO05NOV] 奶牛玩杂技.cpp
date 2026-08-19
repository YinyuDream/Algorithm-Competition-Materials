#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,sum,ans=-0x7f7f7f7f;
struct node{
	int w,s;
}a[maxn];
bool cmp(node a,node b)
{
	return a.w+a.s<b.w+b.s;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].w,&a[i].s);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,sum-a[i].s);
		sum+=a[i].w;
	}
	printf("%d",ans);
	return 0;
}
