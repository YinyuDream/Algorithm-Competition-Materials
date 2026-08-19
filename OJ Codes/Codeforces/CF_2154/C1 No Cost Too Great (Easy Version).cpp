#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

// K: maximum increment tried per element (common contest heuristic)
const int K = 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    vector<tuple<int, vector<int>, vector<ll>>> cases;
    int maxA = 0;
    cases.reserve(T);
    for (int tc = 0; tc < T; ++tc) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) { cin >> a[i]; if (a[i] > maxA) maxA = a[i]; }
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];
        cases.emplace_back(n, move(a), move(b));
    }
    // We will need SPF up to maxA + K
    int LIMIT = maxA + K + 5;
    vector<int> spf(LIMIT+1);
    for (int i = 0; i <= LIMIT; ++i) spf[i] = i;
    spf[0] = spf[1] = 1;
    for (int i = 2; (ll)i * i <= LIMIT; ++i) {
        if (spf[i] == i) {
            for (int j = i*i; j <= LIMIT; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    auto factor_unique = [&](int x){
        vector<int> ps;
        while (x > 1) {
            int p = spf[x];
            ps.push_back(p);
            while (x % p == 0) x /= p;
        }
        return ps;
    };

    // Process each test case independently
    for (auto &tc : cases) {
        int n;
        vector<int> a;
        vector<ll> b;
        tie(n, a, b) = tc;
        unordered_map<int, array<pair<ll,int>,2>> best;
        best.reserve(n * 6);
        // best[p] stores two smallest (cost, index) pairs, sorted by cost (if <2, second has cost INF)
        for (int i = 0; i < n; ++i) {
            for (int d = 0; d <= K; ++d) {
                int val = a[i] + d;
                if (val <= 1) continue;
                auto primes = factor_unique(val);
                ll cost = (ll)d * b[i];
                for (int p : primes) {
                    auto &arr = best[p];
                    // initialize if empty (we use default-inited pairs with cost 0 possibly, so check)
                    // We'll treat unseen by checking if arr[0].second == 0 and arr[0].first==0 with marker, 
                    // but simpler: when created arr will be zero-initialized; to avoid confusion, we set INF defaults once.
                    if (arr[0].first == 0 && arr[0].second == 0 && arr[1].first == 0 && arr[1].second == 0) {
                        arr[0] = {INF, -1};
                        arr[1] = {INF, -1};
                    }
                    // If we already have entry from same index, keep the smaller cost for that index.
                    if (arr[0].second == i) {
                        if (cost < arr[0].first) arr[0].first = cost;
                    } else if (arr[1].second == i) {
                        if (cost < arr[1].first) arr[1].first = cost;
                        if (arr[1].first < arr[0].first) swap(arr[0], arr[1]);
                    } else {
                        // new index, try to insert
                        if (cost < arr[0].first) {
                            arr[1] = arr[0];
                            arr[0] = {cost, i};
                        } else if (cost < arr[1].first) {
                            arr[1] = {cost, i};
                        }
                    }
                }
            }
        }

        ll ans = INF;
        for (auto &kv : best) {
            auto arr = kv.second;
            if (arr[0].second != -1 && arr[1].second != -1 && arr[0].second != arr[1].second) {
                ll cand = arr[0].first + arr[1].first;
                if (cand < ans) ans = cand;
            }
        }
        if (ans == INF) ans = 0; // fallback: if nothing found (shouldn't happen often), 0 or large; keep 0 to be safe
        cout << ans << '\n';
    }
    return 0;
}
