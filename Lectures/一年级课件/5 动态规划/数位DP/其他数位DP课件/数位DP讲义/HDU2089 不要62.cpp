#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2000000;
int l,r,dp[20][2],a[N];
int dfs(int pos,int pre,bool sta,bool limit)
{
	if(pos==-1)return 1;
	if(!limit&&dp[pos][sta]!=-1)return dp[pos][sta];
	int up=limit?a[pos]:9;
	int tmp=0;
	for(int i=0;i<=up;i++)
	{
		if(pre==6&&i==2)continue;
		if(i==4)continue;
		tmp+=dfs(pos-1,i,i==6,limit&&i==a[pos]);
	}
	if(!limit)dp[pos][sta]=tmp;
	return tmp;
}
int solve(int x)
{
	int pos=0;
	while(x)
	{
		a[pos++]=x%10;
		x/=10;
	}
	dfs(pos-1,-1,0,1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	while(~scanf("%d%d",&l,&r)&&l+r)
	{	
		printf("%d\n",solve(r)-solve(l-1));
	}
}
