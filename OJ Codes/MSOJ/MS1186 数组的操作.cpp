#include<cstdio>
using namespace std;
const int maxn=1e5+10;
int n,m,top,x,y;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	top=n;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&y);
			a[++top]=y;
		}
		else
		{
			if(top==0)
			{
				printf("NO");return 0;
			}
			else top--;
		}
	}
	if(top==0)printf("0");
	for(int i=1;i<=top;i++)printf("%d ",a[i]);
	return 0;
}
