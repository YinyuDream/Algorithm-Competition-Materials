#include<bits/stdc++.h>
using i64 = long long;
int n, m, q;

// struct cmp {
//     bool operator()(const std::pair<int, int> &x, const std::pair<int, int> &y) {
//         return x.second > y.second;
//     }
// };

// void prim(int k, std::map<std::pair<int, int>, int> &p, std::vector<int> &s)
// {
//     std::map<int, std::vector<std::pair<int, int>>> g;

//     for (int i = 0; i < k - 1; i++) {
//         for (int j = i + 1; j < k; j++) {
//             if (p[{s[i], s[j]}] != 0) {
//                 g[s[i]].push_back({s[j], p[{s[i], s[j]}]});
//                 g[s[j]].push_back({s[i], p[{s[i], s[j]}]});
//             }
//             else if (p[{s[j], s[i]}] != 0) {
//                 g[s[j]].push_back({s[i], p[{s[j], s[i]}]});
//                 g[s[i]].push_back({s[j], p[{s[j], s[i]}]});
//             }
//         }
//     }
//     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> l;
//     std::map<int, int> dis, vis;
//     for (auto &[x, y] : g) {
//         dis[x] = 0x3f3f3f3f;
//         vis[x] = 0;
//     }
//     dis[s[0]] = 0, l.push({s[0], 0});
//     i64 sum = 0, num = 0;
//     while (!l.empty()) {
//         if (num == k) {
//             break;
//         }
//         auto [u, d] = l.top();
//         l.pop();
//         if (!vis[u]) {
//             vis[u]++;
//             num ++;
//             sum += d;
//             for (auto &[v, w] : g[u]) {
//                 if (!vis[v] && w < dis[v]) {
//                     dis[v] = w, l.push({v, w});
//                 }
//             }
//         }
//     }
//     if (num == k) {
//         std::cout << sum << "\n";
//     }
//     else {
//         std::cout << "-1\n";
//     }
// }

struct DSU {
    std::vector<int> f, sz;
    DSU(int n) : f(n), sz(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (sz[fx] > sz[fy]) {
            std::swap(fx, fy);
        }
        f[fx] = fy;
        sz[fy] += sz[fx];
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void kruskal(int k, std::vector<std::vector<std::pair<int, int>>> &p, std::vector<bool> &vis, std::vector<int> &s, DSU &node)
{

    std::vector<std::array<int, 3>> l;
    for (auto &u : s) {
        for (auto &[v, w] : p[u]) {
            if (vis[v]) {
                l.push_back({w, u, v});
            }
        }
    }
    std::sort(l.begin(), l.end());
    i64 sum = 0, num = 1;
    for (auto &[w, u, v] : l) {
        if (num == k) {
            break;
        }
        if (node.merge(u, v)) {
            num ++;
            sum += w;
        }
    }
    if (num == k) {
        std::cout << sum << "\n";
    }
    else {
        std::cout << "-1\n";
    }
}

void solve()
{
    std::cin >> n >> m >> q;

    DSU node(n + 1);
    std::vector<int> degree(n + 1);
    std::vector<std::array<int, 3>> op(m + 1);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        op[i] = {u, v, w};
        degree[u]++;
        degree[v]++;
    }

    // std::map<std::pair<int, int>, int> p1;
    std::vector<std::vector<std::pair<int, int>>> p2(n + 1);

    for (int i = 1; i <= m; i++) {
        auto &[u, v, w] = op[i];
        if (degree[u] > degree[v]) {
            std::swap(u, v);
        }
        // p1[{u, v}] = w;
        p2[u].emplace_back(v, w);
    }
    std::vector<bool> vis(n + 1);

    while (q--) {
        int k;
        std::cin >> k;
        std::vector<int> s(k);
        for (int i = 0; i < k; i++) {
            std::cin >> s[i];
            vis[s[i]] = true;
            node.f[s[i]] = s[i];
            node.sz[s[i]] = 1;
        }
        // if (k <= 300) {
        //     prim(k, p1, s);
        // }
        // else {
            kruskal(k, p2, vis, s, node);
        // }

        for (auto &i : s) {
            vis[i] = false;
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