#include <bits/stdc++.h>

using ull = unsigned long long;

constexpr int mod = 998244353;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y < 0 ? x - y + mod : x - y;
}

constexpr int N = 1e6 + 5;

int n, m, ml, dp[N], dis[N], end[N];

struct Bitset {
    std::vector<ull> a;
    void flip(const int& i) { a[i >> 6] ^= 1ull << (i & 63); }
    bool get(const int& i) const { return (a[i >> 6] >> (i & 63)) & 1; }
    void set(const int& i, const bool& x) { if (get(i) != x) { flip(i); } }
    void read() {
        a.resize(ml);
        std::string str; std::cin >> str;
        for (int i = 0; i < m; i++) { set(m - 1 - i, str[i] - '0'); }
    }
} L, R;

struct Basis {
    std::vector<Bitset> a;
    void insert(Bitset x) {
        for (int p = ml - 1; ; ) {
            while (p >= 0 && x.a[p] == 0) { p--; }
            if (p < 0) { break; }
            int i = p << 6 | (__builtin_clzll(x.a[p]) ^ 63);
            if (a[i].a.empty()) { a[i] = x; return; }
            for (int j = p; j >= 0; j--) { x.a[j] ^= a[i].a[j]; }
        }
    }
} f[N];

struct OrthogonalBasis {
    std::vector<Bitset> a;
    std::vector<int> v;
    void insert(Bitset x, int u) {
        for (int p = 0; ; ) {
            while (p < ml && x.a[p] == 0) { p++; }
            if (p == ml) { break; }
            int i = p << 6 | __builtin_ctzll(x.a[p]);
            if (a[i].a.empty()) { a[i] = x; v[i] = u; return; }
            if (v[i] < u) { std::swap(a[i], x); std::swap(v[i], u); }
            for (int j = p; j < ml; j++) { x.a[j] ^= a[i].a[j]; }
        }
    }
    std::string query(const Bitset& x, int u, int o) {
        Bitset y; y.a.resize(ml);
        int lst = m, gg = 0;
        std::string str;
        for (int i = m - 1; i >= 0; i--) {
            if (v[i] >= u) {
                bool bit = 0;
                if (!a[i].a.empty()) {
                    for (int p = ml - 1; p >= (i >> 6); p--) {
                        bit ^= __builtin_parityll(y.a[p] & a[i].a[p]);
                    }
                }
                if (lst != -1 && x.get(i) != bit) {
                    if (bit) {
                        gg = 1; break;
                    } else {
                        lst = -1;
                    }
                }
                if (bit) { y.flip(i); }
            } else {
                if (lst == -1) { 
                    y.flip(i); str += '1';
                } else {
                    if (x.get(i)) { y.flip(i); str += '1'; lst = gg ? lst : i; } else { str += '0'; }
                }
            }
        }
        if (o == 0 && lst != -1) { gg = 1; }
        if (gg == 0) { return str; }
        if (lst == m) { return "-"; }
        str = ""; y.a.assign(ml, 0);
        for (int i = m - 1; i >= 0; i--) {
            if (v[i] >= u) {
                bool bit = 0;
                if (!a[i].a.empty()) {
                    for (int p = ml - 1; p >= (i >> 6); p--) {
                        bit ^= __builtin_parityll(y.a[p] & a[i].a[p]);
                    }
                }
                if (bit) { y.flip(i); }
            } else {
                if (lst == i) { 
                    str += '0';
                } else if (lst > i) {
                    y.flip(i); str += '1';
                } else {
                    if (x.get(i)) { y.flip(i); str += '1'; } else { str += '0'; }
                }
            }
        }
        return str;
    }
} g;

void fennec(Basis& f, int u) {
    Basis h; h.a.resize(m);
    for (int i = 0; i < m; i++) { if (f.a[i].a.empty()) { h.a[i].a.resize(ml); } }
    for (int i = m - 1; i >= 0; i--) {
        if (f.a[i].a.empty()) {
            h.a[i].flip(i); g.insert(h.a[i], u);
        } else {
            Bitset x; x.a.swap(f.a[i].a); x.flip(i);
            for (int p = ml - 1; ; ) {
                while (p >= 0 && x.a[p] == 0) { p--; }
                if (p < 0) { break; }
                int j = p << 6 | (__builtin_clzll(x.a[p]) ^ 63);
                if (f.a[j].a.empty()) {
                    h.a[j].flip(i); x.flip(j);
                } else {
                    for (int k = p; k >= 0; k--) { x.a[k] ^= f.a[j].a[k]; }
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m; ml = (m + 63) / 64;
    L.read(); R.read();
    g.a.resize(m); g.v.assign(m, 0);
    for (int i = 0; i < n; i++) {
        f[i].a.resize(m);
        for (int j = 0; j < m; j++) {
            Bitset x; x.read();
            f[i].insert(x);
        }
        fennec(f[i], i + 1);
        dp[i] = i ? add(dp[i], dp[i - 1]) : 1;
        for (int u = 0, v, u0 = 0, w, l, r, lst = 0; u0 <= n; u0 = u, u = v) {
            v = n + 1;
            for (int j = 0; j < m; j++) {
                if (g.v[j] > u) { v = std::min(v, g.v[j]); }    
            }
            std::string s = g.query(R, u, 1), t = g.query(L, u, 0);
            if (s == t) { continue; }
            if (dis[i + 1] == 0) { dis[i + 1] = dis[u0] + 1; end[dis[i + 1]] = i + 1; }
            if (u0 > end[dis[i + 1] - 1]) { break; }
            l = 0; r = 0;
            for (auto c : t) { l = add(l, l); if (c == '1') { l = add(l, 1); } }
            for (auto c : s) { r = add(r, r); if (c == '1') { r = add(r, 1); } }
            if (t != "-") { l = add(l, 1); }
            if (s != "-") { r = add(r, 1); }
            w = sub(r, l);
            dp[i + 1] = add(dp[i + 1], 1ll * sub(w, lst) * sub(dp[end[dis[i + 1] - 1]], u0 ? dp[u0 - 1] : 0) % mod); lst = w;
        }
    }
    std::cout << dp[n] << "\n";
    return 0;
}