#include<bits/stdc++.h>
using namespace std;
void work()
{
	int n,tot=0;
	long long L=1,R=9,ans=0;
	scanf("%d",&n);
	int x=n;
	while(x)
	{
		tot++;
		x/=10;
	}
	for(int i=1;i<tot;i++)
	{
		ans+=i*(R-L+1);
		L=R+1;
		R=L*10-1;
	}
	printf("%lld\n",ans+tot*(n-L+1));
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		work();
	return 0;
}
