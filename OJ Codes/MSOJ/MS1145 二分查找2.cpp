#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,t;
bool bo;
int a[maxn];
int erfen(int L,int R,int x)
{
	while(L<=R)
	{
		int m=(L+R)/2;
		if(a[m]>=x)R=m-1;
		else L=m+1;
	}
	R++;
	if(a[R]!=x)bo=1;
	return R;	
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		bo=0;
		scanf("%d",&t);
		int k=erfen(1,n,t);
		if(bo==0)printf("%d\n",k);
		else printf("%d %d\n",k-1,k);
	}
	return 0;
}