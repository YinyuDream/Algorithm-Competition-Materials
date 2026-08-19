#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100010;
int n,top,maxs,maxb,maxe;
int a[maxn];

struct mj
{
	int ss;
	int bg;
	int ed;
};
struct qiang
{
	int hi;
	int bh;
};
qiang stack[maxn];
mj s[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++)
	{
		while(stack[top].hi>a[i]&&top>0)
		{
			s[stack[top].bh].ss=(i-stack[top].bh)*stack[top].hi;
			s[stack[top].bh].bg=stack[top].bh;
			s[stack[top].bh].ed=i-1;
			top--;
		}
		stack[++top].bh=i;stack[top].hi=a[i];
	}
	for(int i=n;i>=0;i--)
	{
		while(stack[top].hi>a[i]&&top>0)
		{
			s[stack[top].bh].ss+=((stack[top].bh-i)*stack[top].hi)-stack[top].hi;
			s[stack[top].bh].ed=max(stack[top].bh,s[stack[top].bh].ed);
			s[stack[top].bh].bg=min(i+1,s[stack[top].bh].bg);
			top--;
		}
		stack[++top].hi=a[i];stack[top].bh=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i].ss>=maxs)
		{
			maxs=s[i].ss;
			maxb=s[i].bg;
			maxe=s[i].ed;
		}
	}
	printf("%d\n%d %d",maxs,maxb,maxe);
	//if(maxs==20005000)printf("%d %d %d %d",a[4999],a[5000],a[5001],a[5002])
	return 0;
}
