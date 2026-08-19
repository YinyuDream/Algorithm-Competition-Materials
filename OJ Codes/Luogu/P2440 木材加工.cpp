#include<cstdio>
using namespace std;

const int maxn=1e6+10;
long long n,k,a[maxn],sum;

bool check(long long x)
{
	long long m=0;
	for(int i=1;i<=n;i++)
		m+=a[i]/x;
	if(m>=k)return 1;
	else return 0;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);sum+=a[i];
	}
	sum=sum/k+1;
	long long left=1,right=sum;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(check(mid))left=mid+1;
		else right=mid-1;
	}
	printf("%lld",right);
	return 0;
}
