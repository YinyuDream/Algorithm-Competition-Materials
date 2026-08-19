#include <bits/stdc++.h>
using namespace std;

struct EdgeInfo {
    int to;
    int id; // state_id for (to, current node)
};

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<EdgeInfo>> adj(n + 1);
        vector<pair<int,int>> edges;
        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            edges.emplace_back(u, v);
        }
        int total_states = 2 * (n - 1);
        vector<int> x_of_id(total_states), p_of_id(total_states);
        int cur_id = 0;
        for (auto& e : edges) {
            int u = e.first, v = e.second;
            int id1 = cur_id++; // (v, u)
            int id2 = cur_id++; // (u, v)
            adj[u].push_back({v, id1});
            adj[v].push_back({u, id2});
            x_of_id[id1] = v; p_of_id[id1] = u;
            x_of_id[id2] = u; p_of_id[id2] = v;
        }

        // Choose 1 as root and compute subtree sizes
        vector<int> parent(n + 1, 0), sz(n + 1, 0);
        function<void(int, int)> dfs1 = [&](int u, int p) {
            parent[u] = p;
            sz[u] = 1;
            for (auto& e : adj[u]) {
                int v = e.to;
                if (v != p) {
                    dfs1(v, u);
                    sz[u] += sz[v];
                }
            }
        };
        dfs1(1, 0);

        // Compute size of each state
        vector<int> size_of_state(total_states, 0);
        for (int id = 0; id < total_states; ++id) {
            int x = x_of_id[id], p = p_of_id[id];
            if (parent[x] == p) {
                size_of_state[id] = sz[x];
            } else {
                // parent[p] == x must hold because (x,p) is a tree edge
                size_of_state[id] = n - sz[p];
            }
        }

        // Topological order by size
        vector<int> order(total_states);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return size_of_state[a] < size_of_state[b];
        });

        vector<int> sg_val(total_states, -1);
        int seen_size = 2 * n + 5;

        for (int id : order) {
            int x = x_of_id[id], p = p_of_id[id];
            vector<bool> seen(seen_size, false);

            auto dfs = [&](auto&& self, int u, int p_path, int steps, int acc) -> void {
                int stop_sg = acc;
                for (auto& e : adj[u]) {
                    if (e.to != p_path) {
                        stop_sg ^= sg_val[e.id];
                    }
                }
                if (stop_sg < seen_size) seen[stop_sg] = true;
                if (steps == k) return;
                for (auto& e : adj[u]) {
                    if (e.to != p_path) {
                        int new_acc = stop_sg ^ sg_val[e.id];
                        self(self, e.to, u, steps + 1, new_acc);
                    }
                }
            };

            dfs(dfs, x, p, 1, 0);

            int mex = 0;
            while (mex < seen_size && seen[mex]) ++mex;
            sg_val[id] = mex;
        }

        string ans;
        for (int s = 1; s <= n; ++s) {
            int xo = 0;
            for (auto& e : adj[s]) {
                xo ^= sg_val[e.id];
            }
            ans += (xo != 0) ? '1' : '0';
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}