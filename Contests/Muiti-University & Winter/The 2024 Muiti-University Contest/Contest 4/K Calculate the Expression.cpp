#include<bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
i64 calculate(std::string t)
{
    int len = t.size();
    std::stack<i64> l;
    std::string num = "";
    bool check = false;
    i64 now;
    for (int i = 0; i < len; i++) {
        if (isdigit(t[i])) {
            num += t[i];
        }
        if (!isdigit(t[i]) || i == len - 1) {
            now = 0;
            int num_len = num.size();
            i64 p = 1;
            for (int j = num_len - 1; j >= 0; j--) {
                now += p * (num[j] - '0');
                now %= mod;
                p *= 10;
            }
            num = "";
            if (check) {
                i64 r = l.top();
                l.pop();
                l.push((r * now) % mod);
                check = false;
            }
            else {
                l.push(now);
            }
            if (t[i] == '*') {
                check = true;
            }
        }
    }
    i64 ans = 0;
    while (!l.empty()) {
        ans += l.top();
        ans %= mod;
        l.pop();
    }
    return ans;
}
void solve()
{
    int q;
    std::cin >> q;

    std::string s;
    std::cin >> s;

    while (q--) {
        int o, u, v;
        std::cin >> o >> u >> v;
        u--;
        if (o == 1) {
            std::string t = s.substr(u, v - u);
            std::cout << calculate(t) << '\n';
        }
        else {
            s[u] = char(v + '0');
        }
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