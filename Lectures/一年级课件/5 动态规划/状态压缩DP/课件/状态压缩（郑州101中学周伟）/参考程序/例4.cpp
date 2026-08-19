/*
给出一个n*m(n<=100,m<=10)的棋盘，一些格子('H')不能放置棋子。求最多能在棋盘上放置多少个棋子，使得每一行及每一列的任两个棋子距离大于等于2。

Sample Input
5 4
PHPP
PPHH
PPPP
PHPP
PHHP

Sample Output
6

http://acm.pku.edu.cn/JudgeOnline/problem?id=1185
*/

/*
Sol :SCDP
	f[i][j][k]表示第i行状态为s[j]，第i-1行状态为s[k]的最大放置数
	f[i][j][k]=max{f[i-1][k][l]}+c[j],要求s[j],s[k],s[l]互不冲突。
Time:O(n*num^3)s为一行的状态总数。对于m=10，sum=60
Spc :O(n*num^2)，滚动数组后O(num^2)
*/

#include<cstdio>
const int ms=61,mn=101,mm=11;

int n,m,ans=0,s[ms],c[ms],a[mn],f[2][ms][ms];
char tmp[mm];

void dfs(int p,int spc,int now,int cnt)
{
	if(p==m){s[++s[0]]=now,c[s[0]]=cnt;return;}
	dfs(p+1,spc+1,now*2,cnt);
	if(spc>=2)dfs(p+1,0,now*2+1,cnt+1);
}

int main()
{
 	scanf("%d%d",&n,&m);
	dfs(0,2,0,0);
	for(int i=1,ch;i<=n;i++)
	{
		scanf("%s",tmp+1);
		for(int j=1;j<=m;j++)
			a[i]=a[i]*2+(tmp[j]=='H');
		for(int j=1;j<=s[0];j++)
			if(!(s[j]&a[i]))
				for(int k=1;k<=s[0];k++)
					if(!(s[k]&(s[j]|a[i-1])))
						for(int l=1;l<=s[0];l++)
							if(!(s[l]&(a[i-2]|s[k]|s[j])))
								if(f[i&1][j][k]<f[1-i&1][k][l]+c[j])
								{
									f[i&1][j][k]=f[1-i&1][k][l]+c[j];
									if(f[i&1][j][k]>ans)ans=f[i&1][j][k];
								}
	}
								
	printf("%d\n",ans);
 	return 0;
}
