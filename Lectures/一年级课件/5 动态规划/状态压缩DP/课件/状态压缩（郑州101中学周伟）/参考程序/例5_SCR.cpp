/*
给出n*m (1≤n、m≤11)的方格棋盘，用1*2的长方形骨牌不重叠地覆盖这个棋盘，求覆盖满的方案数。

PKU.2411
*/

/*
Sol :SCR
Time:maxn*0.85*2.414^maxn
Spc :maxn^2*2^maxn
*/

#include<cstdio>
const int mn=11+1,ms=2048;
int n,m;
long long f[mn][mn][ms];

void dfs(int p,int s1,int s2)
{
	if(p>=mn)return;
	f[n][p][s1]+=f[n-1][p][s2];
	dfs(p+1,s1*2,s2*2+1);
	dfs(p+1,s1*2+1,s2*2);
	dfs(p+2,s1*4+3,s2*4+3);
}

int main()
{
	for(m=1;m<mn;m++)f[0][m][(1<<m)-1]=1;
	for(n=1;n<mn;n++)dfs(0,0,0);
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(!n)return 0;
		printf("%I64d\n",f[n][m][(1<<m)-1]);
	}
}
