#include<cstdio>
using namespace std;
int n,k,sum,s,c;
int main()
{
	scanf("%d",&n);
	int i=1;
	while(k<=n)
	{
		k+=i;
		i++;
	}
	k=i-2;
	for(int j=1;j<=k;j++)
	{
		sum=sum+j*j;
	}
	for(int s=1;s<=k;s++)
	{
		c=c+s;
	}
	k=n-c;
	k=k*(i-1);
	sum=sum+k;
	printf("%d",sum);
	return 0;
}
