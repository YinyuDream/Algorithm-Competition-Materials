#include<cstdio>
using namespace std;
long long n,ans;
int a[]={0,2,5,10,20,50,100};
int main()
{
	scanf("%lld",&n);
	for(int i=6;i>=1;i--)
	{
		if(n%a[i]==1||n%a[i]==3)
		ans+=n/a[i]-1, 
		n%=a[i],
		n+=a[i];
		else
		ans+=n/a[i],
		n%=a[i];
	}
	printf("%lld",ans);
}
