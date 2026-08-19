#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=13;
const int maxm=1<<maxn;//maxm=9000
const int mod=100000000;
int map[maxm];//map[i]表示给出第i行地的状态。
int st[maxm];//st表示每一行的状态，即预处理出来每一行没有相邻为1的合法状态。 
int dp[maxn][maxm];//dp[i][j]表示在第i行状态为j时候可以放牛的种数 
int n,m;
int k;//k记录每一行最多可以枚举的状态数 

bool judge1(int x)//判断是否存在相邻位为1的情况 
{
	return (x&(x<<1));
}
bool judge2(int i,int j)//判断第i行土地状态与第j个状态是否可以合法，即判断放牛的土地上是否是肥沃的。 
{
	return ((~map[i])&st[j]);
	//return (map[i]&st[j]);
} 
bool judge3(int i,int j)
{
	return (st[i]&st[j]);//判断状态i和状态j相同位是否为1,只要有一位相同就不行（上下相邻） 
} 
void init()
{
	int x;
	memset(map,sizeof(map),0);
	memset(dp,sizeof(dp),0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			if(x==0)  map[i]+=(1<<(m-j));
			//if(x==1) map[i]+=(1<<(m-j));
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",map[i]);
	}
	printf("\n");
	k=0;
	for(int i=0;i<(1<<m);i++)//预处理每行的可行状态 
	{
		if(!judge1(i))
		{
			st[k++]=i;
		}
	}
} 
void work()
{
	//处理第1行的所有可行方案
	for(int i=0;i<k;i++)
	{
		if(!judge2(1,i))//第1行第i个状态是否可以放牛 
		{
			dp[1][i]=1;
			printf("1-->%d: %d\n",i,dp[1][i]);
		}
	} 
	//处理第i行的情况
	for(int i=2;i<=n;i++)//枚举行 
	{
		for(int j=0;j<k;j++)//枚举第i行的状态
		{
			if(judge2(i,j)) //判断第i行，假如按第j个状态放牛不行。 (土地不满足)
		    	continue; 
			for(int s=0;s<k;s++)//枚举i-1行不冲突的方案来计算第i行状态j的方案总数 
			{
				if(judge2(i-1,s))//判断第i-1行，假如按第j个状态放牛不行。(土地不满足)
			    	continue;
				if(!judge3(j,s))
				{
					dp[i][j]+=dp[i-1][s];
					dp[i][j]%=mod;
				}
			    	
			} 
		} 
	} 
	int ans=0;
	for(int i=0;i<k;i++)
	{
		ans+=dp[n][i];
		ans%=mod;
	} 
	printf("\n%d\n",ans);
} 
int main()
{
	init();
	work();
	return 0;
}

