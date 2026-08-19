#include<cstdio>
using namespace std;

const int maxn=1e6+10;
int n,h[maxn],w[maxn];//h存储高度，w存储能量； 
int st[maxn];//st[]栈存储入栈发射塔的编号。 
int top;
long long sum[maxn];//求能量，累加。 
int main()
{
	//freopen("station.in","r",stdin);
	//freopen("station.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&h[i],&w[i]);
	st[++top]=1;
	for(int i=2;i<=n;i++)//找每个发射塔右边的边界。 
	{
		while(top>0 && h[i]>h[st[top]])
		//只有当前位置的发射高度大于栈顶高度，就找到了栈顶发射塔右边的边界。 
		{
			sum[i]+=w[st[top]];
			top--;
		}
		//出栈完，或栈为空，或当前高度小于栈顶发射塔高度，都入栈。 
		st[++top]=i;
	}
	top=0;
	st[++top]=n;//反过来入栈， 
	for(int i=n-1;i>=1;i--)//反过来，找左边边界 
	{
		while(top>0 && h[i]>h[st[top]])
		{
			sum[i]+=w[st[top]];
			top--;
		}
		st[++top]=i;
	}
	sum[0]=0;
	for(int i=1;i<=n;i++)//在所有发射塔接收的能量中，找到最大值。 
	{
		if(sum[0]<sum[i])sum[0]=sum[i];
	}
	printf("%lld",sum[0]);
	return 0;
} 
