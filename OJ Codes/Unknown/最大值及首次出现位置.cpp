#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,maxx=1,maxn=-2e9;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t); 
		if(maxn<t)
		{
			maxx=i;
			maxn=t;	
		}	
	}
	printf("%d\n%d",maxn,maxx);
	return 0;
} 
