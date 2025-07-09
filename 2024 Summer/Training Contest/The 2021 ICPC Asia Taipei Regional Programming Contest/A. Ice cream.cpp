#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll x, y, n;
    cin >> x >> y >> n;
    ll t = n / (x + y);
    cout << min(t * x * 3 + (n - t * (x + y)) * 3, (t + 1) * x * 3) << '\n';
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