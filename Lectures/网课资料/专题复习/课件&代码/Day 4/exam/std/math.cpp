#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename _tp> inline void read(_tp&x){
	char ch=getchar(),ob=0;x=0;
	while(ch!='-'&&!isdigit(ch))ch=getchar();if(ch=='-')ob=1,ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();if(ob)x=-x;
}

const int N = 301000;
int a[N], b[N], n;

inline long double calc(long double x) {
	long double ans = 0.;
	for(int i=1;i<=n;++i)
		ans += abs(a[i] * x + b[i]);
	return ans;
}

int main() {
	freopen("in","r",stdin);
	read(n);
	for(int i=1;i<=n;++i) read(a[i]), read(b[i]);
	const long double eps = 1e-12;
	long double l = -2e9, r = +2e9, mid, t1, t2;
	while(l + eps< r) {
		long double p1 = l + (r-l) * 0.4;
		long double p2 = l + (r-l) * 0.6;
		t1 = calc(p1), t2 = calc(p2);
		if(t1 < t2) r = p2;
		else l = p1;
	}
	printf("%.8Lf\n", calc(l));
	return 0;
}
