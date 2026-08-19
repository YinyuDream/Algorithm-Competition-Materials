#include<cstdio>
using namespace std;

const int maxn=1e6+10;
int h[maxn],n;
int stack[maxn],top;
long long  ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	h[++n]=1e9;
	for(int i=1;i<=n;i++)
	{
		while(top>0 && h[i]>=h[stack[top]])
		{
			ans+=i-stack[top]-1;
			top--;
		}
		stack[++top]=i;
	}
	printf("%lld",ans);
	return 0;
}
