#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10,p=1e9+7;
char a[maxn],b[maxn];
int num[maxn],dp[maxn][10][10][2];//i-1最后一位是j,最后二位是k,有无回文串的总个数;
int dfs(int pos,int pre,int per,int lim,int zero,int use)//i--1位回文总个数 
{
	if(pos==0)return !use;
	if(pre!=-1&&per!=-1&&!lim&&!zero&&dp[pos][pre][per][use]!=-1)
	return dp[pos][pre][per][use];
	int up=lim?num[pos]:9,ans=0;
	for(int i=0;i<=up;i++)
	{
		int p=(zero&&i==0)?-1:i;
		//ans+=dfs(pos-1,p,pre,lim&&(p==up),p==-1,use|(p!=-1&&(p==pre||p==per)));
		if((use==0&&i!=per&&i!=pre)||zero)
		ans+=dfs(pos-1,i,pre,lim&&i==up,!i&&zero,use);
		else if(use==1)
		{
			if(i==pre||i==per)
			ans+=dfs(pos-1,i,pre,lim&&i==up,!i&&zero,0);
			else
			ans+=dfs(pos-1,i,pre,lim&&i==up,!i&&zero,1);
		}
	}
	if(!lim&&!zero&&pre!=-1&&per!=-1)
	dp[pos][pre][per][use]=ans;
	return ans;
}
int work(char *s,bool opt)
{
	memset(dp,-1,sizeof dp);
	int len=strlen(s);
	for(int i=1;i<=len;i++)
	num[i]=a[i]-'0';
	reverse(num+1,num+len+1);
	if(opt){
		int now=1;
		while(num[now]==0)
		num[now++]=9;
		num[now]--;
		while(!num[len]&&len)len--;
	}
	return dfs(len,-1,-1,1,1,1);
}
int main(){
	scanf("%s\n%s",a+1,b+1);
	printf("%d\n",work(b+1,0)-work(a+1,1));
	return 0;
}
