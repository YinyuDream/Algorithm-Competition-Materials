#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;

const ll INF = 4e18;
const int MOD = 998244353;
const int MAXN = 200005;
const int MAXM = 200005;

int n, m, q;
ll a[MAXN], b[MAXM], t[MAXN], t0;
ll preA_global[MAXN], preB[MAXM];

struct QueryBlock {
    int c;
    int L, R;
    int d, u;
    int qid;
};

ll ans[MAXN];

inline ll mod(i128 x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return (ll)x;
}

struct SegTree {
    struct Node {
        i128 sumA;
        ll left_A, right_A;
        ll tag_k, tag_d;
        bool has_tag;
    };
    vector<Node> tree;
    int m;
    SegTree(int _m) : m(_m) {
        tree.resize(4 * m + 5);
        build(1, 1, m);
    }
    void build(int node, int l, int r) {
        tree[node].sumA = 0;
        tree[node].left_A = tree[node].right_A = INF;
        tree[node].has_tag = false;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(node<<1, l, mid);
        build(node<<1|1, mid+1, r);
    }
    void apply_tag(int node, int l, int r, ll k, ll d) {
        tree[node].tag_k = k;
        tree[node].tag_d = d;
        tree[node].has_tag = true;
        tree[node].left_A = k * b[l] + d;
        tree[node].right_A = k * b[r] + d;
        i128 sumB = preB[r] - preB[l-1];
        tree[node].sumA = (i128)k * sumB + (i128)d * (r - l + 1);
    }
    void push_down(int node, int l, int r) {
        if (tree[node].has_tag) {
            int mid = (l + r) >> 1;
            apply_tag(node<<1, l, mid, tree[node].tag_k, tree[node].tag_d);
            apply_tag(node<<1|1, mid+1, r, tree[node].tag_k, tree[node].tag_d);
            tree[node].has_tag = false;
        }
    }
    void update(int node, int l, int r, int ql, int qr, ll k, ll d) {
        if (ql <= l && r <= qr) {
            apply_tag(node, l, r, k, d);
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) update(node<<1, l, mid, ql, qr, k, d);
        if (qr > mid) update(node<<1|1, mid+1, r, ql, qr, k, d);
        tree[node].left_A = tree[node<<1].left_A;
        tree[node].right_A = tree[node<<1|1].right_A;
        tree[node].sumA = tree[node<<1].sumA + tree[node<<1|1].sumA;
    }
    i128 query_sumA(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node].sumA;
        }
        push_down(node, l, r);
        int mid = (l + r) >> 1;
        i128 res = 0;
        if (ql <= mid) res += query_sumA(node<<1, l, mid, ql, qr);
        if (qr > mid) res += query_sumA(node<<1|1, mid+1, r, ql, qr);
        return res;
    }
    int find_first_X(int node, int l, int r, ll X, ll tc) {
        if (l == r) {
            ll val = tree[node].has_tag ? (tree[node].tag_k * b[l] + tree[node].tag_d) : tree[node].left_A;
            if (val - tc * b[l] < X) return l;
            else return -1;
        }
        if (tree[node].right_A - tc * b[r] >= X) return -1;
        push_down(node, l, r);
        int mid = (l + r) >> 1;
        if (tree[node<<1].right_A - tc * b[mid] < X) {
            return find_first_X(node<<1, l, mid, X, tc);
        } else {
            return find_first_X(node<<1|1, mid+1, r, X, tc);
        }
    }
    int find_last_less(int node, int l, int r, ll k, ll d) {
        if (l == r) {
            ll val = tree[node].has_tag ? (tree[node].tag_k * b[l] + tree[node].tag_d) : tree[node].left_A;
            if (val - (k * b[l] + d) > 0) return l;
            else return l - 1;
        }
        ll f_left = tree[node].left_A - (k * b[l] + d);
        ll f_right = tree[node].right_A - (k * b[r] + d);
        if (f_left <= 0) return l - 1;
        if (f_right > 0) return r;
        push_down(node, l, r);
        int mid = (l + r) >> 1;
        ll f_right_left = tree[node<<1|1].left_A - (k * b[mid+1] + d);
        if (f_right_left > 0) {
            return find_last_less(node<<1|1, mid+1, r, k, d);
        } else {
            return find_last_less(node<<1, l, mid, k, d);
        }
    }
};

void process_segment(int c, SegTree &segTree, vector<QueryBlock> &blocks,
                     const vector<int> &rec, const vector<int> &seg_start, const vector<int> &seg_end) {
    int L_start = seg_start[c];
    int R_end = seg_end[c];
    int sz = R_end - L_start + 1;
    ll tc = t[rec[c]];
    vector<ll> a_vals(sz);
    vector<int> J_vals(sz);
    vector<i128> H_vals(sz);
    for (int i = L_start; i <= R_end; ++i) {
        int loc = i - L_start;
        a_vals[loc] = a[i];
        ll X = 2LL * t0 * a[i];
        int j0 = segTree.find_first_X(1, 1, m, X, tc);
        if (j0 == -1) {
            J_vals[loc] = m + 1;
            H_vals[loc] = 0;
        } else {
            J_vals[loc] = j0;
            i128 preW = 0;
            if (j0 > 1) {
                i128 sumA = segTree.query_sumA(1, 1, m, 1, j0 - 1);
                preW = sumA - (i128)tc * preB[j0 - 1];
            }
            H_vals[loc] = (i128)2 * t0 * a[i] * j0 - preW;
        }
    }
    vector<i128> preA_loc(sz + 1, 0), preH_loc(sz + 1, 0);
    for (int loc = 0; loc < sz; ++loc) {
        preA_loc[loc + 1] = preA_loc[loc] + a_vals[loc];
        preH_loc[loc + 1] = preH_loc[loc] + H_vals[loc];
    }
    for (auto &blk : blocks) {
        int L_global = blk.L, R_global = blk.R;
        int d = blk.d, u = blk.u, qid = blk.qid;
        int loc_l = L_global - L_start;
        int loc_r = R_global - L_start;
        int cnt = loc_r - loc_l + 1;
        i128 sum_a_seg = preA_loc[loc_r + 1] - preA_loc[loc_l];
        i128 sum_b = preB[u] - preB[d-1];
        i128 S_sum = (i128)t0 * (u - d + 1) * sum_a_seg + (i128)tc * sum_b * cnt;
        int pos1 = loc_r + 1;
        int l_tmp = loc_l, r_tmp = loc_r;
        while (l_tmp <= r_tmp) {
            int mid = (l_tmp + r_tmp) >> 1;
            if (J_vals[mid] <= u) { pos1 = mid; r_tmp = mid - 1; }
            else l_tmp = mid + 1;
        }
        int pos2 = loc_r + 1;
        l_tmp = loc_l; r_tmp = loc_r;
        while (l_tmp <= r_tmp) {
            int mid = (l_tmp + r_tmp) >> 1;
            if (J_vals[mid] <= d) { pos2 = mid; r_tmp = mid - 1; }
            else l_tmp = mid + 1;
        }
        i128 Delta = 0;
        i128 preW_u = 0, preW_dminus1 = 0;
        if (pos2 <= loc_r || pos1 <= pos2 - 1) {
            i128 sumA_u = segTree.query_sumA(1, 1, m, 1, u);
            preW_u = sumA_u - (i128)tc * preB[u];
            if (d > 1) {
                i128 sumA_dm1 = segTree.query_sumA(1, 1, m, 1, d - 1);
                preW_dminus1 = sumA_dm1 - (i128)tc * preB[d - 1];
            }
        }
        if (pos2 <= loc_r) {
            int loc_start_full = pos2;
            int cnt_full = loc_r - loc_start_full + 1;
            i128 sum_a_full = preA_loc[loc_r + 1] - preA_loc[loc_start_full];
            Delta += (i128)(-2) * t0 * (u - d + 1) * sum_a_full + (i128)cnt_full * (preW_u - preW_dminus1);
        }
        if (pos1 <= pos2 - 1) {
            int loc_start_mid = pos1;
            int loc_end_mid = pos2 - 1;
            int cnt_mid = loc_end_mid - loc_start_mid + 1;
            i128 sum_a_mid = preA_loc[loc_end_mid + 1] - preA_loc[loc_start_mid];
            i128 sum_H_mid = preH_loc[loc_end_mid + 1] - preH_loc[loc_start_mid];
            Delta += (i128)(-2) * t0 * (u + 1) * sum_a_mid + (i128)cnt_mid * preW_u + sum_H_mid;
        }
        i128 contrib = S_sum + Delta;
        ans[qid] = (ans[qid] + mod(contrib)) % MOD;
    }
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) cin >> t[i];
    cin >> t0;
    // prefix sums
    preA_global[0] = 0;
    for (int i = 1; i <= n; ++i) preA_global[i] = preA_global[i-1] + a[i];
    preB[0] = 0;
    for (int i = 1; i <= m; ++i) preB[i] = preB[i-1] + b[i];
    // find record points (strict prefix minima of t)
    vector<int> rec;
    rec.push_back(1);
    ll min_t = t[1];
    for (int i = 2; i <= n; ++i) {
        if (t[i] < min_t) {
            rec.push_back(i);
            min_t = t[i];
        }
    }
    int K = rec.size();
    vector<int> seg_start(K), seg_end(K), seg_of_i(n+1);
    for (int c = 0; c < K; ++c) {
        seg_start[c] = rec[c];
        if (c + 1 < K) seg_end[c] = rec[c+1] - 1;
        else seg_end[c] = n;
        for (int i = seg_start[c]; i <= seg_end[c]; ++i) {
            seg_of_i[i] = c;
        }
    }
    vector<vector<QueryBlock>> blocks(K);
    // decompose queries into blocks
    for (int i = 1; i <= q; ++i) {
        int l, r, d, u; cin >> l >> r >> d >> u;
        int cl = seg_of_i[l], cr = seg_of_i[r];
        if (cl == cr) {
            blocks[cl].push_back({cl, l, r, d, u, i});
        } else {
            blocks[cl].push_back({cl, l, seg_end[cl], d, u, i});
            for (int c = cl + 1; c <= cr - 1; ++c) {
                blocks[c].push_back({c, seg_start[c], seg_end[c], d, u, i});
            }
            blocks[cr].push_back({cr, seg_start[cr], r, d, u, i});
        }
    }
    for (int i = 1; i <= q; ++i) ans[i] = 0;
    // segment K-1 is the rightmost one, only S candidate
    if (K > 0) {
        int cK = K - 1;
        for (auto &blk : blocks[cK]) {
            i128 sum_a = preA_global[blk.R] - preA_global[blk.L - 1];
            i128 sum_b = preB[blk.u] - preB[blk.d - 1];
            i128 contrib = (i128)t0 * (blk.u - blk.d + 1) * sum_a + (i128)t[rec[cK]] * sum_b * (blk.R - blk.L + 1);
            ans[blk.qid] = (ans[blk.qid] + mod(contrib)) % MOD;
        }
    }
    // for other segments, use dynamic lower envelope of right candidates
    if (K > 1) {
        SegTree segTree(m);
        for (int y = K - 1; y >= 1; --y) {
            int idx = rec[y];
            ll k = t[idx];
            ll d_val = 2LL * t0 * a[idx];
            int pos = segTree.find_last_less(1, 1, m, k, d_val);
            if (pos >= 1) {
                segTree.update(1, 1, m, 1, pos, k, d_val);
            }
            int c = y - 1;
            if (!blocks[c].empty()) {
                process_segment(c, segTree, blocks[c], rec, seg_start, seg_end);
            }
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << (i == q ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}