#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,l,r,ans=-0x7f7f7f7f;
int a[maxn],f[maxn];
deque<int>q;
int main(){
	memset(f,-0x3f,sizeof f);
	scanf("%d%d%d",&n,&l,&r);
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	f[0]=a[0];
	for(int i=l;i<=n+r;i++)
	{
		if(q.size()&&q.front()<i-r)q.pop_front();
		while(q.size()&&f[q.back()]<f[i-l])q.pop_back();
		q.push_back(i-l);
		f[i]=f[q.front()]+a[i];
	}
	for(int i=n+1;i<=n+r;i++)
		ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}
