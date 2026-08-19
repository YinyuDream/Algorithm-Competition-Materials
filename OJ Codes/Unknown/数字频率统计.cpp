#include<cstdio>
using namespace std;
int n,t,a=2,cnt;
int m[10010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		m[t]++;
	}
	for(int i=10000;i>=1;i--)
	{
		if(m[i]!=0&&a!=0)
		{
			printf("%d ",m[i]);
			a--;
			cnt++; 
		}
		if(m[i]!=0&&a==0)cnt++; 
	}
	printf("%d",cnt); 
	return 0;
}
