#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    if ((n & 1) == 1 && (m & 1) == 1) {
        std::cout << "No\n";
    }
    else if ((n == 1 && m == 2) || (n == 2 && m == 1)) {
        std::cout << "Yes\n";
    }
    else if (a == 1 && b == 1) {
        std::cout << "Yes\n";
    }
    else if (a == 0 && b == 1) {
        if (n == 1 || m == 1) {
            std::cout << "No\n";
        }
        else {
            std::cout << "Yes\n";
        }
    }
    else if (a == 1 && b == 0) {
        if (n == 1 || m == 1) {
            std::cout << "Yes\n";
        }
        else {
            std::cout << "No\n";
        }
    }
    else {
        std::cout << "No\n";
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