#include<cstdio>
using namespace std;
const int maxn=5e5+10;
int n,m,t;
int a[maxn],c[maxn];
inline void update(int x,int val)
{
	while(x<=n)
	{
		c[x]+=val;
		x+=(x&-x);
	}
}
inline int getsum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=(x&-x);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&t),update(i,t);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)
		{
			update(x,y);
		}
		if(opt==2)
		{
			printf("%d\n",getsum(y)-getsum(x-1));
		}
	}
	return 0;
}
