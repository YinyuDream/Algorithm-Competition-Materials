#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <int, int> pii;

const int N = 1e3 + 5;
const double eps = 1e-9;

int n;
int r[N], g[N], b[N];

void print(double R, double G = -1, double B = -1) {
	if (R == -1) {
		puts ("-1");
	} else {
		for (int i = 0; i < n; i++) {
			printf("%d\n", int(R * r[i] + B * b[i] + G * g[i] + eps));
		}
	}
}


void work () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}
	if (r[0] < r[1] && g[0] < g[1] && b[0] < b[1]) print(-1);
	else if (r[0] > r[1] && g[0] > g[1] && b[0] > b[1]) print(-1);
	else if (r[0] == r[1]) print(1, 0, 0);
	else if (g[0] == g[1]) print(0, 1, 0);
	else if (b[0] == b[1]) print(0, 0, 1);
	else {
		if ((r[0] < r[1]) ^ (g[0] < g[1])) {
			int dr = abs(r[0] - r[1]);
			int dg = abs(g[0] - g[1]);
			print(dg * 1. / (dr + dg), dr * 1. / (dr + dg), 0);
		} else {
			int dr = abs(r[0] - r[1]);
			int db = abs(b[0] - b[1]);
			print(db * 1. / (dr + db), 0, dr * 1. / (dr + db));
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
//	cin >> T;
	for (int ca = 1; ca <= T; ca ++)
		work();
}
