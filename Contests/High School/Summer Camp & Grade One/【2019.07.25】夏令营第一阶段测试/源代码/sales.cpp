#include<cstdio>
using namespace std;
int n,s,minn=10000,sum;
int a[30][30];
bool bo[30];
int b[30];
void dfs(int k)
{
	if(k==n+1)
	{sum+=a[b[k-1]][1];
		if(minn>sum)minn=sum;
		sum-=a[b[k-1]][1];
	}
	else
	{
		for(int i=2;i<=n;i++){
			if(bo[i]==0){
				bo[i]=1;b[k]=i;sum+=a[b[k-1]][i];dfs(k+1);bo[i]=0;sum-=a[b[k-1]][i];
			}
		}
	}
}
int main()
{
	freopen("sales.in","r",stdin);
	freopen("sales.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	b[1]=1;
	dfs(2);
	printf("%d",minn);
	return 0;
}
