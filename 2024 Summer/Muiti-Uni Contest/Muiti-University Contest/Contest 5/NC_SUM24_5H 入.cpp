#include<bits/stdc++.h>
using i64 = long long;
int vis[50];
std::vector<int> g[50];
int max = -1;
void dfs(int x, int path)
{
    for (auto i : g[x]) {
            vis[i]++;
    }
    for (auto i : g[x]) {
        if (vis[i]==1) {
            dfs(i,path+1);
        }
    }
    for (auto i : g[x]) {
        vis[i]--;
    }
    max = std::max(max, path);
}
void solve()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        vis[i]++;
        dfs(i, 1);
        vis[i]-- ;
    }
    std::cout << max;
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