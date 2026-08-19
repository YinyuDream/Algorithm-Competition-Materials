#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 300005;
const int LOG = 19;

int C, N, M;
vector<int> A, D;
vector<int> G[MAXN];

// ============== LCA and distance ==============
int dep[MAXN], par[MAXN][LOG];
void dfs_lca(int u, int p) {
    par[u][0] = p;
    for (int i = 1; i < LOG; ++i)
        par[u][i] = par[par[u][i-1]][i-1];
    for (int v : G[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs_lca(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LOG-1; i >= 0; --i)
        if (dep[u] - (1<<i) >= dep[v])
            u = par[u][i];
    if (u == v) return u;
    for (int i = LOG-1; i >= 0; --i)
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
int dist(int u, int v) {
    return dep[u] + dep[v] - 2*dep[lca(u,v)];
}

// ============== Centroid Decomposition ==============
bool dead[MAXN];
int sz[MAXN], cpar[MAXN], cdepth[MAXN];
vector<int> CT[MAXN];
int cdist[LOG][MAXN]; // cdist[k][v] = distance from v to its k-th centroid ancestor

void dfs_sz(int u, int p) {
    sz[u] = 1;
    for (int v : G[u]) if (v != p && !dead[v]) {
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}
int find_cent(int u, int p, int tot) {
    for (int v : G[u]) if (v != p && !dead[v] && sz[v] > tot/2)
        return find_cent(v, u, tot);
    return u;
}
void fill_dist(int u, int p, int depth, int d) {
    cdist[depth][u] = d;
    for (int v : G[u]) if (v != p && !dead[v])
        fill_dist(v, u, depth, d+1);
}
int decompose(int u, int depth) {
    dfs_sz(u, 0);
    int c = find_cent(u, 0, sz[u]);
    dead[c] = true;
    cdepth[c] = depth;
    fill_dist(c, 0, depth, 0);
    for (int v : G[c]) if (!dead[v]) {
        int sub = decompose(v, depth+1);
        CT[c].push_back(sub);
        cpar[sub] = c;
    }
    return c;
}
int cRoot;
int max_cd;

// ========== 链 (测试点 11-12) ==========
namespace Chain {
    struct Mat2 {
        ll m[2][2];
        Mat2() { m[0][0]=m[0][1]=m[1][0]=m[1][1]=INF; }
    };
    vector<int> L, R;
    vector<Mat2> seg;
    Mat2 single(int idx) {
        Mat2 r;
        int len = R[idx] - L[idx];
        r.m[0][0]=0; r.m[0][1]=len;
        r.m[1][0]=len; r.m[1][1]=0;
        return r;
    }
    Mat2 merge(const Mat2 &a, const Mat2 &b) {
        Mat2 c;
        for (int i : {0,1}) for (int j : {0,1})
            for (int k : {0,1})
                c.m[i][j] = min(c.m[i][j], a.m[i][k] + b.m[k][j]);
        return c;
    }
    void build(int id, int l, int r) {
        if (l == r) { seg[id] = single(l); return; }
        int m = (l+r)/2;
        build(id<<1, l, m); build(id<<1|1, m+1, r);
        seg[id] = merge(seg[id<<1], seg[id<<1|1]);
    }
    Mat2 query(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[id];
        int m = (l+r)/2;
        if (qr <= m) return query(id<<1, l, m, ql, qr);
        if (ql > m) return query(id<<1|1, m+1, r, ql, qr);
        return merge(query(id<<1, l, m, ql, qr),
                     query(id<<1|1, m+1, r, ql, qr));
    }
    void init() {
        L.resize(M); R.resize(M);
        for (int i = 0; i < M; ++i) {
            L[i] = max(1, A[i] - D[i]);
            R[i] = min(N, A[i] + D[i]);
        }
        seg.resize(4*M);
        build(1, 0, M-1);
    }
    ll answer(int x, int l, int r) {
        --l; --r;
        Mat2 m = query(1, 0, M-1, l, r);
        return min({abs(x - L[l]) + m.m[0][0],
                    abs(x - L[l]) + m.m[0][1],
                    abs(x - R[l]) + m.m[1][0],
                    abs(x - R[l]) + m.m[1][1]});
    }
}

// ========== B性质：半径很大 (13-14) ==========
int center;
void find_center() {
    auto bfs = [&](int s) {
        vector<int> d(N+1, -1);
        queue<int> q; q.push(s); d[s]=0;
        int far = s;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : G[u]) if (d[v] == -1) {
                d[v] = d[u] + 1; q.push(v);
                if (d[v] > d[far]) far = v;
            }
        }
        return make_pair(far, d);
    };
    auto p1 = bfs(1);
    auto p2 = bfs(p1.first);
    int u = p2.first, diam = p2.second[u];
    for (int i = 0; i < diam/2; ++i) u = par[u][0];
    center = u;
}

// ========== 暴力 (1-10) ==========
namespace Brute {
    ll solve(int x, int l, int r) {
        --l; --r;
        vector<ll> dp(N+1, INF);
        for (int v = 1; v <= N; ++v)
            if (dist(A[l], v) <= D[l])
                dp[v] = dist(x, v);
        for (int i = l+1; i <= r; ++i) {
            vector<ll> ndp(N+1, INF);
            for (int v = 1; v <= N; ++v)
                if (dist(A[i], v) <= D[i])
                    for (int u = 1; u <= N; ++u)
                        if (dp[u] != INF)
                            ndp[v] = min(ndp[v], dp[u] + dist(u, v));
            swap(dp, ndp);
        }
        return *min_element(dp.begin(), dp.end());
    }
}

// ========== 通用算法：点分树 + 线段树 ==========
namespace General {
    // 宝石 i 到各个重心祖先的距离是否 <= D[i]
    // 关键重心：点分树上从 A[i] 到根的路径上满足 dist(c, A[i]) <= D[i] 的那些 c
    vector<int> key_centroids[MAXN]; // 每颗宝石的关键重心列表（按 cdepth 递增）
    vector<vector<ll>> gem_mat[MAXN]; // gem_mat[i][u][v] = trans_cost(key[u], key[v], i)

    ll trans_cost(int g, int h, int i) {
        // 从重心 g 进入宝石 i，从重心 h 离开的最小总距离
        int ai = A[i], R = D[i];
        // 最小化 dist(g,p) + dist(p,h) s.t. dist(ai,p) <= R
        // 该最小值 = dist(g,h) + 2 * max(0, dist(ai, path(g,h)) - R)
        // dist(ai, path(g,h)) = min_{p on path} dist(ai,p)
        // 可以用 LCA 计算
        int l = lca(g, h);
        int dai_l = dist(ai, l);
        int dai_g = dist(ai, g);
        int dai_h = dist(ai, h);
        int closest = min({dai_g, dai_h, dai_l});
        // 但这样不准确，path 上的最近距离其实等于 (dai_g + dai_h - dist(g,h)) / 2? 不，那是到路径距离公式。
        // 正确的公式：设 p 为路径上离 ai 最近的点，若 ai 在子树中则可能是某祖先。
        // 通用公式：d = max(0, (dist(ai,g) + dist(ai,h) - dist(g,h)) / 2) 是到路径的距离？
        // 实际上，点 ai 到路径 (g,h) 的最短距离 = (dist(ai,g) + dist(ai,h) - dist(g,h)) / 2 向上取整？ 不是。
        // 正确计算：ai 到路径的最短距离等于 max(0, (dist(ai,g) + dist(ai,h) - dist(g,h)) / 2) ？ 错。
        // 令 m = lca(g,h)。最近点可能在 g..m 段或 h..m 段。最近距离 = min( dist(ai, g) - dist(g, nearest_ancestor), ...)
        // 简便方法：直接枚举路径上三个关键点：g, h, lca(g,h)，取距离最小值，因为这三点中一定有一点是离 ai 最近的“拐点”。实际上树上任意两点路径上的点到一个外部点的最近距离总可以在端点或 LCA 处取得。这是一个已知结论：点 x 到路径 u-v 的距离 = min( dist(x,u), dist(x,v), (dist(x,u)+dist(x,v)-dist(u,v))/2 )。注意后一项可能非整数，但距离都是整数，应该先算分子。
        int candidate = min({dist(ai, g), dist(ai, h),
                             (dist(ai, g) + dist(ai, h) - dist(g, h)) / 2});
        ll extra = max(0, candidate - R);
        return dist(g, h) + 2LL * extra;
    }

    void prepare_gems() {
        for (int i = 0; i < M; ++i) {
            vector<int> &keys = key_centroids[i];
            int u = A[i];
            // 沿着点分树向上走，直到根，收集所有距离 <= D[i] 的重心
            while (u != 0) {
                if (dist(u, A[i]) <= D[i])
                    keys.push_back(u);
                u = cpar[u];
            }
            reverse(keys.begin(), keys.end()); // 深度递增
            int k = keys.size();
            gem_mat[i].assign(k, vector<ll>(k, INF));
            for (int a = 0; a < k; ++a)
                for (int b = 0; b < k; ++b)
                    gem_mat[i][a][b] = trans_cost(keys[a], keys[b], i);
        }
    }

    // 合并两个有序列表并去重，返回新列表
    vector<int> merge_keys(const vector<int> &A, const vector<int> &B) {
        vector<int> C;
        int i = 0, j = 0;
        while (i < (int)A.size() && j < (int)B.size()) {
            if (A[i] < B[j]) { C.push_back(A[i++]); }
            else if (A[i] > B[j]) { C.push_back(B[j++]); }
            else { C.push_back(A[i]); i++; j++; }
        }
        while (i < (int)A.size()) C.push_back(A[i++]);
        while (j < (int)B.size()) C.push_back(B[j++]);
        return C;
    }

    struct Node {
        vector<int> keys;            // 该区间所有关键重心的有序列表（去重）
        vector<vector<ll>> mat;      // 矩阵，大小为 keys.size()
    };

    Node tree[1 << 20]; // 4 * M

    Node merge_node(const Node &a, const Node &b) {
        if (a.keys.empty()) return b;
        if (b.keys.empty()) return a;
        Node res;
        res.keys = merge_keys(a.keys, b.keys);
        int n = res.keys.size();
        int na = a.keys.size(), nb = b.keys.size();
        res.mat.assign(n, vector<ll>(n, INF));
        // 映射函数
        auto ida = [&](int v) {
            return lower_bound(a.keys.begin(), a.keys.end(), v) - a.keys.begin();
        };
        auto idb = [&](int v) {
            return lower_bound(b.keys.begin(), b.keys.end(), v) - b.keys.begin();
        };
        auto idr = [&](int v) {
            return lower_bound(res.keys.begin(), res.keys.end(), v) - res.keys.begin();
        };
        // 现在对于每对 (u,v) ∈ res.keys^2，我们需要计算经过 a 区间再经过 b 区间的最小代价
        // 枚举衔接点 w ∈ res.keys，若 w 在 a 中且 w 在 b 中，则 cost = a.mat[ida(w)][ida(w)?]... 不对，
        // 应该枚举 w 在 a 的出口，且在 b 的入口。实际上两个区间顺序是 a 后 b，所以路径 u -> ... -> w (离开 a) -> w (进入 b) -> ... -> v
        // 要求 w 同时在 a.keys 和 b.keys 中。
        for (int u : res.keys) {
            int iu = idr(u);
            for (int v : res.keys) {
                int iv = idr(v);
                ll &best = res.mat[iu][iv];
                for (int w : res.keys) {
                    if (!binary_search(a.keys.begin(), a.keys.end(), w)) continue;
                    if (!binary_search(b.keys.begin(), b.keys.end(), w)) continue;
                    int iwa = ida(w);
                    int iwb = idb(w);
                    if (a.mat[ida(u)][iwa] >= INF || b.mat[iwb][idb(v)] >= INF) continue;
                    best = min(best, a.mat[ida(u)][iwa] + b.mat[iwb][idb(v)]);
                }
            }
        }
        return res;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            tree[id].keys = key_centroids[l];
            tree[id].mat = gem_mat[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id<<1, l, mid);
        build(id<<1|1, mid+1, r);
        tree[id] = merge_node(tree[id<<1], tree[id<<1|1]);
    }

    Node query(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[id];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(id<<1, l, mid, ql, qr);
        if (ql > mid) return query(id<<1|1, mid+1, r, ql, qr);
        return merge_node(query(id<<1, l, mid, ql, qr),
                          query(id<<1|1, mid+1, r, ql, qr));
    }

    void init() {
        max_cd = 0;
        for (int i = 1; i <= N; ++i)
            if (!dead[i]) max_cd = max(max_cd, cdepth[i]);
        prepare_gems();
        build(1, 0, M-1);
    }

    ll answer(int x, int l, int r) {
        --l; --r;
        Node res = query(1, 0, M-1, l, r);
        // 初始向量：从起点 x 到第一个区间的各个接口重心的距离
        vector<ll> init_vec(res.keys.size(), INF);
        for (int i = 0; i < (int)res.keys.size(); ++i) {
            init_vec[i] = dist(x, res.keys[i]);
        }
        // 与矩阵相乘：ans = min_k init[k] + mat[k][*]
        ll ans = INF;
        for (int i = 0; i < (int)res.keys.size(); ++i) {
            for (int j = 0; j < (int)res.keys.size(); ++j) {
                ans = min(ans, init_vec[i] + res.mat[i][j]);
            }
        }
        return ans;
    }
}

// ========== 主接口 ==========
void gems(int c, int n, int m, vector<int> u, vector<int> v,
          vector<int> a, vector<int> d) {
    C = c; N = n; M = m;
    A = a; D = d;
    for (int i = 0; i <= N; ++i) G[i].clear();
    for (int i = 0; i < n-1; ++i) {
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    dfs_lca(1, 1);

    if (C <= 10) { /* brute */ }
    else if (C == 11 || C == 12) Chain::init();
    else if (C == 13 || C == 14) find_center();
    else {
        // 构建点分树与通用线段树
        memset(dead, 0, sizeof dead);
        cRoot = decompose(1, 0);
        General::init();
    }
}

long long query(int x, int l, int r) {
    if (C <= 10) return Brute::solve(x, l, r);
    if (C == 11 || C == 12) return Chain::answer(x, l, r);
    if (C == 13 || C == 14) return dist(x, center);
    return General::answer(x, l, r);
}