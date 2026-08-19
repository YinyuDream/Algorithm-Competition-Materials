#include<cstdio>
#define ll long long
using namespace std;
const int maxn=12;
ll l,r;
int num[maxn],dp[maxn][maxn][maxn][2][2][2][2];
void dfs(int pos,int pre,int per,bool _4,bool _8,bool limit,bool zero)
{
	if(pos==-1)return 1;
	if(dp[pos][pre][per][_4][_8][limit][zero]!=-1)
	return dp[pos][pre][per][_4][limit][zero];
	int up=limit?num[pos]:9,ans=0;
	for(int i=0;i<=up;i++)
	{
		
	}
}
ll work(ll x)
{
	int top=0;
	while(x){
		num[top++]=x%10;
		x/=10;	
	} 
	top--;
	return dfs(top,1,1,1,1,3,1);
}
int main(){
	scanf("%lld%lld",&l,&r);
	printf("%lld",work(r)-work(l-1));
	return 0;
} 
