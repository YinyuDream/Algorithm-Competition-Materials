#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
long long a[20],dp[20][100000];//dp[i][j]表示到达第i位,余数为j的方案数。
void work(){
	for(int i=1;i<=9;i++){
		dp[1][i%m]+=1;
		//printf("%d %d\n",i%m ,dp[1][i%m]);
	}
	for(int i=1;i<n;i++){//枚举位数 
		for(int k=0;k<=9;k++){//当前位取值 
			for(int j=0;j<m;j++){//上一位(高位)的余数范围 
				dp[i+1][(j*10+k)%m]+=dp[i][j];
			}
		}
	}
	printf("%d\n",dp[n][0]);
}
long long dfs(int pos,int k)//dp[pos][k]表示枚举到当前pos位，余数位k的方案数
{
	if(dp[pos][k]!=0 || pos==1) return dp[pos][k];
	for(int i=0;i<=9;i++)//枚举当前位pos位的取值范围
	{
		for(int j=0;j<m;j++)//枚举pos-1位(高位)的的可能余数范围 
		{
			int yu=(j*10+i)%m; 
		 	if(k==yu) dp[pos][k]+=dfs(pos-1,j);
		}
	}
	return dp[pos][k];
} 
void answer(){
	for(int i=1;i<=9;i++) dp[1][i%m]+=1;
	for(int i=2;i<=n;i++){//枚举pos当前位 
		for(int h=0;h<m;h++){ //当前位的可能余数 
			for(int k=0;k<=9;k++){ //枚举pos当前位可取数的范围 
				for(int j=0;j<m;j++){ //枚举上一位的余数 
					if(h==(j*10+k)%m) dp[i][h]+=dp[i-1][j]; 
				}
			}
		}
	}
	for(int i=0;i<=m-1;i++){
		printf("%d %lld\n",i,dp[n][i]);
	}
} 
int main(){
	for(int y=1;y<=10;y++){
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		work();
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=9;i++) dp[1][i%m]+=1;//边界预处理 
		dfs(n,0);
		printf("--%d\n",dp[n][0]);
		//for(int i=0;i<m;i++) printf("%lld %d\n",dp[n-1][i],i); 
		//for(int i=0;i<m;i++ )printf("%d %lld\n",i,dp[n][i]);
	} 
	return 0;
} 
