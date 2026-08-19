#include<cstdio>
using namespace std;

const int maxn=1e3+10;
int n,k,cnt;
int a,t[maxn];
int main()
{
	freopen("maxk.in","r",stdin);
	freopen("maxk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		t[a]++;	
	}
	for(int i=maxn-1;i>=1;i--)
	{
		if(t[i]!=0)cnt++;
		if(cnt==k)
		{
			printf("%d\n%d",i,t[i]);
			return 0;
		}
	}
}
