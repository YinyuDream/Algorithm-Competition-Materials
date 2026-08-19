#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<bitset>
#include<stack>
#include<ctime>
#define dd double
#define ll long long
#define mp make_pair
#define pb push_back
#define N 100010
#define M 1010
using namespace std;
int n,m,Q;
int a[N],op[N],x[N],y[N];
int pre[N];
int ne[N],la[N];
int cnt;
void ins(int x)
{
	if(la[x]==pre[x]) cnt++;
}
void del(int x)
{
	if(la[x]==pre[x]) cnt--;
}
void doit()
{
	memset(pre,0,sizeof(pre));
	memset(ne,0,sizeof(ne));
	memset(la,0,sizeof(la));
	int k,u=n+3,v;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&v);
		pre[v]=u;
		u=v;
	}
	pre[n+4]=u;
	cnt=0;
	for(int i=0;i<=n;i++)
	{
		ne[a[i]]=a[i+1];
		la[a[i+1]]=a[i];
		ins(a[i+1]);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int t=x[i],w=y[i];
		if(op[i]==1)
		{
			del(t);
			del(ne[t]);
			la[ne[t]]=la[t];
			ne[la[t]]=ne[t];
			ins(ne[t]);
		}
		else
		{
			if(!t) t=n+1;
			del(ne[t]);
			la[w]=t;
			ne[w]=ne[t];
			la[ne[t]]=w;
			ne[t]=w;
			ins(w);
			ins(ne[w]);
		}
		if(cnt==k-1) ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	cin>>n>>m>>Q;
	a[0]=n+1;
	a[n+1]=n+2;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&op[i],&x[i]);
		if(op[i]==2) scanf("%d",&y[i]); 
	}
	while(Q--) doit();
}