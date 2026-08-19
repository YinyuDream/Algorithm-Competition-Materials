#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m;
int a[maxn],b[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
		if(b[lower_bound(b+1,b+m+1,a[i])-b]==a[i])printf("%d ",a[i]);
	return 0;
}