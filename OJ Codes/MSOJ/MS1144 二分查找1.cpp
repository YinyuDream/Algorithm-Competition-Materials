#include<cstdio>
using namespace std;
int n,m;
int a[1000010];
bool bo=0;
int erfen(int left,int right,int x)
{
	bo=0;
	while(left<right)
	{
		int mid=(left+right)/2;
		if(x>=a[mid])left=mid+1;
		else right=mid; 
	}
	left--;
	if(a[left]<x)bo=1;
	return left;
}
int main()
{
	scanf("%d",&n);
	a[n+1]=1e9;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int k,x;
		scanf("%d",&k);
		x=erfen(1,n+1,k); 
		if(bo==0)printf("%d\n",x);
		else printf("%d %d\n",x,x+1);
	}
	return 0;
}