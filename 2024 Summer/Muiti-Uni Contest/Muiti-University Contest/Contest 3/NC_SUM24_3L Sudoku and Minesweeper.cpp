#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n = 9;
    std::string s[n];
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    int x, y;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (s[i][j] == '8') {
                x = i, y = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == x && j == y) {
                std::cout << '8';
            }
            else {
                std::cout << '*';
            }
        }
        std::cout << "\n";
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