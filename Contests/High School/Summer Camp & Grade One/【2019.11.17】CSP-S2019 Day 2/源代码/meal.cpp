#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353,maxn=110;
int n,m,c;
int a[maxn][maxn*20];
int book[maxn],isuse[maxn],ans[maxn],st[maxn],top;
void dfs(int x,int k,int pre)
{
	if(x==0)
	{
		int t=1;
		for(int i=1;i<=top;i++)t=(t*st[i])%mod;//printf("%d,",st[i]);
		ans[k]=(t+ans[k])%mod;
		return ;
	}
	for(int i=pre;i<=n;i++)
	
		if(book[i]==0)
		{
			book[i]=1;
			for(int j=1;j<=m;j++)
				if(a[i][j]!=0&&isuse[j]<k/2)
				{
					isuse[j]++;
					st[++top]=a[i][j];
					dfs(x-1,k,i);
					isuse[j]-=1;
					top=top-1;
				}
			book[i]=0;		
		} 
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=n;i>=2;i--)dfs(i,i,1);
	for(int i=2;i<=n;i++)c=(c+ans[i])%mod;
	printf("%d",c%mod);	
	return 0;
}
