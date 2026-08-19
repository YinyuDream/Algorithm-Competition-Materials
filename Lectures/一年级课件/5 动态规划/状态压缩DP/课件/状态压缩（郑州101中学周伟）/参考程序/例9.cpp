/*
有n(n≤20)头牛和m(m≤20)个牧场，每头牛都有若干个喜欢的牧场，它们都不喜欢和别的牛在同一个牧场
问有多少种分配方案使得每头牛都有自己的牧场。
*/
/*
Sol : SCR
Time: O(n*2^m)
Spc : O(2^m)
*/
#include<cstdio>
const int mn=20;
int n,m,f[1<<mn]={1},g[mn+1][mn+1];
char z[1<<mn];
int main()
{
	scanf("%d%d",&n,&m);
	if(n>m){puts("0");return 0;}
	for(int i=1,t1,t2;i<=n;i++)
	{
		scanf("%d",&t1);
		while(t1--)scanf("%d",&t2),g[i][t2]=1;
	}
	int c=0;
	for(int i=1,p,ms=1<<m;i<ms;i++)
	{
		p=z[i]=z[i>>1]+(i&1);
		if(p>n)continue;
		for(int ti=i,j=0;ti;ti>>=1,j++)
			if(ti&1&&g[p][j+1])f[i]+=f[i^(1<<j)];
		if(p==n)c+=f[i];
	}
	printf("%d\n",c);
	return 0;
}
