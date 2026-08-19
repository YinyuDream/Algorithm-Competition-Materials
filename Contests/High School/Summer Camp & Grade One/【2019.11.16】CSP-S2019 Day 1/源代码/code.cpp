#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=70;
int n;
long long k;
int ans[maxn],top=maxn-1;
void dfs(int x,long long k)
{
	if(x==1)
		{
			if(k==1) ans[top--]=0;
			else  ans[top--]=1;
			return ;
		}
	long long s=(long long)pow(2,x)>>1;
	if(k<=s)dfs(x-1,k),ans[top--]=0;
	else dfs(x-1,s*2-k+1),ans[top--]=1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%lld",&n,&k);
	dfs(n,k+1);
	for(int i=top+1;i<=maxn-1;i++)
	printf("%d",ans[i]);
	return 0;
}
