/*
在n*n(n≤10)的棋盘上放k个国王(可攻击相邻的8个格子)，求使它们无法互相攻击的方案数。
*/

/*
Sol	:SCR
Time:O(n*pn*num^2)
Spc :O(pn*num)
*/
#include<cstdio>
#include<cstring>

const int maxn=11,maxs=200;

int n,pn,s[maxs],c[maxs];
long long f[2][maxs][(maxn/2)*(maxn/2)],ans=0;

void dfs(int p,int last,int now,int cnt)
{
	if(p==n){s[++s[0]]=now,c[s[0]]=cnt;	return;}
	dfs(p+1,0,now*2,cnt);
	if(!last)dfs(p+1,1,now*2+1,cnt+1);
}

int main()
{
	scanf("%d%d",&n,&pn);
	if(pn>((n+1)/2)*((n+1)/2)){printf("0\n");return 0;}
	
	dfs(0,0,0,0);
	f[0][1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s[0];j++)
			for(int k=c[j];k<=pn;k++)
				for(int p=1;p<=s[0];p++)
					if(!(s[p]&s[j])&&!(s[p]&(s[j]<<1))&&!(s[p]&(s[j]>>1))&&k-c[j]>=c[p])
						f[i&1][j][k]+=f[1-i&1][p][k-c[j]];
		memset(f[1-i&1],0,sizeof(f[1-i&1]));
	}
	for(int i=1;i<=s[0];i++)ans+=f[n&1][i][pn];
	printf("%I64d\n",ans);
	
	return 0;
}
