#include <bits/stdc++.h>
using namespace std;
constexpr int Spp{1<<20};
char buf[Spp],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,Spp,stdin),p1==p2)?EOF:*p1++)
template <typename T>
void read(T &x) {
	char c;int f{1};
	do x=(c=getchar())^48;
	while (!isdigit(c)&&c!='-');
	if (x==29) f=-1,x=0;
	while (isdigit(c=getchar()))
		x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
template <typename T,typename ...Args>
void read(T& x,Args&... args) {read(x);read(args...);}
using LL=long long;
constexpr int N(1e6);
int pi[N+5];
LL s[N+5];
int main() {
	int S;read(S);
	int m;LL b,p;read(m,b,p);
	for (int i{1};i<=S;++i) read(s[i]);
	LL z{0};
	LL B{1};
	LL ans{0};
	while (m--) {
		int op;read(op);
		if (op==1) {
			LL x,c;read(x,c);
			x=(x^z)%S+1;c^=z;
			s[x]=c;
		} else {
			B=B*b%p;
			LL n;read(n);
			vector<int> t(1);
			for (int i{1};i<=n;++i) {
				LL c;read(c);
				c^=z;
				t.push_back(c);
			}
			if (n<S)
			{
				z=0;
				continue;
			}
			for (int i{2},j{0};i<=S;++i) {
				while (j&&s[j+1]!=s[i]) j=pi[j];
				if (s[j+1]==s[i]) ++j;
				pi[i]=j;
			}
			LL cnt{0};
			for (int i{1},j{0};i<=n;++i) {
				while (j&&s[j+1]!=t[i]) j=pi[j];
				if (s[j+1]==t[i]) ++j;
				if (j==S) ++cnt,j=pi[j];
			}
			z=cnt*pi[S];
			ans=(ans+cnt*pi[S]%p*B)%p;
		}
	}
	cout<<ans<<endl;
	return 0;
}