#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; long long k;
        cin >> n >> k;
        vector<i64> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<i64> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
        i64 S = pref[n];

        i64 bestGain = 0; // 可以选择不操作

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) ++j; // 块 [i, j) 值均为 v
            i64 v = a[i];
            int L = i;         // < v 的个数
            int E = j - i;     // = v 的个数
            int G = n - j;     // > v 的个数
            if (E == 0) { i = j; continue; }

            // u = t-1, x = 2u+1；首次必须可行的上界
            int u_max = min({L + E - 1, G + E - 1, (n - 1) / 2});
            if (u_max < 0) { i = j; continue; }

            auto add = [&](long long u, vector<long long>& cand) {
                if (u < 0) return;
                if (u > u_max) return;
                cand.push_back(u);
            };

            vector<long long> cand;
            // 基础断点
            add(0, cand);
            add(u_max, cand);
            add((long long)E - 1, cand);
            add((long long)E, cand);
            add((long long)L, cand);
            add((long long)L - 1, cand);
            add((long long)L + 1, cand);

            if (k > 0) {
                long long u_need = (L + k - 1) / k; // ceil(L/k)
                add(u_need, cand);
                add(u_need - 1, cand);
                add(u_need + 1, cand);
                add(u_need + 2, cand);
            }

            // 邻域扩展，避免夹在断点之间
            vector<long long> base = cand;
            for (long long u : base) {
                add(u - 2, cand);
                add(u - 1, cand);
                add(u + 1, cand);
                add(u + 2, cand);
            }

            sort(cand.begin(), cand.end());
            cand.erase(unique(cand.begin(), cand.end()), cand.end());

            auto eval = [&](int u) -> i64 {
                if (u < 0 || u > u_max) return (i64)-4e18;

                // 首次操作最小牺牲的 >v 个数
                long long b_req;
                if (u <= L) b_req = max<long long>(0, (long long)u + 1 - E);
                else        b_req = max<long long>(0, (long long)2*u + 1 - L - E);
                if (b_req > G) return (i64)-4e18; // 不足以提供 >v 元素

                // k 次操作可提升的 <v 总数
                long long a_tot = min<long long>(L, k * u);

                // 取最小的 a_tot 个 <v：a[0 .. a_tot-1]
                i64 sum_lt = pref[a_tot];

                // 取最小的 b_req 个 >v：a[j .. j+b_req-1]
                i64 sum_gt = 0;
                if (b_req > 0) {
                    if (j + b_req > n) return (i64)-4e18;
                    sum_gt = pref[j + (int)b_req] - pref[j];
                }

                return v * (a_tot + b_req) - sum_lt - sum_gt;
            };

            i64 localBest = 0;
            for (long long u : cand) {
                localBest = max(localBest, eval((int)u));
            }
            bestGain = max(bestGain, localBest);

            i = j;
        }

        cout << (S + bestGain) << "\n";
    }
    return 0;
}