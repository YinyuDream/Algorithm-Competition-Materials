#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5010;
ll x0;
int a,b,c,d;
int m,n,q;
int x[maxn*maxn],t[maxn*maxn];
struct node{
	int left,right;
}edge[maxn];
int main(){
	scanf("%lld%d%d%d%d%d%d%d",&x0,&a,&b,&c,&d,&n,&m,&q);
	x[0]=x0;
	for(int i=1;i<=n*m;i++)
	{
		x0 = x[i] = ((a * x0 + b) * x0 + c) % d;
		//x[i]=(a*x[i-1]*x[i-1]+b*x[i-1]+c)%d;
		t[i]=i;
	}
	for(int i=1;i<=n*m;i++)
	{
		swap(t[i],t[x[i]%i+1]);
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		swap(t[u],t[v]);
	}
	for(int i=1;i<=n*m;i++)
		x[t[i]]=i;
	for(int i=1;i<=n;i++)edge[i].left=0,edge[i].right=m+1;
	for(int i=1;i<=n*m;i++)
	{
		if(edge[(x[i]+m-1)/m].left<(x[i]-1)%m+1&&edge[(x[i]+m-1)/m].right>(x[i]-1)%m+1)
		{
			printf("%d ",i);
			for(int j=1;j<=(x[i]+m-1)/m-1;j++)edge[j].right=min(edge[j].right,(x[i]-1)%m+2);
			for(int j=(x[i]+m-1)/m+1;j<=n;j++)edge[j].left=max(edge[j].left,(x[i]-1)%m);
		}
	}
	return 0;
}