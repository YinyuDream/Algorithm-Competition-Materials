#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e5+10;
int n,m;
int h[maxn],a[maxn],pt;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&h[i]);
	for(int i=1;i<=m;i++)
	{
		int opt,p,x;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&p,&x);
			h[p]=x;
		}
		else
		{
			int cnt=0;
			pt=0;
			scanf("%d",&p);
			for(int j=p-1;j;j--)
			{
				if(pt==0||h[j]>a[pt])
				a[++pt]=h[j];
			}
			cnt+=pt;
			pt=0;
			for(int j=p+1;j<=n;j++)
			{
				if(pt==0||h[j]>a[pt])
				a[++pt]=h[j];
			}
			cnt+=pt;
			printf("%d\n",cnt+1);
		}
	}
	return 0;
}
