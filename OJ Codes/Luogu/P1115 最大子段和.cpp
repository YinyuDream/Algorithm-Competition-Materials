#include<cstdio>
using namespace std;
const int maxx=200010;
int n,t;
int sum,maxn,maxm=-100000000;
int a[maxx];
int max(int x,int y)
{
	if(x>y)return x;
	else return y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0)
		{
			t++;
			maxm=max(maxm,a[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum<0)sum=0;
		maxn=max(maxn,sum); 
	}
	if(t==n)printf("%d",maxm);
	else printf("%d",maxn);
	return 0;
}