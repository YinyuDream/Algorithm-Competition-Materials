#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define p2(x) p[x + 1000000]
#define add(a, b) a = (a + b) % mod
#define sub(a, b) a = (a + mod - b % mod) % mod

int n, a[1000471], ans, p[2000471], s1[2][1000471], s2[2][1000471];
int qpow(int b, int e) {
	return e ? e & 1 ? qpow(b * b % mod, e >> 1) * b % mod : qpow(b * b % mod, e >> 1) : 1;
}
signed main() {
	p2(-1000000) = qpow(2, mod - 1000001);
	for (int i = -1000000; i < 1000000; i++) {
		p2(i + 1) = p2(i) * 2 % mod;
	}
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		add(ans, a[i] * a[i] % mod * a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 0; i < 31; i++) {
		int l1 = 1, l2 = 1, res = 0;
		for (int l = 1; l <= n; l++) {
			int x = 1 & (a[l] >> i), y = 1 ^ x;
			s1[x][l] = (s1[x][l - 1] + a[l] * p2(-l)) % mod;
			s1[y][l] = s1[y][l - 1];
			s2[x][l] = (s2[x][l - 1] + l * a[l] % mod * p2(-l)) % mod;
			s2[y][l] = s2[y][l - 1];
		}
		for (int r = 1; r <= n; r++) {
			int x = 1 & (a[r] >> i), y = 1 ^ x;
			add(res, a[r] * (r + 3) % mod * p2(r - 2) % mod * (s1[y][r - 1] + mod - s1[y][l1 - 1]));
			sub(res, a[r] * p2(r - 2) % mod * (s2[y][r - 1] + mod - s2[y][l1 - 1]));
			add(res, a[r] * (r + 2) % mod * p2(r - 3) % mod * (s1[y][l1 - 1] + mod - s1[y][l2 - 1]));
			add(res, a[r] * (r + 4) % mod * p2(r - 3) % mod * (s1[x][l1 - 1] + mod - s1[x][l2 - 1]));
			sub(res, a[r] * p2(r - 3) % mod * (s2[y][l1 - 1] + mod - s2[y][l2 - 1]));
			sub(res, a[r] * p2(r - 3) % mod * (s2[x][l1 - 1] + mod - s2[x][l2 - 1]));
			add(res, a[r] * p2(r - 3) % mod * (r + 3) % mod * (s1[0][l2 - 1] + s1[1][l2 - 1]));
			sub(res, a[r] * p2(r - 3) % mod * (s2[0][l2 - 1] + s2[1][l2 - 1]));
			if (x) {
				l2 = l1;
				l1 = r;
			}
		}
		add(ans, res * p2(i));
	}
	printf("%lld\n", ans);
}
