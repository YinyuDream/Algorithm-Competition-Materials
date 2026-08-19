#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

int n;
ll m;
vector<ll> xs;
ll p_min;
vector<ll> pre; // prefix sums of sorted xs

// check if we can buy at least t candies with money m
bool check(ll t) {
    int parity = t & 1;
    ll maxD = min<ll>(n, t);
    if ((maxD - parity) % 2 != 0)
        maxD--;                 // ensure same parity as t
    for (ll D = parity; D <= maxD; D += 2) {
        ll S = (t - D) / 2;     // number of pairs
        i128 cost = (i128)S * p_min + pre[D];
        if (cost <= m)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    xs.resize(n);
    p_min = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        xs[i] = x;
        p_min = min(p_min, x + y);
    }

    sort(xs.begin(), xs.end());
    pre.resize(n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + xs[i - 1];

    ll lo = 0, hi = m;
    while (lo < hi) {
        ll mid = (lo + hi + 1) >> 1;
        if (check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}