#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

// Precompute factorials and inverse factorials for nCk
struct Comb {
    int N;
    vector<long long> fact, invfact;

    long long modpow(long long a, long long e) {
        long long r = 1 % MOD;
        while (e) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

    Comb(int n=0) { init(n); }

    void init(int n) {
        N = n;
        fact.assign(N+1, 1);
        invfact.assign(N+1, 1);
        for (int i = 1; i <= N; ++i) fact[i] = fact[i-1] * i % MOD;
        invfact[N] = modpow(fact[N], MOD-2);
        for (int i = N; i >= 1; --i) invfact[i-1] = invfact[i] * i % MOD;
    }

    long long C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
    }
};

// Count A: number of completions with pos[1] < pos[2] < ... < pos[n]
long long count_A(int n, const vector<int>& p, const vector<int>& posOfVal, Comb& comb) {
    // Collect known values (by value order)
    vector<pair<int,int>> known; // (value v, position pos)
    known.reserve(n);
    for (int v = 1; v <= n; ++v) {
        if (posOfVal[v] != -1) known.emplace_back(v, posOfVal[v]);
    }
    // Check positions strictly increasing by value
    for (int i = 1; i < (int)known.size(); ++i) {
        if (known[i-1].second >= known[i].second) return 0;
    }
    // Add sentinels: (0,0) and (n+1, n+1)
    long long ways = 1;
    int prevV = 0, prevPos = 0;
    int idx = 0, K = (int)known.size();
    while (idx < K) {
        int v = known[idx].first;
        int pos = known[idx].second;
        int a = v - prevV - 1;          // missing values between prevV and v
        int b = pos - prevPos - 1;      // free positions between prevPos and pos
        if (a < 0 || b < 0) return 0;
        if (a > b) return 0;
        ways = ways * comb.C(b, a) % MOD;
        prevV = v; prevPos = pos;
        ++idx;
    }
    // Final gap to (n+1, n+1)
    {
        int a = (n+1) - prevV - 1;   // n - prevV
        int b = (n+1) - prevPos - 1; // n - prevPos
        if (a < 0 || b < 0) return 0;
        if (a > b) return 0;
        ways = ways * comb.C(b, a) % MOD;
    }
    return ways;
}

// Count R_k via constrained prefix-L counts
long long count_Rk(int n, const vector<int>& p, int k, Comb& comb) {
    // reqX[j] = required number of L's in prefix j (after position j)
    // -1 means unconstrained
    vector<int> reqX(n+1, -1);
    // letterAt[j]: 'L' if p[j] known and <=k, 'R' if known and >k, 'N' if unknown, 'S' for synthetic (we'll not set for 0/n)
    vector<char> letterAt(n+1, 'N');

    reqX[0] = 0;
    reqX[n] = k;

    // Build constraints from known entries
    for (int j = 1; j <= n; ++j) {
        int v = p[j];
        if (v == -1) continue;
        if (v <= k) {
            // Must be L at position j, and x(j) = v
            int req = v;
            if (req < 0 || req > min(j, k)) return 0;
            if (reqX[j] == -1) reqX[j] = req;
            else if (reqX[j] != req) return 0;
            letterAt[j] = 'L';
        } else {
            // Must be R at position j, and #R in prefix j = v - k
            // ==> x(j) = j - (v - k)
            int req = j - (v - k);
            if (req < 0 || req > min(j, k)) return 0;
            if (reqX[j] == -1) reqX[j] = req;
            else if (reqX[j] != req) return 0;
            letterAt[j] = 'R';
        }
    }

    // Collect constrained indices
    vector<int> idxs;
    idxs.reserve(n+1);
    for (int j = 0; j <= n; ++j) if (reqX[j] != -1) idxs.push_back(j);
    sort(idxs.begin(), idxs.end());
    idxs.erase(unique(idxs.begin(), idxs.end()), idxs.end());

    // Verify if j = n had a known constraint, it matches x(n)=k (already ensured by merging above)

    long long ways = 1;
    for (int t = 1; t < (int)idxs.size(); ++t) {
        int prev = idxs[t-1];
        int curr = idxs[t];
        int A = reqX[prev];
        int B = reqX[curr];
        int m_all = curr - prev; // number of positions in (prev, curr]
        if (m_all < 0) return 0;
        int d = B - A; // number of L's in (prev, curr]
        if (d < 0 || d > m_all) return 0;

        bool currKnown = (curr >= 1 && curr <= n && letterAt[curr] != 'N');
        int freeSlots = m_all - (currKnown ? 1 : 0);

        int needFromFree = d - ((currKnown && letterAt[curr] == 'L') ? 1 : 0);
        if (needFromFree < 0 || needFromFree > freeSlots) return 0;

        ways = ways * comb.C(freeSlots, needFromFree) % MOD;
    }
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;

    // Since sum of n across tests <= 3000, max N <= 3000
    const int MAXN = 3000;
    Comb comb(MAXN + 5);

    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n+1);
        for (int i = 1; i <= n; ++i) cin >> p[i];

        vector<int> posOfVal(n+1, -1);
        for (int i = 1; i <= n; ++i) {
            if (p[i] != -1) posOfVal[p[i]] = i;
        }

        long long A = count_A(n, p, posOfVal, comb);

        long long sumR = 0;
        for (int k = 1; k <= n-1; ++k) {
            long long Rk = count_Rk(n, p, k, comb);
            sumR += Rk;
            if (sumR >= MOD) sumR -= MOD;
        }

        long long ans = (sumR - ((long long)(n - 2) % MOD) * A) % MOD;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    }
    return 0;
}