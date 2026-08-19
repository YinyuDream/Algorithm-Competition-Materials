#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int a[100];
int s=0;
void dfs(int k,int x,int y)//第k位置分解的值为x,能分解成不得小于y 
{
	//if(x==0) return;
	if(x<n){//先输出方案，然后往下递归。 
		s++;
		printf("%d:7=",s);
		for(int i=1;i<k;i++) printf("%d+",a[i]);
		printf("%d\n",x);
	}
	for(int i=y;i<=x;i++)
	{
		a[k]=i;
		if(x-i>=i)
		{
			dfs(k+1,x-i,i);
		}
	}
} 
void dfs2(int k,int x,int y)//第k位置拆分的值x且不得低于y 
{
	if(x==0 && a[k-1]<n)//特点一直分解到不能分解为止,才输出方案 
	{
		printf("%d=",n); 
		for(int i=1;i<k-1;i++) printf("%d+",a[i]); 
		printf("%d\n",a[k-1]);
	}
	else
	{
		for(int i=y;i<=x;i++)
		{
			a[k]=i;
			dfs2(k+1,x-i,i);
		} 
	} 
}
void dfs3(int k,int x,int y)//第i位置分解的值为x,能分解成不得小于y 
{
	//if(x==0) return;
	if(x<=m){//先输出方案，然后往下递归。 
		s++;
		printf("%d:7=",s);
		for(int i=1;i<k;i++) printf("%d+",a[i]);
		printf("%d\n",x);
	}
	for(int i=y;i<=x;i++)
	{
		a[k]=i;
		if(x-i>=i)
		{
			dfs3(k+1,x-i,i);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	dfs(1,n,1);
	return 0;
}
