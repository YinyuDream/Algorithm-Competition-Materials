#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
using namespace std;  
const int mod=1000000007;
long long l,r,dp[100][100];
int a[100];
long long dfs(int pos,int sum,bool lead,bool limit,int num)
{
	if(pos==-1)return sum;
	if(dp[pos][sum]!=-1&&!limit)return dp[pos][sum];
	long long tmp=0;
	int up=limit?a[pos]:9;
	for(int i=0;i<=up;i++)
	{
		tmp+=dfs(pos-1,sum+(i==num&&(lead||i)),i!=0||lead,limit&&i==a[pos],num);
	}
	if(lead&&!limit)dp[pos][sum]=tmp;
	return tmp;
}
long long solve(long long x,int num)
{
	int pos=0;
	while(x)
	{
		a[pos++]=x%10;
		x/=10;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(pos-1,0,0,1,num);
}
int main()
{
	scanf("%lld%lld",&l,&r);
	for(int i=0;i<=9;i++)printf("%lld ",solve(r,i)-solve(l-1,i));
}
