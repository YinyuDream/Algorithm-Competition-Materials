/*
给出一个n*m的棋盘(n、m≤80,n*m≤80)，要在棋盘上放k(k≤20)个棋子，使得任意两个棋子不相邻。
每次试验随机分配一种方案，求第一次出现合法方案时试验的期望次数，答案用既约分数表示。
*/

/*
Sol :SCR
	因为n,m<=80,n*m<=80，所以有m<=8或n<=8，假设m<=n.
	f[i][j][k]表示第i行状态为s[j]，前i行共放k个棋子的方案数。
	f[i][j][k]=sigma{f[i-1][p][k-c[j]]}，s[j]&s[p]==0
Time:O(n*pn*num^2)
Spc :O(pn*num)
*/
#include<cstdio>
#include<cstring>
const int maxs=100,maxm=81,maxpn=21;

typedef long long LL;
int n,m,pn,s[maxs],c[maxs];
LL f[2][maxs][maxpn],x1,x2,g;

void dfs(int p,int last,int now,int cnt)
{
	if(p==m){s[++s[0]]=now,c[s[0]]=cnt;return;}
	dfs(p+1,0,now*2,cnt);
	if(!last)dfs(p+1,1,now*2+1,cnt+1);
}

LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

LL calc_com(int n,int m)
{
	LL denom=1,numer=1;
	for(int i=2;i<=m;i++)denom*=i;
	for(int i=n-m+1;i<=n;i++)
	{
		numer*=i;
		g=gcd(numer,denom);
		numer/=g,denom/=g;
	}
	return numer;	
}

int main()
{
	scanf("%d%d%d",&n,&m,&pn);
	if(n<m)n^=m,m=n^m,n^=m;
	dfs(0,0,0,0);
	
	f[0][1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s[0];j++)
			for(int k=c[j];k<=pn;k++)
				for(int p=1;p<=s[0];p++)
					if(!(s[p]&s[j]) && k-c[j]>=c[p])
						f[i&1][j][k]+=f[1-i&1][p][k-c[j]];
		memset(f[1-i&1],0,sizeof(f[1-i&1]));
	}
	for(int i=1;i<=s[0];i++)x1+=f[n&1][i][pn];
	if(!x1){printf("Impossible!");return 0;}
	x2=calc_com(n*m,pn),g=gcd(x2,x1);
	printf("%I64d/%I64d\n",x2/g,x1/g);
	return 0;
}
