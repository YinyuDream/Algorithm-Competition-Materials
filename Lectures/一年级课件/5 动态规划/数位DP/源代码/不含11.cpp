#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int L,R;
int a[20];
int dp[20][10];
int dfs(int pos,int pre,int lim)//lim表示枚举上界
{
	if(pos==-1) return 1;//递归边界 
	if(!lim && dp[pos][pre]!=-1) return dp[pos][pre];
	int up=lim?a[pos]:9;//up表示当前位值可枚举范围上界 
	int temp =0;
	for(int i=0;i<=up;i++){//枚举当前位可取的值 
		if(i==1 && pre==1) continue;//不合法的剔除
		temp+=dfs(pos-1,i,lim && i==a[pos]); //高位往低位枚举 
	}
	if(!lim) dp[pos][pre]=temp;//lim为真仅当所有位都取最高位的值 
	return temp;
}
int work(int x){
	int pos=0;
	while(x){
		a[pos++]=x%10; x/=10;
	}
	return dfs(pos-1,-1,true);
}
int main()
{
	scanf("%d%d",&L,&R);
	memset(dp,-1,sizeof(dp));
	int ans1=work(L-1);
	int ans2=work(R);
	printf("%d\n",ans2-ans1);
}

