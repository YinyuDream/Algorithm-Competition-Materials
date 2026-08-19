#include<cstdio>
using namespace std;
int a[100000];
int s[100000];
int n,x,y,maxx=1,minx=1,sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[n+1]=a[1];a[n+2]=a[2];a[n+3]=a[3];
	s[1]=a[1]+a[2]+a[3]+a[4]; 
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]-a[i-1]+a[i+3];
		if(s[i]>s[maxx])maxx=i;
		if(s[i]<s[minx])minx=i;
	}
	printf("%d %d",maxx,minx);
	return 0;
}
