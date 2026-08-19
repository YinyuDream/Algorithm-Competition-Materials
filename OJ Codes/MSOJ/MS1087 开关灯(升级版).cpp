#include<cstdio>
using namespace std;
int n,m;
bool bo[100010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<=n;j+=i)
		if(bo[j]==1)bo[j]=0;
		else bo[j]=1;
	}
	printf("1");
	for(int i=2;i<=n;i++)
	{
		if(bo[i]==0)printf(",%d",i);
	}
}
