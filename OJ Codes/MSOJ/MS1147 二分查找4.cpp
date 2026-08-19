#include<cstdio>
#include<algorithm>
const int maxn=1e6+10;
using namespace std;
int n,m;
int a[maxn];
int find(int x)
{
	int p=lower_bound(a+1,a+n+1,x)-a;
	if(p==n+1)return 0;
	int q=upper_bound(a+1,a+n+1,x)-a;
	return q-p;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1,num;i<=m;i++)
		scanf("%d",&num),printf("%d\n",find(num));	
	return 0;
}
