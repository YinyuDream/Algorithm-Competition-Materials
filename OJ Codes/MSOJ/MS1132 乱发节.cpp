#include<cstdio>
using namespace std;
int n;
int h[1000010];
int stack1[1000010],stack2[1000010];
int top1,top2;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	h[++n]=1e9;
	for(int i=1;i<=n;i++)
	{
		while(stack1[top1]<=h[i]&&top1>0)
		{
			ans+=i-stack2[top2]-1;
			top1--;top2--;
		}
		stack1[++top1]=h[i];stack2[++top2]=i;
	}
	printf("%lld",ans);
	return 0;
}