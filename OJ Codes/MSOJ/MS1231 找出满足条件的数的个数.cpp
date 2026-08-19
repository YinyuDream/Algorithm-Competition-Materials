#include<cstdio>
using namespace std;
int n,m,cnt,k;
long long a[500][500];
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
	
	scanf("%d%d",&n,&k);m=f(n)-1;
	for(int i=1;i<=m+1;i++)a[i][1]=1;
	for(int i=1;i<=m+1;i++)a[i][i]=1;
	for(int i=3;i<=m+1;i++)
	{
		for(int j=2;j<i;j++)a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
	m=n-(m*(m+1)/2);
	for(int i=1;i<=f(n)-1;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i][j]%k==0)cnt++;
		}
	}
	for(int j=1;j<=m;j++)
		{
			if(a[f(n)][j]%k==0)cnt++;
		}
	printf("%d",cnt);
	return 0;
}
