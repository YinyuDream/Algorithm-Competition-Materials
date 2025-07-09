#include<bits/stdc++.h>
using i64 = long long;
constexpr int MAX = 5e5 + 1;
bool vis[MAX];
std::vector<int> g[MAX], d(MAX), num[MAX];
std::set<int> f[MAX];
int level = 1;
void dfs(int now, int lev)
{
    level = std::max(lev, level);
    vis[now] = true;
    num[lev].push_back(now);
    for (auto i : g[now]) {
        if (!vis[i]) {
            dfs(i, lev + 1);
            f[i] = f[now];
            f[i].insert(now);
        }
    }
}
void solve()
{
    int n, m;
    std::cin >> n >> m;
    level = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[v] ++, d[u] ++;
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].empty() && d[i] == 0) {
            num[1].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] == 1 && !vis[i]) {
            dfs(i, 1);
        }
    }

    // std::cout << level << "\n";
    // for (int i = 1; i <= level; i++) {
    //     std::cout << i << ": ";
    //     for (auto j : num[i]) {
    //         std::cout << j << " ";
    //     }
    //     std::cout << "\n";
    // }

    if (level == 1) {
        for (auto i : num[1]) {
            std::cout << i << " ";
        }
    }

    else if (level == 2) {
        if (num[1].size() < 2) {
            std::cout << "-1";
        }
        else {
            for (auto i : num[2]) {
                std::cout << i << " ";
            }
            int len = num[1].size(), fp, p = *(num[2].end() - 1);
            for (int i = 0; i < len; i++) {
                if (f[p].find(num[1][i]) != f[p].end()) {
                    fp = i;
                }
                else {
                    std::cout << num[1][i] << " ";
                }
            }
            std::cout << num[1][fp] << " ";
        }
    }

    else if (level == 3) {
        if (num[1].size() >= 2) {
            for (auto i : num[2]) {
                std::cout << i << " ";
            }
            int len = num[1].size(), fp, p = *(num[2].end() - 1);
            for (int i = 0; i < len; i++) {
                if (f[p].find(num[1][i]) != f[p].end()) {
                    fp = i;
                }
                else {
                    std::cout << num[1][i] << " ";
                }
            }
            std::cout << num[1][fp] << " ";
            for (auto i : num[3]) {
                std::cout << i << " ";
            }
        }
        else if (num[2].size() >= 2) {
            for (auto i : num[1]) {
                std::cout << i << " ";
            }
            for (auto i : num[3]) {
                std::cout << i << " ";
            }
            int len = num[2].size(), fp, p = *(num[3].end() - 1);
            for (int i = 0; i < len; i++) {
                if (f[p].find(num[2][i]) != f[p].end()) {
                    fp = i;
                }
                else {
                    std::cout << num[2][i] << " ";
                }
            }
            std::cout << num[2][fp] << " ";
        }
        else {
            std::cout << "-1";
        }
    }
    else {
        for (int i = 2; i <= level; i += 2) {
            for (auto j : num[i]) {
                std::cout << j << " ";
            }
        }
        for (int i = 1; i <= level; i += 2) {
            for (auto j : num[i]) {
                std::cout << j << " ";
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        vis[i] = false;
        g[i].clear();
        num[i].clear();
        d[i] = 0;
        f[i].clear();
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
        std::cout << "\n";
    }
    return 0;
}