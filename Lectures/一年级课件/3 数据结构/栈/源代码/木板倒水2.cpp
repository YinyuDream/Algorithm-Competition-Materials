#include<cstdio>
using namespace std;

const int maxn=1e6+10;

int h[maxn],n;
int st1[maxn],top1;
int st2[maxn],top2;

long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	h[++n]=1e9;
	for(int i=1;i<=n;i++)
	{
		while(st1[top1]<=h[i]  && top1>0)
		{
			ans+=i-st2[top2]-1;
			top1--;top2--;
		}
		st1[++top1]=h[i];
		st2[++top2]=i;
	}
	printf("%lld",ans);
	return 0;
}
