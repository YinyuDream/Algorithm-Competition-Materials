#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<int> cnt;
    vector<ll> sumx;
    const vector<ll>* xs;
    BIT(int sz, const vector<ll>* xs_ptr) : n(sz), cnt(sz+1, 0), sumx(sz+1, 0), xs(xs_ptr) {}
    void add(int p, int dc, ll ds) {
        for (; p <= n; p += p & -p) {
            cnt[p] += dc;
            sumx[p] += ds;
        }
    }
    int total_cnt() {
        int res = 0;
        for (int p = n; p > 0; p -= p & -p) res += cnt[p];
        return res;
    }
    ll total_sum() {
        ll res = 0;
        for (int p = n; p > 0; p -= p & -p) res += sumx[p];
        return res;
    }
    // 返回升序第 k 小的值 以及 前 k 小的 sum
    pair<ll, ll> query_kth_smallest(int k) {
        if (k <= 0) return {0, 0};
        int tot = total_cnt();
        if (k > tot) return {xs->back(), total_sum()};
        int orig_k = k;
        int idx = 0;
        int highest = 1;
        while (highest <= n) highest <<= 1;
        highest >>= 1;
        for (int step = highest; step > 0; step >>= 1) {
            int next = idx + step;
            if (next <= n && cnt[next] < k) {
                k -= cnt[next];
                idx = next;
            }
        }
        int pos = idx + 1;
        int cnt_before = 0;
        ll sum_before = 0;
        for (int p = pos - 1; p > 0; p -= p & -p) {
            cnt_before += cnt[p];
            sum_before += sumx[p];
        }
        ll val = (*xs)[pos - 1];
        ll sum_k = sum_before + (orig_k - cnt_before) * val;
        return {val, sum_k};
    }
};

void solve() {
    int n;
    cin >> n;
    vector<char> ops(n);
    vector<int> vals(n); // For F: x; For W: 0
    vector<int> W_pos;
    for (int i = 1; i <= n; i++) {
        string op;
        cin >> op;
        ops[i-1] = op[0];
        if (op[0] == 'F') {
            int x; cin >> x;
            vals[i-1] = x;
        } else {
            W_pos.push_back(i);
        }
    }
    int m = W_pos.size();
    if (m == 0) {
        cout << "0\n";
        return;
    }
    // 离散化所有工厂容量
    vector<ll> xs;
    for (int i = 0; i < n; i++) if (ops[i] == 'F') xs.push_back(vals[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    int SZ = xs.size();
    BIT bit(SZ, &xs);
    
    // 收集所有工厂 (建立时间, 容量)
    vector<pair<int, ll>> factories; // (t, x)
    for (int i = 1; i <= n; i++) {
        if (ops[i-1] == 'F') factories.push_back({i, vals[i-1]});
    }
    int f_idx = 0;
    // 将第一个 W 之前的工厂作为初始历史工厂插入 BIT
    while (f_idx < (int)factories.size() && factories[f_idx].first < W_pos[0]) {
        ll x = factories[f_idx].second;
        int r = lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
        bit.add(r, 1, x);
        f_idx++;
    }
    ll ans = 0;
    for (int k = 0; k < m; k++) {
        int p_k = W_pos[k];
        int p_next = (k+1 < m) ? W_pos[k+1] : n+1;
        ll L = p_next - p_k;
        // 收集本段新工厂 N_k
        vector<pair<ll, ll>> N; // (w, x)
        while (f_idx < (int)factories.size() && factories[f_idx].first < p_next) {
            if (factories[f_idx].first > p_k) {
                ll t = factories[f_idx].first;
                ll x = factories[f_idx].second;
                ll w = x * (p_next - t);
                N.push_back({w, x});
            }
            f_idx++;
        }
        // 按权重 w 降序
        sort(N.begin(), N.end(), [](auto& a, auto& b){ return a.first > b.first; });
        vector<ll> N_w, N_pref(1, 0);
        for (auto& p : N) N_w.push_back(p.first);
        for (ll w : N_w) N_pref.push_back(N_pref.back() + w);
        
        int H_sz = bit.total_cnt();
        int N_sz = N.size();
        int kw = k + 1; // 当前工人数
        if (kw >= H_sz + N_sz) {
            ans += bit.total_sum() * L + N_pref.back();
        } else {
            auto get_H_x = [&](int i) -> ll {
                if (i <= 0 || i > bit.total_cnt()) return -1;
                int kth = bit.total_cnt() - i + 1;
                return bit.query_kth_smallest(kth).first;
            };
            auto get_H_sum_x = [&](int i) -> ll {
                if (i <= 0) return 0;
                if (i >= bit.total_cnt()) return bit.total_sum();
                int k_exclude = bit.total_cnt() - i;
                ll sum_ex = bit.query_kth_smallest(k_exclude).second;
                return bit.total_sum() - sum_ex;
            };
            int low = max(0, kw - N_sz);
            int high = min(kw, H_sz);
            while (low <= high) {
                int mid = (low + high) / 2;
                int s = kw - mid;
                bool ok1 = true, ok2 = true;
                if (mid > 0 && s < N_sz) {
                    ll H_mid = get_H_x(mid) * L;
                    ll N_next = N_w[s];
                    if (H_mid < N_next) ok1 = false;
                }
                if (s > 0 && mid < H_sz) {
                    ll N_s = N_w[s-1];
                    ll H_next = get_H_x(mid + 1) * L;
                    if (N_s < H_next) ok2 = false;
                }
                if (ok1 && ok2) {
                    ans += get_H_sum_x(mid) * L + N_pref[s];
                    break;
                }
                if (!ok1) high = mid - 1;
                else if (!ok2) low = mid + 1;
            }
        }
        // 本段新工厂变为下一段的历史工厂
        for (auto& p : N) {
            ll x = p.second;
            int r = lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
            bit.add(r, 1, x);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}