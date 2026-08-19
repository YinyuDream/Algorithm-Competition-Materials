#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        vector<ll> ans(n + 1, -INF);

        // iterate over all allowed lengths
        for (int len = L; len <= R; ++len) {
            int max_l = n - len + 1;          // last possible start index
            deque<pair<ll, int>> dq;          // (value, start)

            for (int i = 1; i <= n; ++i) {
                // add the interval that starts at i (if it exists)
                if (i <= max_l) {
                    ll val = pre[i + len - 1] - pre[i - 1];
                    while (!dq.empty() && dq.back().first <= val)
                        dq.pop_back();
                    dq.emplace_back(val, i);
                }

                // remove intervals whose start is too far left
                while (!dq.empty() && dq.front().second < i - len + 1)
                    dq.pop_front();

                // the best interval covering i for this length
                ll cur = dq.empty() ? -INF : dq.front().first;
                if (cur > ans[i]) ans[i] = cur;
            }
        }

        // compute the required xor
        ull res = 0;
        for (int i = 1; i <= n; ++i) {
            ull v = (ull)i * (ull)ans[i];   // automatic mod 2^64
            res ^= v;
        }
        cout << res << '\n';
    }
    return 0;
}
