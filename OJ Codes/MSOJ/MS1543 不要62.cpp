#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int maxn=25;
int l,r;
int a[maxn],dp[maxn][maxn];
int dfs(int pos,int pre,int lim)
{
	if(pos==-1) return 1;
	if(lim==0 && dp[pos][pre]!=-1) return dp[pos][pre];
	int up=lim?a[pos]:9;
	int temp=0;
	for(int i=0;i<=up;i++)
	{
		if(i==4||(i==2 && pre==6)) continue;
		temp+=dfs(pos-1,i,lim && i==a[pos]);
	}
	if(lim==0) 
	dp[pos][pre]=temp;
	return temp;
}
int solve(int x){
	int pos=0;
	while(x){
		a[pos++]=x%10; x=x/10;
	}
	return dfs(pos-1,-1,true);
}
main(){
	memset(dp,-1,sizeof(dp));
	scanf("%lld%lld",&l,&r);
	while(l+r>0){
		printf("%lld\n",solve(r)-solve(l-1));
		scanf("%lld%lld",&l,&r);
	}
	return 0;
}