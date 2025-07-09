#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n;
    std::cin >> n;
    while (n % 5 == 0) {
        n /= 5;
    }
    while (n % 2 == 0) {
        n /= 2;
    }
    if (n == 1) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}