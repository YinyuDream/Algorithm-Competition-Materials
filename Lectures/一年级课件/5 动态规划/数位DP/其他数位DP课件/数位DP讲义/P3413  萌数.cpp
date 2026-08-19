#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
using namespace std;  
const int mod=1000000007;
long long dp[1000+1][2];
int a[1001],b[1001],c[1001],d[1001];
char l[1001],r[1001];
int dfs(int pos,int pre,int per,bool sta,bool lead,bool limit)
{
	if(pos==-1)return sta;
	if(!limit&&dp[pos][sta]!=-1)return dp[pos][sta];
	int up=limit?a[pos]:9;
	int tmp=0;
	for(int i=0;i<=up;i++)
	tmp=(tmp+dfs(pos-1,i,lead?pre:-1,sta||((i==pre)&&lead)||((i==per)&&lead),lead||(i!=0),limit&&(i==a[pos]))%mod)%mod;
	if(!limit&&lead&&per!=-1)dp[pos][sta]=tmp;
	return tmp;
}
int solve(int x[],int len)
{
	memset(dp,-1,sizeof(dp));
	int pos=0;
	for(int i=len;i>=1;i--)a[pos++]=x[i];
	dfs(pos-1,-1,-1,0,0,1);
}
int main()
{
	scanf("%s %s",l+1,r+1);
	int lenl=strlen(l+1),lenr=strlen(r+1);
	for(int i=1;i<=lenl;i++)b[i]=l[i]-'0';
	for(int i=1;i<=lenr;i++)c[i]=r[i]-'0';
	int pos=lenl;
	if(b[lenl]==0)
	{
		if(lenl==1)b[lenl]-=1;
		else while(b[pos]==0)b[pos]=9,pos--;
		b[pos]-=1;
	}
	else if(b[lenl]!=0)b[lenl]-=1;
	pos=1;
	while(b[pos]==0&&lenl>1)pos++;
	int j=1;
	for(int i=pos;i<=lenl;i++,j++)
	{
		d[j]=b[i];
	}
	lenl=j-1;
	printf("%d",(solve(c,lenr)-solve(d,lenl)+mod)%mod);
}
