#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,t;
bool bo;
int a[maxn];
int left,right;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t);
		left=1;right=n;
		while(left<=right)
		{
			int mid=(left+right)/2;
			if(a[mid]<=t)left=mid+1;
			else right=mid-1;
		}
		if(a[left-1]!=t)printf("%d %d\n",left-1,left);
		else printf("%d\n",left-1);
	}
	return 0;
}