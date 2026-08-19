#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,k,l,r,ans;
int a[maxn];
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+k+1,cmp);
	l=1,r=n;
	for(int i=1;i<=k&&l<=r;i++)
	ans+=(r-l)*a[i],r--,l++;
	printf("%d",ans);
	return 0;
}