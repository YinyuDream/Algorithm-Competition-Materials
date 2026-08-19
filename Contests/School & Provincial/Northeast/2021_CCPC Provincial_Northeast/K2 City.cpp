#include<bits/stdc++.h>
using i64 = long long;
constexpr int MAX = 1e5 + 5;
std::vector<int> f(MAX);
struct node {
    int x, y, k;
};
int find (int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}
bool cmp(node x, node y) {
    return x.k > y.k;
}
void solve()
{
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<node> g;
    for (int i = 0; i < m; i++) {
        int x, y, k;
        std::cin >> x >> y >> k;
        g.push_back({x, y, k});
    }

    std::sort(g.begin(), g.end(), cmp);
    
    std::vector<int> p(q);
    for (int i = 0; i < q; i++) {
        std::cin >> p[i];
    }

    auto check = p;
    std::sort(p.begin(), p.end(), std::greater<int>());
    
    int l[n + 1]; 
    for (int i = 1; i <= n; i++) {
        l[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    int s = 0;
    i64 sum = 0;
    std::map<int, i64> ans;
    for (int i = 0; i < q; i++) {
        // std::cout << "check: " << p[i] << "\n";
        while (s < m && g[s].k >= p[i]) {
            // std::cout << "compare: " << g[s].x << " " << g[s].y << " " << g[s].k << "\n";
            // std::cout << find(g[s].x) << ": " << l[find(g[s].x)] << " ; " << find(g[s].y) << ": " << l[find(g[s].y)] << "\n";
            int fx = find(g[s].x), fy = find(g[s].y);
            if (fx != fy) {
                sum -= 1LL * l[fx] * (l[fx] - 1) / 2 + 1LL * l[fy] * (l[fy] - 1) / 2;
                l[fy] += l[fx];
                l[fx] = 0;
                sum += 1LL * l[fy] * (l[fy] - 1) / 2;
                f[fx] = fy;
            }
            s++;
        }
        ans[p[i]] = sum;
    }
    for (auto i : check) {
        std::cout << ans[i] << "\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
	  		 	 	    	 	 	 	    					 	