#include <bits/stdc++.h>
using namespace std;

static const int T_BASE = 200; // max increments per index to consider
using int64 = long long;
const int64 INF64 = (int64)4e18;

struct BestTwo {
    int64 c1; int i1;
    int64 c2; int i2;
    BestTwo(): c1(INF64), i1(-1), c2(INF64), i2(-1) {}
    inline void add(int idx, int64 cost) {
        if (idx == i1) {
            if (cost < c1) c1 = cost;
            return;
        }
        if (cost < c1) {
            c2 = c1; i2 = i1;
            c1 = cost; i1 = idx;
        } else if (idx == i2) {
            if (cost < c2) c2 = cost;
        } else if (cost < c2) {
            c2 = cost; i2 = idx;
        }
    }
    inline bool has_two() const { return i1 != -1 && i2 != -1; }
    inline int64 sum_two() const { return c1 + c2; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    vector<int> ns(T);
    vector<vector<int>> As(T), Bs(T);
    int maxA = 0;
    long long totalN = 0;
    for (int tc = 0; tc < T; ++tc) {
        int n; cin >> n;
        ns[tc] = n;
        totalN += n;
        As[tc].resize(n);
        Bs[tc].resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> As[tc][i];
            maxA = max(maxA, As[tc][i]);
        }
        for (int i = 0; i < n; ++i) cin >> Bs[tc][i];
    }
    int MAXV = maxA + T_BASE;
    // SPF sieve up to MAXV
    vector<int> spf(MAXV + 1);
    for (int i = 0; i <= MAXV; ++i) spf[i] = i;
    for (int i = 2; i * 1LL * i <= MAXV; ++i) {
        if (spf[i] == i) {
            for (long long j = 1LL * i * i; j <= MAXV; j += i) {
                if (spf[(int)j] == j) spf[(int)j] = i;
            }
        }
    }

    // Per test case processing
    vector<BestTwo> best; best.reserve(MAXV + 1);
    vector<int> touched; touched.reserve(100000);
    vector<int> lastSeen(MAXV + 1, -1);

    for (int tc = 0; tc < T; ++tc) {
        int n = ns[tc];
        auto &a = As[tc];
        auto &b = Bs[tc];

        // Prepare best arrays
        best.assign(MAXV + 1, BestTwo());
        touched.clear();

        // Initial upper bound using p=2
        int64 ans = INF64;
        int64 m1 = INF64, m2 = INF64;
        for (int i = 0; i < n; ++i) {
            int64 c = (a[i] % 2 == 0) ? 0 : (int64)b[i];
            if (c < m1) { m2 = m1; m1 = c; }
            else if (c < m2) { m2 = c; }
        }
        if (m2 < INF64) ans = min(ans, m1 + m2);
        if (ans == 0) { // Already two even numbers
            cout << 0 << "\n";
            continue;
        }

        // Process indices
        for (int i = 0; i < n; ++i) {
            // Per-index seen marker using lastSeen array to avoid duplicate primes from multiple t
            // We use the index 'i' as the mark id.
            int64 bi = b[i];
            // prune by current best answer
            int t_limit = (bi > 0 ? (int)min<int64>(T_BASE, ans / bi) : 0);
            // always include t=0
            for (int t = 0; t <= t_limit; ++t) {
                int x = a[i] + t;
                // factor x, add unique primes
                int y = x;
                while (y > 1) {
                    int p = spf[y];
                    if (lastSeen[p] != i) {
                        lastSeen[p] = i;
                        if (best[p].c1 == INF64 && best[p].c2 == INF64) {
                            touched.push_back(p);
                        }
                        best[p].add(i, (int64)t * bi);
                        if (best[p].has_two()) {
                            ans = min(ans, best[p].sum_two());
                        }
                    }
                    while (y % p == 0) y /= p;
                }
            }
        }

        cout << ans << "\n";

        // cleanup: reset lastSeen for touched primes (by indices, not necessary; lastSeen keyed by prime and i)
        // No need to reset best due to assign at next iteration.
        // lastSeen array is per (prime, index) marking, we don't need to clear; index changes each loop naturally.
        // Nothing else to do.
    }
    return 0;
}