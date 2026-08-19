#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=20;
ll l,r,a[maxn];
ll dp[maxn][maxn];
ll dfs(int pos,int limit,int flag,int num,int sum)
{
	if(pos==-1)
	return sum;
	if(!limit&&flag&&dp[pos][sum]!=-1)
	return dp[pos][sum];
	int up=limit?a[pos]:9;
	ll ans=0;
	for(int i=0;i<=up;i++)
	ans+=dfs(pos-1,limit&&i==a[pos],flag||i,num,sum+((i||flag)&&(i==num)));
	if(!limit&&flag)
	dp[pos][sum]=ans;
	return ans;
}
ll work(ll x,int k)
{
	
	int t=0;
	while(x){
		a[t++]=x%10;
		x/=10;
	}
	return dfs(t-1,1,0,k,0);
}
int main(){
	memset(dp,-1,sizeof dp);
	scanf("%lld",&r);
	ll ans=0;
	for(int i=0;i<=9;i++)
	ans+=work(r,i)*i;
	printf("%lld\n",ans);
	return 0;
}
