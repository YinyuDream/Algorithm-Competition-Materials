#include<cstdio>
using namespace std;
int n,m,s;
long long a[60][60];
int f(int x)
{
	int i=0; 
	for(;1;i++)
	{
		if(i*(i+1)/2>=n)break;
	}
	return i;
}
int main()
{	
	
	scanf("%d",&n);m=f(n)-1;
	for(int i=1;i<=m+1;i++)a[i][1]=1;
	for(int i=1;i<=m+1;i++)a[i][i]=1;
	for(int i=3;i<=m+1;i++)
	{
		for(int j=2;j<i;j++)a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
	m=n-(m*(m+1)/2);
	printf("%lld",a[f(n)][m]);
	return 0;
}