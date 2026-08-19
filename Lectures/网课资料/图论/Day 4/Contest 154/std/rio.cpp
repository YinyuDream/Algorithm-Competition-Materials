#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,z[30][30];

int get(int s)
{
	int ans=0;
	for (int a=0;a<n;a++)
	   for (int b=a+1;b<n;b++)
	   if ((s>>a&1)==(s>>b&1)) ans+=z[a][b];	   
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int a=1;a<=m;a++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		z[s-1][e-1]++;
		z[e-1][s-1]++;
	}
	int ans=0x3f3f3f3f;
	for (int a=0;a<(1<<n);a++)
		ans=min(ans,get(a));
	printf("%d\n",ans);

	return 0;
}
