#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
int n,m,k,book,ans=0x7f7f7f7f;
int up[maxn],down[maxn],maxm;
int dp[maxn][maxn];
struct node{
	int l,h;
	bool flag;
}p[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	scanf("%d%d",&up[i],&down[i]);
	for(int i=1;i<=k;i++){
		int q,l,h;
		scanf("%d",&q);
		scanf("%d%d",&p[q].l,&p[q].h);
		p[q].flag=1;
	}
	for(int i=0;i<n;i++){
		if(p[i].flag==0){
			p[i].h=m+1;
		}
	}
	memset(dp,0x7f,sizeof dp);
	for(int i=1;i<=m;i++)
	dp[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=p[i].l+1;j<=p[i].h-1;j++){
			for(int k=1;j-k*up[i-1]>0;k++){
				if(j-k*up[i-1]>p[i-1].l&&j-k*up[i-1]<p[i-1].h){
					dp[i][j]=min(dp[i][j],dp[i-1][j-k*up[i-1]]+k);
					maxm=max(maxm,i);
				}
			}
			if(j+down[i-1]<=m&&j+down[i-1]>p[i-1].l&&j+down[i-1]<p[i-1].h)		
			dp[i][j]=min(dp[i][j],dp[i-1][j+down[i-1]]),maxm=max(maxm,i);
		}
		for(int j=m-up[i-1]+1;j<=m;j++){
			if(j>p[i-1].l&&j<p[i-1].h){
				dp[i][m]=min(dp[i][m],dp[i-1][j]+1);
			}
		}
	}
	for(int i=1;i<=m;i++)
		if(dp[n][i]!=0x7f7f7f7f)
			book=1,ans=min(ans,dp[n][i]);
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			printf("%d ",dp[i][j]);
			puts("");
		}
	if(book){
		printf("%d\n%d",1,ans);
	}else{
		printf("%d\n%d",0,maxm);
	}
}
