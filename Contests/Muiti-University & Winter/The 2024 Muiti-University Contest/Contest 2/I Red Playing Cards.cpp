#include <bits/stdc++.h>
using ll = long long;
void solve()
{
    int n, m;
    std::cin >> n;
    m = (n << 1);

    std::vector<int> a(m + 2);
    std::vector<std::vector<int>> p(n + 1);
    a[0] = 0, a[m + 1] = 0;
    p[0] = {0, m + 1};
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i];
        p[a[i]].push_back(i);
    }

    std::vector<std::pair<int, int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int l = p[i][0], r = p[i][1];
        g[i] = {r - l + 1, i};
    }
    g[0] = {m + 2, 0};

    std::sort(g.begin(), g.end());

    std::vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++) {
        auto &[len, now] = g[i];
        int l = p[now][0], r = p[now][1];
        std::vector<int> dp(len);
        dp[0] = now;

        for (int j = 1; j < len; j++) {
            dp[j] = dp[j - 1] + now;
            int lx = p[a[j + l]][0], rx = p[a[j + l]][1];
            if (lx > l && rx == j + l) {
                dp[j] = std::max(dp[j], dp[lx - l - 1] + ans[a[j + l]]);
            }
        }
        ans[now] = dp[len - 1];
    }
    std::cout << ans[0];

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //  cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}