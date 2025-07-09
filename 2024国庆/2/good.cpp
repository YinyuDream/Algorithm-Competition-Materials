#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

mt19937 eng(time(0));

int n, m, p[MAXN], s[MAXN]; pair<int, int> w[MAXN];

char a[MAXN], b[MAXN]; int pos[MAXN], tp;

int main() {
    freopen("data.in", "r", stdin);
    freopen("good.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s%s", a + 1, b + 1);
	for (int i = 1; i <= n; i++) if (a[i] != b[i]) pos[++tp] = i;
	for (int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &w[i].first, &w[i].second);
		w[i].first = lower_bound(pos + 1, pos + tp + 1, w[i].first) - pos;
		w[i].second = upper_bound(pos + 1, pos + tp + 1, w[i].second) - pos - 1;
	}
	shuffle(w + 1, w + m + 1, eng);
	for (int i = 1, l, r; i <= m; i++) {
		l = w[i].first, r = w[i].second;
		if (l > r || l > tp || r < 1) continue;
		for (int j = l; j <= tp; j = l) {
			if (!p[j]) { p[j] = r; break; }
			if (r == p[j]) break;
			if (r < p[j]) l = r + 1, r = p[j];
			else l = p[j] + 1;
		}
	}
	for (int i = 1; i <= tp; i++) {
		s[i] ^= s[i - 1];
		if (s[i]) swap(a[pos[i]], b[pos[i]]);
		if (a[pos[i]] < b[pos[i]] && p[i]) {
			s[i] ^= 1, s[p[i] + 1] ^= 1;
			swap(a[pos[i]], b[pos[i]]);
		}
	}
	printf("%s", a + 1);
}