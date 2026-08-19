#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=35;
int n;
int a[maxn];
int dp[maxn][maxn],root[maxn][maxn];
void pt(int l,int r)
{
	if(l>r)return ;
	if(l==r){
		printf("%d ",l);return ;
	} 
	printf("%d ",root[l][r]);
	pt(l,root[l][r]-1);
	pt(root[l][r]+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		dp[i][i]=a[i],dp[i][i-1]=1;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			for(int k=i;k<=i+len-1;k++){
				if(dp[i][i+len-1]<dp[i][k-1]*dp[k+1][i+len-1]+a[k]){
					dp[i][i+len-1]=dp[i][k-1]*dp[k+1][i+len-1]+a[k],root[i][i+len-1]=k;	
				}
			}
				
		}
	}
	printf("%d\n",dp[1][n]);
	pt(1,n);
	return 0;
} 