#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[100010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)printf("%d ",a[i]);
	return 0;
}