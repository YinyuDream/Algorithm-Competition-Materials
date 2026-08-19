#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int left=1,right=n;
	while(left+1<right)
	{
		int mid=(left+right)/2;
		if(a[mid]>=0)right=mid;
		else left=mid;
	}
	printf("%d",min(abs(a[left]),abs(a[right])));
}
