#include<cstdio>
#include<algorithm>
using namespace std;

int n,sum,cnt;
int a[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sum=sum/n;
	for(int i=1;i<=n;i++)
	{
		int temp=a[i]-sum;
		if(temp!=0)
		{
			a[i]-=temp;
			a[i+1]+=temp;
			cnt++;
		}
	}
	printf("%d",cnt);
}