#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 301000;
int n, F;
double a[N];
ll b[N];

double Time = 0.;

double mi[N<<2];

void build(int l, int r, int x) {
	if (l == r) {
		mi[x] = a[l] / (b[l-1] - b[l]);
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, x << 1);
	build(mid+1, r, x << 1 | 1);
	mi[x] = min(mi[x<<1], mi[x<<1|1]);
}

int qry(int l, int r, int x) {
	if (l == r) return l;
	int mid = l + r >> 1;
	if(mi[x<<1] < mi[x<<1|1]) return qry(l, mid, x<<1);
	else return qry(mid+1, r, x<<1|1);
}

void upd(int l, int r, int x, int ps) {
	if (l == r) {
		if(a[l] < 0) mi[x] = 1e18;
		else mi[x] = a[l] / (b[l-1] - b[l]); // b[l-1] == b[find(l-1)] 
		return ;
	}
	int mid = l + r >> 1;
	if (ps <= mid) upd(l, mid, x<<1, ps);
	else upd(mid+1, r, x<<1|1, ps);
	mi[x] = min(mi[x<<1], mi[x<<1|1]);
}

int dad[N];
int find(int x) {return dad[x] ? dad[x] = find(dad[x]) : x;}

int main() {
	scanf("%d%lld", &n, &b[0]);
	
	int lowest = b[0], R = 0;
	for (int i = 1; i <= n; ++ i) scanf("%lf", a+i);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld", b+i);
		if (b[i] < lowest)
			lowest = b[R = i];
	}
	
	for (int i = 0; i <= R; ++ i)
		b[i] -= lowest;
	
	if (R == 0 or b[0] == 0) {
		puts("-1");
		return 0;
	}
	
	for(int i = 1; i <= R; ++ i)
		if(b[i-1] < b[i])
			b[i] = b[i-1];
	
	int nn = 1;
	ll res = 0;
	for(int i = 2; i <= R; ++ i)
		if(b[i-1] != b[i]) {
			++ nn;
			a[nn] = a[i] + res, res = 0;
			b[nn] = b[i];
		} else res += a[i];
	
	b[n = nn] = 0;
	
	build(1, n, 1);
	
	while(1) {
		int t = qry(1, n, 1);
		
		double time = a[t] / (b[t-1] - b[t]);
		a[t] = -1;
		Time = time;
		if(t == 1) break;
		
		int u = find(t-1);
		dad[t] = u;
		a[u] -= Time * (b[u-1] - b[u]);
		b[u] = b[t];
		a[u] += Time * (b[u-1] - b[u]);
		
		upd(1, n, 1, t); // discard
		upd(1, n, 1, u); // update
	}
	
	printf("%.3lf\n", Time);
	return 0;
}
