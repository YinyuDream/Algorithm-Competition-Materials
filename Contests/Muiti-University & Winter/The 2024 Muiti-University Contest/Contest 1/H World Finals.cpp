#include<bits/stdc++.h>
using i64 = long long;
struct part {
    std::string s;
    int pass, pen;
};
bool cmp(part x, part y)
{
    if (x.pass > y.pass) {
        return true;
    }
    else if (x.pass == y.pass) {
        return x.pen < y.pen;
    }
    else {
        return false;
    }
}
void solve()
{
    int n;
    std::cin >> n;

    std::set<std::string> l46b, l47b;

    std::vector<part> l46(n);
    for (int i = 0; i < n; i++) {
        std::string s;
        int p, t;
        std::cin >> s >> p >> t;
        l46[i] = {s, p, t};
        l46b.insert(s);
    }

    int m;
    std::cin >> m;
    std::vector<part> l47(m);

    for (int i = 0; i < m; i++) {
        std::string s;
        int p, t;
        std::cin >> s >> p >> t;
        l47[i] = {s, p, t};
        l47b.insert(s);
    }

    std::sort(l46.begin(), l46.end(), cmp);
    std::sort(l47.begin(), l47.end(), cmp);

    std::set<std::string> l46f, l47f;
    for (int i = 0; i < n; i++) {
        if (l46[i].s == "lzr010506") {
            break;
        }
        l46f.insert(l46[i].s);
    }
    for (int i = 0; i < m; i++) {
        if (l47[i].s == "lzr010506") {
            break;
        }
        l47f.insert(l47[i].s);
    }

    int num1 = 1, num2 = 1;
    for (auto i : l46f) {
        if (l47b.find(i) == l47b.end()) {
            num1 ++;
        }
    }
    for (auto i : l47f) {
        if (l46b.find(i) == l46b.end()) {
            num2 ++;
        }
    }
    std::cout << std::min(num1, num2);
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