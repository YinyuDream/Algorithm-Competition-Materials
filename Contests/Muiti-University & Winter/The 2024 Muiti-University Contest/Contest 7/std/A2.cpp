#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int inf = int(1e9) + 5;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    vector<vector<int>> mn(n + 1);
    priority_queue<pair<int, int>> hp;
    for (int i = 1; i <= n; i++) {
        hp.push({-a[i], i});
        if (i >= k) {
            vector<int> p;
            while ((int)p.size() < m && !hp.empty()) {
                auto [v, id] = hp.top();
                hp.pop();
                if (id > i - k) {
                    p.emplace_back(id);
                }
            }
            mn[i].emplace_back(0);
            for (auto j : p) {
                hp.push({-a[j], j});
                mn[i].emplace_back(mn[i].back() + a[j]);
            }
        }
    }
    array<array<array<int, 2>, 21>, 21> z;
    for (auto &a : z) {
        for (auto &b : a) {
            b.fill(-inf);
        }
    }
    int sgn[2] = {1, -1};
    vector f(n / k + 1, vector(n % k + 1, z));
    f[0][0][0][0][0] = 0;
    auto upd = [&](int &v, int val) {
        v = max(v, val);
    };
    for (int i = 0; i <= n / k; i++) {
        for (int j = 0; j <= n % k; j++) {
            for (int c = 0; c <= m; c++) {
                for (int d = 0; d <= m; d++) {
                    if (j > 0) {
                        if (c > 0) {
                            upd(f[i][j][c][d][0], f[i][j - 1][c - 1][d][0] + a[i * k + j]);
                        }
                        if (d > 0) {
                            upd(f[i][j][c][d][1], f[i][j - 1][c][d - 1][1]);
                        }
                        upd(f[i][j][c][d][0], f[i][j - 1][c][d][0]);
                        upd(f[i][j][c][d][1], f[i][j - 1][c][d][1] + a[i * k + j]);
                    }
                    if (i > 0) {
                        for (int e = 0; e <= d && e < (int)mn[i * k + j].size(); e++) {
                            upd(f[i][j][c][d][1], f[i - 1][j][c][d - e][0] + (sum[i * k + j] - sum[i * k + j - k] - mn[i * k + j][e]));
                        }
                    }
                    upd(f[i][j][c][d][0], f[i][j][c][d][1]);
                }
            }
        }
    }
    int ans = -inf;
    for (int i = 0; i <= m; i++) {
        upd(ans, f[n / k][n % k][i][i][0]);
    }
    cout << ans << '\n';
	return 0;
}
