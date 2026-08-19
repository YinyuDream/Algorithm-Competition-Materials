#include<cstdio>
using namespace std;
int n,maxn,sum;
bool a[12];
int v[12][12];
int b[12];
int c[12];
void dfs(int x)
{
    if(x==n+1)
    {
        if(maxn<sum)
        {
        	maxn=sum;
        	for(int i=1;i<=n;i++)c[i]=b[i];
		}
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
        	sum=sum+v[x][i];
            a[i]=1;
            b[x]=v[x][i];
            dfs(x+1);
            a[i]=0;
			sum=sum-v[x][i]; 
        } 
    }
    return ;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)scanf("%d",&v[i][j]);
	}
    dfs(1);
    printf("%d\n",maxn);
    for(int i=1;i<=n;i++)printf("%d\n",c[i]);
    return 0;
}
