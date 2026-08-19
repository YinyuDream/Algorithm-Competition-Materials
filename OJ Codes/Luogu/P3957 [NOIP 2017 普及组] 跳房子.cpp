#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,d,l,r,ans;
int dis[maxn],w[maxn];
ll k,f[maxn];
deque<int>q;
bool check(int x)
{
	memset(f,-0x7f,sizeof f);
	f[0]=0;
	int p=0;
	ll mx=-0x7f7f7f7f;
	while(q.size())q.pop_back();
	int dmax=d+x,dmin=max(1,d-x);
	for(int i=1;i<=n;i++)
	{
		while(dis[p]<=dis[i]-dmin){
			while(q.size()&&f[q.back()]<f[p])q.pop_back();
			q.push_back(p++);
		}
		while(q.size()&&dis[q.front()]<dis[i]-dmax)q.pop_front();
		if(q.size())
			f[i]=f[q.front()]+w[i];
		mx=max(mx,f[i]);
	}
	return mx>=k;
}
int main(){
	//freopen("P3957_3.in","r",stdin);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&dis[i],&w[i]);
	r=dis[n]+1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",r!=dis[n]+1?ans:-1);
	return 0;
}
