#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int L,R;
int a[20],dp[20][10];//dp[i][j]表示当前第i位，上一位是否位6的状态，0表示不为6，1表示为6 
int dfs(int pos,int pre,int lim){
	if(pos==-1) return 1;
	if(!lim && dp[pos][pre]!=-1) return dp[pos][pre];
	int up=lim?a[pos]:9;//条件语句，枚举上界 
	int temp=0;
	for(int i=0;i<=up;i++){
		if(i==4) continue;
		if(i==2 && pre==6) continue;
		temp+=dfs(pos-1,i,lim && i==a[pos]);
	}
	if(!lim) dp[pos][pre]=temp;
	return temp;
}
int solve(int x){
	int pos=0;
	while(x){
		a[pos++]=x%10; x=x/10;
	}
	return dfs(pos-1,-1,true);
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&L,&R);
	while(L+R>0){
		printf("%d\n",solve(R)-solve(L-1));
		scanf("%d%d",&L,&R);
	}
	return 0;
} 
