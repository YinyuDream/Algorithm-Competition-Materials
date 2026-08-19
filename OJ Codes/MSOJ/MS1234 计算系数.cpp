#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,c,b;
long long a[1010][1010];
long long ans;
int main()
{
	scanf("%d%d%d%d%d",&c,&b,&k,&n,&m);
	for(int i=1;i<=n+m+1;i++)a[i][1]=1;
	for(int i=1;i<=n+m+1;i++)a[i][i]=1;
	for(int i=3;i<=n+m+1;i++)
	{
		for(int j=2;j<i;j++)a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
	ans=(long long)(pow(c,n)*pow(b,m)*a[m+n+1][m+1])%10003;
	printf("%d",ans);
	return 0;
}