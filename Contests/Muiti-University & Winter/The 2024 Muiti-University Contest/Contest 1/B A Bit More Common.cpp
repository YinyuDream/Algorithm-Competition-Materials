#include<bits/stdc++.h>
using i64 = long long;
i64 binpow(i64 a, i64 b, i64 mod)
{
    a %= mod;
    i64 ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, m;
    i64 q;
    std::cin >> n >> m >> q;

    std::vector<i64> a(n + 1), c(n + 1), ct(m);
    a[0] = c[0] = ct[0] = 1;

    for (int k = 1; k <= n; k++) {
        a[k] = a[k - 1] << 1;
        a[k] %= q;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            c[j] = (c[j] + c[j - 1]) % q;
        }
    }
    for (int i = 1; i <= m - 1; i++) {
        for (int j = i; j > 0; j--) {
            ct[j] = (ct[j] + ct[j - 1]) % q;
        }
    }

    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(m));
    dp[0][0] = 1;
    for (int k = 1; k <= n; k++) {
        for (int t = 1; t <= m - 1; t++) {
            dp[k][t] = ((dp[k][t - 1] + dp[k - 1][t - 1]) % q * k) % q;
        }
    }

    i64 ans = 0;
    for (int k = 2; k <= n; k++) {
        i64 tmp1 = binpow(a[k] - 1, m - 1, q);
        i64 tmp2 = 0, tp = (a[k] + q - k - 1) % q, tmpt = 1;
        for (int t = m - 1; t >= k; t--) {
            tmp2 += ((ct[t] * dp[k][t]) % q * tmpt) % q;
            tmp2 %= q;
            tmpt *= tp;
            tmpt %= q;
        }
        i64 tmp3 = binpow(a[n - k], m - 1, q);
        ans += (((tmp1 + q - tmp2) % q * tmp3) % q * c[k]) % q;
        ans %= q;
    }
    std::cout << ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}