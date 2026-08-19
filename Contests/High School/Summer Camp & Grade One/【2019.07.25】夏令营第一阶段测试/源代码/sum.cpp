#include<cstdio>
using namespace std;
int N;
int a[200020],maxn,sum;
int b[200020];
int dfs()
{
	for(int i=1;i<=N;i++)
	{
		sum=a[i];
		for(int j=i+1;j<=N;j++)
		{
			sum+=a[j];
			if(maxn<sum)maxn=sum;
		}
	}
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d",&a[i]);
	{
		dfs();printf("%d",maxn);
	}
	return 0;
}
