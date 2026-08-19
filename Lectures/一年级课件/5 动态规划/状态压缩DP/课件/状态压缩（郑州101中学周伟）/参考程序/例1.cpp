/*
在n*n(n≤20)的方格棋盘上放置n个车，某些格子不能放，求使它们不能互相攻击的方案总数。
*/

/*
Sol :SCR
Time:O(n*2^n)
Spc :O(2^n);
*/

#include<cstdio>
const int maxn=20+1,maxs=1<<20;

int n,m,a[maxn],p[maxn]={1};
long long f[maxs]={1};

int main()
{
	for(int i=1;i<maxn;i++)p[i]=p[i-1]*2;
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x]+=p[y-1];
	}
	for(int i=1,t,c;i<p[n];i++)
	{
		for(c=0,t=i;t;c++,t-=t&-t);
		for(t=i&~a[c];t;t-=t&-t)
			f[i]+=f[i^(t&-t)];
	}
	
	printf("%I64d\n",f[p[n]-1]);
	return 0;
}
