#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;

struct Op {
    int t, x, y, l, r;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> out(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        out[u].push_back(v);
    }

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<Op> ops(q);
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> ops[i].x >> ops[i].y;
            ops[i].t = 1;
        } else if (t == 2) {
            cin >> ops[i].x >> ops[i].y;
            ops[i].t = 2;
        } else {
            cin >> ops[i].x >> ops[i].l >> ops[i].r;
            ops[i].t = 3;
        }
    }

    const int B = 700; // 块大小
    for (int L = 0; L < q; L += B) {
        int R = min(q, L + B);

        // 收集块内修改涉及的点 S_mod
        vector<int> S_mod_list;
        vector<bool> is_smod(n + 1, false);
        // 收集询问的 x 集合 X_qry
        vector<int> X_qry_list;
        vector<int> x_to_idx(n + 1, -1);

        for (int i = L; i < R; ++i) {
            if (ops[i].t == 1 || ops[i].t == 2) {
                int x = ops[i].x, y = ops[i].y;
                if (!is_smod[x]) { is_smod[x] = true; S_mod_list.push_back(x); }
                if (!is_smod[y]) { is_smod[y] = true; S_mod_list.push_back(y); }
            } else {
                int x = ops[i].x;
                if (x_to_idx[x] == -1) {
                    x_to_idx[x] = X_qry_list.size();
                    X_qry_list.push_back(x);
                }
            }
        }

        int K = X_qry_list.size();
        if (K == 0) {
            // 没有询问，直接应用修改并跳过
            for (int i = L; i < R; ++i) {
                if (ops[i].t == 1) swap(a[ops[i].x], a[ops[i].y]);
                else if (ops[i].t == 2) swap(b[ops[i].x], b[ops[i].y]);
            }
            continue;
        }

        // 正向传播求 reach 掩码
        int M = (K + 63) / 64;
        vector<vector<u64>> reach(n + 1, vector<u64>(M, 0));
        for (int idx = 0; idx < K; ++idx) {
            int x = X_qry_list[idx];
            reach[x][idx / 64] |= (1ULL << (idx % 64));
        }
        for (int u = 1; u <= n; ++u) {
            auto &ru = reach[u];
            for (int v : out[u]) {
                auto &rv = reach[v];
                for (int j = 0; j < M; ++j) {
                    rv[j] |= ru[j];
                }
            }
        }

        // base_a_to_node 只在未修改点上有值
        vector<int> base_a_to_node(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            if (!is_smod[i])
                base_a_to_node[a[i]] = i;

        // 分块建立 best 数组
        const int S = 300; // a 值分块大小
        int B_a = (n + S - 1) / S;
        vector<vector<int>> best(B_a, vector<int>(K, 0));

        for (int y = 1; y <= n; ++y) {
            if (is_smod[y]) continue;
            int bid = (a[y] - 1) / S;
            int *best_ptr = best[bid].data();
            u64 *ry = reach[y].data();
            for (int j = 0; j < M; ++j) {
                u64 w = ry[j];
                while (w) {
                    int bit = __builtin_ctzll(w);
                    int idx = j * 64 + bit;
                    if (b[y] > best_ptr[idx]) best_ptr[idx] = b[y];
                    w &= w - 1;
                }
            }
        }

        // 块内当前状态
        vector<int> cur_a(a);
        vector<int> cur_b(b);

        // 处理本块所有操作
        for (int i = L; i < R; ++i) {
            if (ops[i].t == 1) {
                swap(cur_a[ops[i].x], cur_a[ops[i].y]);
            } else if (ops[i].t == 2) {
                swap(cur_b[ops[i].x], cur_b[ops[i].y]);
            } else {
                int x = ops[i].x, l = ops[i].l, r = ops[i].r;
                int idx = x_to_idx[x];
                int ans = 0;

                if (l <= r) {
                    int bl = (l - 1) / S, br = (r - 1) / S;
                    // 整块
                    for (int bid = bl + 1; bid < br; ++bid)
                        if (best[bid][idx] > ans) ans = best[bid][idx];
                    // 左边界
                    int lim = min(r, (bl + 1) * S);
                    for (int av = l; av <= lim; ++av) {
                        int y = base_a_to_node[av];
                        if (y && ((reach[y][idx / 64] >> (idx % 64)) & 1))
                            if (cur_b[y] > ans) ans = cur_b[y];
                    }
                    // 右边界
                    if (br > bl) {
                        for (int av = br * S + 1; av <= r; ++av) {
                            int y = base_a_to_node[av];
                            if (y && ((reach[y][idx / 64] >> (idx % 64)) & 1))
                                if (cur_b[y] > ans) ans = cur_b[y];
                        }
                    }
                }

                // 被修改过的点
                for (int s : S_mod_list) {
                    if (cur_a[s] >= l && cur_a[s] <= r) {
                        if ((reach[s][idx / 64] >> (idx % 64)) & 1) {
                            if (cur_b[s] > ans) ans = cur_b[s];
                        }
                    }
                }

                cout << ans << '\n';
            }
        }

        // 块内修改写回全局
        a.swap(cur_a);
        b.swap(cur_b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, T;
    cin >> c >> T;
    while (T--) solve();
    return 0;
}