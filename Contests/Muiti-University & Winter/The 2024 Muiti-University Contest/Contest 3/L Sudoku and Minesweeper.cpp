#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    std::string s[9];
    for (int i = 0; i < 9; i++) {
        std::cin >> s[i];
    }
    bool check=false;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!check && i != 0 && i != 8 && j != 0 && j != 8 && s[i][j] == '8') {
                std::cout << 8;
                check = true;
            }
            else {
                std::cout << "*";
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