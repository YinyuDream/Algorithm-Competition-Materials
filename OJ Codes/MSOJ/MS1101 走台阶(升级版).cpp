#include<cstdio>
using namespace std;
int n;
int a[1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[0]);
		if(a[0]==1)a[i]=-1;	
	}
	a[0]=1;
	if(a[1]==-1)a[1]=0;
	else a[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==-1)a[i]=0;
		else a[i]=(a[i-1]+a[i-2])%10000003;	
	}
		printf("%d",a[n]);
	return 0;
}
