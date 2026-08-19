#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int G = 3; // primitive root for MOD

// fast exponentiation modulo MOD
int powmod(int a, int e) {
    int res = 1;
    while (e) {
        if (e & 1) res = (long long)res * a % MOD;
        a = (long long)a * a % MOD;
        e >>= 1;
    }
    return res;
}

// in-place NTT, invert = true for inverse transform
void ntt(vector<int>& a, bool invert) {
    int n = a.size();
    // bit-reversal permutation
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    // transform
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = powmod(G, (MOD - 1) / len);
        if (invert) wlen = powmod(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = (long long)a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = (long long)w * wlen % MOD;
            }
        }
    }

    if (invert) {
        int n_inv = powmod(n, MOD - 2);
        for (int& x : a) x = (long long)x * n_inv % MOD;
    }
}

// polynomial multiplication, uses NTT for large, brute force for small
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) return {};
    // threshold for brute force
    if (min(a.size(), b.size()) <= 128) {
        vector<int> c(a.size() + b.size() - 1, 0);
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] == 0) continue;
            for (size_t j = 0; j < b.size(); j++) {
                c[i + j] = (c[i + j] + (long long)a[i] * b[j]) % MOD;
            }
        }
        return c;
    }
    int n = 1;
    while (n < (int)(a.size() + b.size() - 1)) n <<= 1;
    vector<int> fa = a, fb = b;
    fa.resize(n, 0); fb.resize(n, 0);
    ntt(fa, false); ntt(fb, false);
    for (int i = 0; i < n; i++) fa[i] = (long long)fa[i] * fb[i] % MOD;
    ntt(fa, true);
    fa.resize(a.size() + b.size() - 1);
    return fa;
}

// polynomial wrapper for priority queue
struct Poly {
    vector<int> coef;
};

// comparator for min-heap based on polynomial degree
struct PolyCmp {
    bool operator()(const Poly& a, const Poly& b) const {
        return a.coef.size() > b.coef.size(); // smaller size first
    }
};

// 3D grid key
struct GridKey {
    int i, j, k;
    bool operator==(const GridKey& o) const {
        return i == o.i && j == o.j && k == o.k;
    }
};

// hash for grid key
struct GridKeyHash {
    size_t operator()(const GridKey& k) const {
        // combine three ints
        return ((size_t)k.i * 1000000007) ^ 
               ((size_t)k.j * 1000000009) ^ 
               ((size_t)k.k * 1000000021);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n), z(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
    }

    long long d2 = 1LL * d * d;
    // find maximum k such that 3*k^2 < d^2
    long long low = 0, high = d;
    while (low < high) {
        long long mid = (low + high + 1) >> 1;
        if (3LL * mid * mid < d2) low = mid;
        else high = mid - 1;
    }
    long long k_val = low;
    int L = (int)(k_val + 1);
    int R = (d + L - 2) / L;   // = ceil((d-1) / L)

    // place contestants into grid cells
    unordered_map<GridKey, vector<int>, GridKeyHash> grid_map;
    grid_map.reserve(n * 2);
    bool possible = true;
    for (int i = 0; i < n; i++) {
        int ix = x[i] / L;
        int iy = y[i] / L;
        int iz = z[i] / L;
        GridKey key{ix, iy, iz};
        auto& vec = grid_map[key];
        vec.push_back(i);
        if (vec.size() >= 3) {
            possible = false;
            break;
        }
    }
    if (!possible) {
        for (int i = 1; i <= n - 1; i++) cout << "0\n";
        return 0;
    }

    // BFS to 2-color the graph and extract connected components
    vector<int> color(n, -1);
    vector<Poly> polys;
    for (int s = 0; s < n; s++) {
        if (color[s] != -1) continue;
        queue<int> q;
        q.push(s);
        color[s] = 0;
        int cnt0 = 0, cnt1 = 0;
        long long prod0 = 1, prod1 = 1;
        bool fail = false;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (color[u] == 0) {
                cnt0++;
                prod0 = prod0 * w[u] % MOD;
            } else {
                cnt1++;
                prod1 = prod1 * w[u] % MOD;
            }

            int I = x[u] / L;
            int J = y[u] / L;
            int K = z[u] / L;

            for (int di = -R; di <= R && !fail; di++) {
                int ni = I + di;
                for (int dj = -R; dj <= R && !fail; dj++) {
                    int nj = J + dj;
                    for (int dk = -R; dk <= R && !fail; dk++) {
                        int nk = K + dk;
                        GridKey nkey{ni, nj, nk};
                        auto it = grid_map.find(nkey);
                        if (it == grid_map.end()) continue;
                        for (int v : it->second) {
                            if (v == u) continue;
                            bool neighbor = false;
                            // points in the same cell are always at distance < d
                            if (di == 0 && dj == 0 && dk == 0) {
                                neighbor = true;
                            } else {
                                long long dx = x[u] - x[v];
                                long long dy = y[u] - y[v];
                                long long dz = z[u] - z[v];
                                if (dx * dx + dy * dy + dz * dz < d2) {
                                    neighbor = true;
                                }
                            }
                            if (neighbor) {
                                if (color[v] == -1) {
                                    color[v] = color[u] ^ 1;
                                    q.push(v);
                                } else if (color[v] == color[u]) {
                                    fail = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (fail) {
            possible = false;
            break;
        }

        // build polynomial for this component: prod0 * x^{cnt0} + prod1 * x^{cnt1}
        Poly p;
        int sz = max(cnt0, cnt1);
        p.coef.assign(sz + 1, 0);
        p.coef[cnt0] = (int)((p.coef[cnt0] + prod0) % MOD);
        p.coef[cnt1] = (int)((p.coef[cnt1] + prod1) % MOD);
        // remove trailing zeros
        while (!p.coef.empty() && p.coef.back() == 0) p.coef.pop_back();
        if (p.coef.empty()) p.coef.push_back(0); // should not happen
        polys.push_back(p);
    }

    if (!possible) {
        for (int i = 1; i <= n - 1; i++) cout << "0\n";
        return 0;
    }

    // multiply all component polynomials
    priority_queue<Poly, vector<Poly>, PolyCmp> pq;
    for (auto& p : polys) pq.push(p);
    while (pq.size() > 1) {
        Poly a = pq.top(); pq.pop();
        Poly b = pq.top(); pq.pop();
        Poly c;
        c.coef = multiply(a.coef, b.coef);
        pq.push(c);
    }
    vector<int> ans = pq.empty() ? vector<int>(1, 1) : pq.top().coef;
    if ((int)ans.size() < n + 1) ans.resize(n + 1, 0);

    for (int k = 1; k <= n - 1; k++) {
        cout << ans[k] << '\n';
    }

    return 0;
}