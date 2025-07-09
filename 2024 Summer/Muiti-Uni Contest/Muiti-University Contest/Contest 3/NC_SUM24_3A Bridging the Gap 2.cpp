#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n, L, R;
    std::cin >> n >> L >> R;
    int num = std::ceil(double(n - R) / (R - L));

    int sum = 0, p = 0;
    for (int i = 0; i < n; i++) {
        int h;
        std::cin >> h;
        h = (h - 1) / 2;
        if (h >= num) {
            sum ++;
        }
        else {
            p += h;
            while (p >= num) {
                p -= num;
                sum ++;
            }
        }
    }
    if (sum >= L) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
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