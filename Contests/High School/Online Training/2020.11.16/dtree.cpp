#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,ans;
int a[maxn];
int solve(int l,int r)
{
	if(l>r)return 0;
	int p=0;
	for(int i=l;i<=r;i++)
		if(!p||a[p]<a[i])p=i;
	int t1=solve(l,p-1);
	int t2=solve(p+1,r);
	if(l<=p-1&&p+1<=r)ans+=t2-t1;
	ans%=k;
	return p;
}
int main(){
	freopen("dtree.in","r",stdin);
	freopen("dtree.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		a[i]=i;
	do{
		solve(1,n);
	}while(next_permutation(a+1,a+n+1));
	printf("%d\n",ans);
	return 0;
}
