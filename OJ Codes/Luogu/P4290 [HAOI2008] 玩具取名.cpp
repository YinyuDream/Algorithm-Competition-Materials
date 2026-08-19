#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int W,I,N,G;
char a[]={'\0','W','I','N','G'};
char change[130][20][2];
int t[130];
int dp[210][210][130];
char name[210];
bool dfs(int l,int r,char k)
{
	if(l==r)return (name[l]==k);
	if(dp[l][r][k]!=-1)return dp[l][r][k];
	for(int i=1;i<=t[k];i++)
		for(int j=l;j<=r-1;j++)
			if(dfs(l,j,change[k][i][0])&&dfs(j+1,r,change[k][i][1]))
			return dp[l][r][k]=true;
	return dp[l][r][k]=false;
}
int main(){
	scanf("%d%d%d%d",&W,&I,&N,&G);
	for(int i=1;i<=W;i++)
		scanf(" %c%c",&change['W'][i][0],&change['W'][i][1]);
	for(int i=1;i<=I;i++)
		scanf(" %c%c",&change['I'][i][0],&change['I'][i][1]);
	for(int i=1;i<=N;i++)
		scanf(" %c%c",&change['N'][i][0],&change['N'][i][1]);
	for(int i=1;i<=G;i++)
		scanf(" %c%c",&change['G'][i][0],&change['G'][i][1]);
	scanf("%s",name+1);
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=strlen(name+1);i++)
		dp[i][i][name[i]]=1;
	t['W']=W,t['I']=I,t['N']=N,t['G']=G;
	bool bo=true;
	for(int i=1;i<=4;i++)
		if(dfs(1,strlen(name+1),a[i]))printf("%c",a[i]),bo=false;
	if(bo)printf("The name is wrong!");
	return 0;
}
