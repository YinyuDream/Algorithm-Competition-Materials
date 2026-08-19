using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <deque>
#define ll long long
#define M 200005
ll gcd(ll a,ll b){
	ll k;
	while (b)
		k=a%b,a=b,b=k;
	return a;
}
ll n;
int m;
ll s[M*20];
int head,tail;
ll ans=0;
void work(){
	while (1){
		if (head>tail)
			return;
		while (head<=tail && s[tail]>=n)
			tail--;
		if (s[head]>n>>1){
			ll v=s[head],b=2*v-n;
			ans+=b;
			n-=b;
			for (int i=head;i<=tail;++i)
				s[i]-=b;
		}
		ll d=0;
		while (head<=tail && (s[head]<=n>>1 || d+s[head]<=n))
			d=gcd(d,s[head++]);
		if (head>tail){
			ans+=d;
			return;	
		}
		ll n_=d+n%d;
		for (int i=head;i<=tail;++i)
			s[i]=s[i]+n_-n;
		n=n_;
//		for (int i=head;i<=tail;++i)
//			assert(d<s[i]);
		s[++tail]=d;
		sort(s+head,s+tail+1);
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%lld%d",&n,&m);
		head=1,tail=0;
		for (int i=1;i<=m;++i)
			scanf("%lld",&s[++tail]);
		sort(s+head,s+tail+1);
		ans=0;
		work();
		printf("%lld\n",ans);
	}
	return 0;
}





























