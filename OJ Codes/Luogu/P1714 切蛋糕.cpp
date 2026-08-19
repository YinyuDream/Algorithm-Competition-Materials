#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,ans=-0x7f7f7f7f;
int a[maxn],sum[maxn],f[maxn];
deque<int>q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(q.size()&&q.front()<i-m)q.pop_front();
		while(q.size()&&sum[q.back()]>sum[i-1])q.pop_back();
		q.push_back(i-1);
		f[i]=sum[i]-sum[q.front()];
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}
