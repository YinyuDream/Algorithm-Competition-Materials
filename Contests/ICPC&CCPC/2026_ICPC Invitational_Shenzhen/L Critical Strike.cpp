#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int p, v, w;
};

void solve() {
    int T;
    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<Item> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].p >> items[i].v >> items[i].w;
        }
        // Remove items that cannot be bought at all
        items.erase(remove_if(items.begin(), items.end(), [m](const Item& it) {
            return it.w > m;
        }), items.end());

        // Sort by multiplier ascending (lower multipliers processed first)
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.v < b.v;
        });

        // dp[c] = maximum expected effective multiplier spending at most c coins
        vector<double> dp(m + 1, 0.0);
        for (const auto& it : items) {
            double prob = it.p / 100.0;
            double f = 1.0 - prob;
            double val = it.v * prob;
            for (int c = m; c >= it.w; --c) {
                double new_val = val + f * dp[c - it.w];
                if (new_val > dp[c]) dp[c] = new_val;
            }
        }
        double ans = 0.0;
        for (int c = 0; c <= m; ++c) {
            if (dp[c] > ans) ans = dp[c];
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}