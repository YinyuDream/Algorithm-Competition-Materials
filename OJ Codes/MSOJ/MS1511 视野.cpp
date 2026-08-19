#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int n,m;
int l[maxn],r[maxn];
struct node{
	int l,r;
}t[maxn];
int main(){
	//freopen("vision.in","r",stdin);
	//freopen("vision.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		r[i]=l[i]+r[i]-1;
	}
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&t[i].l,&t[i].r);
		t[i].r=t[i].l+t[i].r-1;
	}
	for(int i=1;i<=m;i++)
	{
		int t1=lower_bound(r+1,r+n+1,t[i].l)-r-1;
		int t2=n-(upper_bound(l+1,l+n+1,t[i].r)-l-1);
		if(t1==n+1)t1=0;
		if(t2==n+1)t2=0;
		printf("%d\n",n-t1-t2);
	}
	return 0;
}