#include<cstdio>
using namespace std;
int n,ans;
int a[110][110];
int s[110][110];
int max(int x,int y)
{
	if(x>y)return x;
	else return y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)scanf("%d",&a[i][j]);
	}
	s[1][1]=a[1][1];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)s[i][j]+=max(s[i-1][j-1],s[i-1][j])+a[i][j]; 
	}
	for(int i=1;i<=n;i++)ans=max(ans,s[n][i]);
	printf("%d",ans);
	return 0;
}
