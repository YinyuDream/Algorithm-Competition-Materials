#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
const double T0=1e5;
const double T_end=1e-3;
const double V=1-3e-3;
int n,m,k,next[100],d[100],v[100],ans=1e9,dis[100],s[100],top,book[100];
double st=clock();
int min(int a,int b)
{
	return a<b?a:b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
void fz()
{
	for (int i=0;i<n;i++)
	{
		if (top>=k)break;
		if (v[i]==0)
		{
			book[i]=1;
			s[++top]=i;
		}
	}
}
int js()
{
	int cnt=0,flag=1; 
	for (int i=0;i<n;i++)
		dis[i]=1e9;
	for (int i=0;i<n;i++)
		if (book[i]||v[i])dis[i]=0;
	while(flag==1)
	{
		flag=0;
		for (int j=0;j<n;j++)
		{
			if (dis[next[j]]+d[j]<dis[j]){flag=1;dis[j]=dis[next[j]]+d[j];};
			if (dis[next[j]]>dis[j]+d[j]){flag=1;dis[next[j]]=dis[j]+d[j];};
		}
	}
	for (int i=0;i<n;i++)
		cnt=cnt>dis[i]?cnt:dis[i];
	return cnt;
}
void SA()
{
	fz();
	double T=T0;int res=js();
	ans=min(ans,res);
	while (T>T_end)
	{
		for (int i=1;i<=20;++i)
		{
			int x=rand()%n;
			if (book[x]==1||v[x]==1)continue;
			int y=rand()%top+1;
			int z=s[y];
			s[y]=x;
			book[z]=0;book[x]=1;
			int tmp=js();
			int de=res-tmp;
			if (de>0)
			{
				res=tmp;
				ans=min(ans,res);
			}
			else if (exp(de/T)>(double)rand()/(double)RAND_MAX)
				res=tmp;
			else
			{
				s[y]=z;
				book[z]=1;book[x]=0;
			}
		}
		T*=V;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if (m+k==n)
	{
		printf("0");
		return 0;
	}
	for (int i=0;i<n;i++)
		scanf("%d",&next[i]);
	for (int i=0;i<n;i++)
		scanf("%d",&d[i]);
	for (int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		v[x]=1;
	}	
	if (k==0)
	{
		printf("%d",js());
		return 0;
	}
	while (clock()-st<0.25*CLOCKS_PER_SEC)SA();
	printf("%d",ans);
	return 0;
}