#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n;
    i64 D;
    std::cin >> n >> D;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 h;
        std::cin >> h;
        ans = std::__gcd(ans, h);
    }
    i64 res = D % ans;
    std::cout << std::min(res, ans - res);

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