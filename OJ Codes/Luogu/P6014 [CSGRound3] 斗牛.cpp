#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn],sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((sum-a[i]-a[j])%10==0)
			{
				printf("%d",(a[i]+a[j])%10==0?10:(a[i]+a[j])%10);
				return 0;
			} 
		}
	}
	printf("0");
	return 0;
}