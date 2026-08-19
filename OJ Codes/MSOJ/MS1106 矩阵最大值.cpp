#include<cstdio>
using namespace std;
int n,m;
int maxn,maxm,minn,minm,maxx,minx=10000000; 
int a[110][110];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		scanf("%d",&a[i][j]);
		if(a[i][j]>maxx){maxn=i;maxm=j;maxx=a[i][j];}
		if(a[i][j]<minx){minn=i;minm=j;minx=a[i][j];}
		} 
	}
	printf("%d %d\n%d %d",maxn,maxm,minn,minm);
	return 0;
}
