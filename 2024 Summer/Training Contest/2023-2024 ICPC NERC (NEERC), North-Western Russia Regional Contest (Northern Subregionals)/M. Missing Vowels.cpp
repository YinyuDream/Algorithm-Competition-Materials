#include<bits/stdc++.h>
using i64 = long long;
char unol[] = {'a', 'e', 'i', 'o', 'u', 'y'};
void solve()
{
    std::string s, f;
    std::cin >> s >> f;

    int ps = 0, pf = 0, lens = s.size(), lenf = f.size();
    for (int i = 0; i < lens; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = char(s[i] - 'A' + 'a');
        }
    }

    for (int i = 0; i < lenf; i++) {
        if (f[i] >= 'A' && f[i] <= 'Z') {
            f[i] = char(f[i] - 'A' + 'a');
        }
    }

    // std::cout << s << "\n" << f;

    bool check = true;

    while (ps < lens && pf < lenf && check) {
        while (pf < lenf && f[pf] != s[ps]) {
            bool find = false;
            for (int i = 0; i < 6; i++) {
                if (f[pf] == unol[i]) {
                    find = true;
                    break;
                }
            }
            pf++;
            if (!find || pf == lenf) {
                check = false;
                break;
            }
        }
        ps ++; pf ++;
    }
    if (!check || ps != lens) {
        std::cout << "Different";
    }
    else {
        while (pf < lenf) {
            bool find = false;
            for (int i = 0; i < 6; i++) {
                if (f[pf] == unol[i]) {
                    find = true;
                    break;
                }
            }
            pf++;
            if (!find) {
                std::cout << "Different";
                return;
            }
        }
        std::cout << "Same";
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