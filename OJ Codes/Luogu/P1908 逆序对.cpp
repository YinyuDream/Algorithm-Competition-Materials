#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5e5+10;
int n;
ll ans;
int a[maxn],help[maxn];
int tree[maxn];
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	return x;
}
inline void update(int x)
{
	while(x<=n)
	{
		tree[x]++;
		x+=(x&-x);
	}
}
inline ll get(int x)
{
	ll cnt=0;
	while(x>0)
	{
		cnt+=tree[x];
		x-=(x&-x);
	}
	return cnt;
}
void lsh()
{
	sort(help+1,help+n+1);
	int cnt=unique(help+1,help+n+1)-help-1;
	for(int i=1;i<=n;i++)
		a[i]=upper_bound(help+1,help+cnt+1,a[i])-help;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),help[i]=a[i];
	lsh();
	for(int i=n;i>=1;i--)
	{
		ans+=get(a[i]-1);
		update(a[i]);
	}
	printf("%lld",ans);
	return 0;
}
