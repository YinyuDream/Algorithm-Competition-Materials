#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
inline ll read(){
	ll x=0;int f=1;
	char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)x=x*10+c-48,c=getchar();
	return x*f;
}

inline ll abss(ll n){return n>=0?n:-n;}

#define ctz __builtin_ctzll
inline ll gcd(ll a,ll b){
	if(!a||!b)return a|b;
	ll p=ctz(a|b),t;
	a>>=ctz(a);
	do{
		b>>=ctz(b);
		if(a>b)t=a,a=b,b=t;
		b-=a;
	}while(b);
	return a<<p;
}

inline ll inc(ll x,ll y,ll p){
	return x+y>=p?x+y-p:x+y;
}

inline ll mul(ll x,ll y,ll p){
	ll d=(long double)x/p*y+0.5,r=x*y-d*p;
	if(r<0)r+=p;
	return r;
}

inline ll qpow(ll a,ll b,ll p){
	ll r=1;
	for(;b;b>>=1){
		if(b&1)r=mul(r,a,p);
		a=mul(a,a,p);
	}return r;
}

ull sd=20201021,sd2=20200914;
inline ull randll(){
	sd^=sd<<17,sd^=sd>>5,sd^=sd<<23,sd2=(sd2*114+514)%20161021;
	return sd^sd2;
}

namespace miller{
	const int P[7]={2,3,5,7,11,61,24251};
	ll s,t;
	inline bool test(ll n,int p){
		if(p>=n)return 1;
		ll r=qpow(p,t,n),w;
		for(int j=0;j<s&&r!=1;++j){
			w=mul(r,r,n);
			if(w==1&&r!=n-1)return 0;
			r=w;
		}
		return r==1;
	}
	inline bool judge(ll n){
		if(n<2||n==46856248255981ll)return 0;
		for(int i=0;i<7;++i)if(!(n%P[i]))return n==P[i];
		s=0,t=n-1;
		while(!(t&1))t>>=1,++s;
		for(int i=0;i<7;++i)if(!test(n,P[i]))return 0;
		return 1;
	}
}
using miller::judge;

namespace rho{
	inline ll nxt(ll x,ll y,ll p){
		return inc(mul(x,x,p),y,p);
	}
	inline ll find(ll n,ll C){
		ll l,r,d,p=1;
		l=randll()%(n-2)+2,r=nxt(l,C,n);
		int cnt=0;
		while(l^r){
			p=mul(p,abss(l-r),n);
			if(!p)return gcd(n,abss(l-r));
			++cnt;
			if(cnt==127){
				cnt=0;
				d=gcd(abss(l-r),n);
				if(d>1)return d;
			}
			l=nxt(l,C,n);
			r=nxt(nxt(r,C,n),C,n);
		}
		return gcd(n,p);
	}
}
using rho::find;

vector<ll> v;
void dfs(ll n){
    if(n == 1) return ;
	if(judge(n)){v.push_back(n) ;return;}
	ll p=n,C=randll()%(n-1)+1;
	while(p==1||p==n)p=find(n,C++);
	while(!(n%p))n/=p;
	dfs(p),dfs(n);
}

ll phi(ll n)
{
    v.clear();
    ll t =n;
    if(!(n&1)) {
        while(!(n&1)) n >>= 1;
        v.push_back(2);
    }
    dfs(n);
    sort(v.begin() , v.end());
    v.erase(unique(v.begin() , v.end()) , v.end());
    for(auto x : v) {t = t / x * (x - 1); }
    return t;
}
ll lcm(int a,int b)
{
    return 1LL*a*b/__gcd(a , b);
}

ll sol(int a,ll mod)
{
    if(mod == 1) return 0;
    ll p = phi(mod);
    return qpow(a , sol(a , p) + p , mod) ;
}
void solve()
{
    int a , m;
    a =read() , m = read();
    ll d = lcm(m , phi(m));
    ll ans = sol(a , d);
    if(ans <= 30) {ans += d;}
    printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--){
        solve() ;
	}
	return 0;
}
