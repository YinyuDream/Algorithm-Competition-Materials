#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,h[maxn],w[maxn];
int st[maxn];
int top;
long long sum[maxn];
int main()
{
	//freopen("station.in","r",stdin);
	//freopen("station.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&h[i],&w[i]);
	st[++top]=1;
	for(int i=2;i<=n;i++)
	{
		while(top>0 && h[i]>h[st[top]])
		{
			sum[i]+=w[st[top]];
			top--;
		}
		st[++top]=i;
	}
	top=0;
	st[++top]=n;
	for(int i=n-1;i>=1;i--)
	{
		while(top>0 && h[i]>h[st[top]])
		{
			sum[i]+=w[st[top]];
			top--;
		}
		st[++top]=i;
	}
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(sum[0]<sum[i])sum[0]=sum[i];
	}
	printf("%lld",sum[0]);
	return 0;
}