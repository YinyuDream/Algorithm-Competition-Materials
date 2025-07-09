#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mp[3000][3000];
void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
        }
    }
    ll a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == a) {
                if (mp[i - 1][j] == b && mp[i][j + 1] == c) {
                    cout << i - 1 << " " << j - 1 << "\n";
                    continue;
                }
                if (mp[i + 1][j] == c && mp[i][j + 1] == b) {
                    cout << i - 1 << " " << j - 1 << "\n";
                    continue;
                }
                if (mp[i + 1][j] == b && mp[i][j - 1] == c) {
                    cout << i - 1 << " " << j - 1 << "\n";
                    continue;
                }
                if (mp[i - 1][j] == c && mp[i][j - 1] == b) {
                    cout << i - 1 << " " << j - 1 << "\n";
                    continue;
                }
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
    return 0;
}