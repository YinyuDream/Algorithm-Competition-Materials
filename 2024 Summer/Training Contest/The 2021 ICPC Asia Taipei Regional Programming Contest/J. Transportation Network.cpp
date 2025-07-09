#include <bits/stdc++.h>
using namespace std;
using l1 = long long;

void solve() {
    l1 n, s, p;
    cin >> n >> s >> p;
    for (int i = 0; i < n; i++) {
        l1 t;
        cin >> t;
    }
    cout << (n - 2 - s + p) * 2 * (n - 1) + 2 * (n - p) * p << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}