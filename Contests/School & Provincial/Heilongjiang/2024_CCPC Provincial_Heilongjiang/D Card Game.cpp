#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n;
    i64 hpa, hpb;
    std::cin >> n >> hpa >> hpb;
    std::vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int atmp;
        std::cin >> atmp;
        if (atmp != -1) {
            a.push_back(atmp);
        }
    }
    for (int i = 0; i < n; i++) {
        int btmp;
        std::cin >> btmp;
        if (btmp != -1) {
            b.push_back(btmp);
        }
    }

    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end(), std::less<int>());

    int len = std::min(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        hpa -= b[i];
        hpb -= a[i];
        if (hpa > 0 && hpb <= 0) {
            std::cout << "yes";
            return;
        }
        if (hpa <= 0) {
            std::cout << "no";
            return;
        }
    }
    std::cout << "no";
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
        if (t != 0) {
            std::cout << "\n";
        }
    }
    return 0;
}