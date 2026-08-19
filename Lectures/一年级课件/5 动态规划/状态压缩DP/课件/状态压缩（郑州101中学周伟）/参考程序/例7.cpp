/*
给出n*m(n,m≤10)的方格棋盘，用1*r的长方形骨牌不重叠地覆盖这个棋盘，求覆盖满的方案数。
*/

/*
Sol	:SCR
Time:...
Spc :...
*/
#include<cstdio>
#include<cstring>
const int maxs=10000000;
int r,n,m,ln,p[15]={1};
long long f[2][maxs];

void dfs(int d,int s1,int s2)
{
	if(d>m)return;
	if(d==m){f[ln&1][s1]+=f[ln&1^1][s2];return;}
	for(int i=0;i<r;i++)dfs(d+1,s1*r+i,s2*r+(i+1)%r);
	dfs(d+r,s1*p[r]+p[r]-1,s2*p[r]+p[r]-1);
}

int main()
{
	scanf("%d%d%d",&r,&n,&m);
	if(n%r && m%r){printf("0\n");return 0;}
	if(n<m)n^=m,m=n^m,n^=m;
	for(int i=1;i<=m;i++)p[i]=p[i-1]*r;
	f[0][p[m]-1]=1;
	for(ln=1;ln<=n;ln++)
	{
		dfs(0,0,0);
		for(int i=0;i<p[m];f[ln&1^1][i++]=0);
	}
	printf("%I64d\n",f[n&1][p[m]-1]);
	return 0;
} 
