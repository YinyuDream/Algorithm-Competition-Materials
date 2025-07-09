#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    i64 x;
    std::cin >> x;
        i64 lowbit = (x & -x);
        if (lowbit == x) {
            std::cout << "-1\n";
        }
        else {
            std::cout << x - lowbit << "\n";
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