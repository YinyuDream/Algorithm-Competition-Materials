#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	int ans=0,minv=0,sum=0;
	for (int a=1;a<=n;a++)
	{
		int v;
		scanf("%d",&v);
		sum+=v;
		ans=max(ans,sum-minv);
		minv=min(minv,sum);
	}
	printf("%d\n",ans);

	return 0;
}
