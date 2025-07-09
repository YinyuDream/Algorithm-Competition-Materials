#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n, k;
    std::cin >> n >> k;
    if (n < (k << 1)) {
        k = n - k;
    }
    if (n == (k << 1)) {
        std::cout << n;
    }
    else {
        std::cout << 1LL * n * k + 1;
    }
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