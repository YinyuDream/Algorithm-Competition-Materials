#include<cstdio>
using namespace std;
const int maxn=13,p=1e8;
int n,m;
int mapp[maxn],st[1<<maxn-1],top;
int dp[maxn][1<<maxn-1];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,tmp;i<=n;i++)//读入数据 
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&tmp);
			if(tmp==1)mapp[i]+=(1<<(j-1));
		}
	for(int i=0;i<=(1<<m)-1;i++)//所有可行的状态 
	{
		if(!(i&(i<<1)))
		st[top++]=i;
	}
	for(int i=0;i<top;i++)//第一行可能的状态 
	{
		if(!((~mapp[1])&st[i]))
		dp[1][st[i]]=1;
	}
	for(int i=2;i<=n;i++)//枚举2---n行 
	{
		for(int j=0;j<top;j++)//枚举所有可能的状态
		{
			if((~mapp[i])&st[j])continue;
			for(int k=0;k<top;k++)//枚举上一行可能的状态 
			{
				if(st[j]&st[k])continue;
				dp[i][st[j]]+=dp[i-1][st[k]];
				dp[i][st[j]]%=p;
			}
		} 
	}
	int ans=0;
	for(int i=0;i<=(1<<m)-1;i++)
		ans=(ans+dp[n][i])%p;
	printf("%d",ans%p);
	return 0;
}
