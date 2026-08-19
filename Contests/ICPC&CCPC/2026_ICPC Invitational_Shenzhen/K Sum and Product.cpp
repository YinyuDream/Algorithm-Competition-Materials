#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using i128 = __int128;

const ull MOD = 998244353;

// ---------- 快速乘法和快速幂 (模任意数) ----------
ull mul_mod(ull a, ull b, ull m) {
    return (ull)((i128)a * b % m);
}

ull pow_mod(ull a, ull e, ull m) {
    ull res = 1;
    a %= m;
    while (e) {
        if (e & 1) res = mul_mod(res, a, m);
        a = mul_mod(a, a, m);
        e >>= 1;
    }
    return res;
}

// ---------- Miller-Rabin 素性测试 ----------
bool is_prime(ull n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    ull d = n - 1, s = 0;
    while (d % 2 == 0) d /= 2, ++s;
    // 64 位整数的确定性测试基
    const vector<ull> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ull a : bases) {
        if (a % n == 0) continue;
        ull x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (ull r = 0; r < s; ++r) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

// ---------- Pollard's Rho 分解 ----------
ull pollard_rho(ull n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    for (ull c = 1; ; ++c) {
        auto f = [&](ull x) { return (mul_mod(x, x, n) + c) % n; };
        ull x = 2, y = 2, d = 1;
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = __gcd(x > y ? x - y : y - x, n);
        }
        if (d != n) return d;
    }
}

void factorize(ull n, map<ull, int>& fac) {
    if (n <= 1) return;
    if (is_prime(n)) {
        ++fac[n];
        return;
    }
    ull d = pollard_rho(n);
    factorize(d, fac);
    factorize(n / d, fac);
}

// ---------- 对每个素数幂计算 B 数组 ----------
vector<ull> calc_B(ull p, int e) {
    ull pe = 1;
    for (int i = 0; i < e; ++i) pe *= p;
    ull phi = pe - pe / p;
    // N(0) = e * φ(p^e) + p^e
    ull N0 = e * phi + pe;

    vector<ull> A(e + 1);
    for (int t = 0; t <= e; ++t) {
        if (2 * t < e)
            A[t] = (2 * t + 1) * phi;
        else
            A[t] = N0;
    }
    vector<ull> B(e + 1);
    B[0] = A[0];
    for (int t = 1; t <= e; ++t)
        B[t] = A[t] - A[t - 1];
    return B;
}

// ---------- 深度优先搜索所有因数并累加答案 ----------
ull ans = 0;
void dfs(int idx, ull r, ull g_val,
         const vector<pair<ull, vector<ull>>>& info, ull m) {
    if (idx == (int)info.size()) {
        ull cnt = m / r + 1;
        i128 add = (i128)(g_val % MOD) * (cnt % MOD);
        ans = (ans + add) % MOD;
        return;
    }
    ull p = info[idx].first;
    const vector<ull>& B = info[idx].second;
    ull p_pow = 1;
    for (int t = 0; t < (int)B.size(); ++t) {
        if (B[t] != 0) {
            dfs(idx + 1, r * p_pow, g_val * B[t], info, m);
        }
        p_pow *= p;
    }
}

// ---------- 主函数 ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ull n, m;
        cin >> n >> m;

        if (n == 1) {
            cout << (m + 1) % MOD << '\n';
            continue;
        }

        // 1) 质因数分解
        map<ull, int> fac;
        ull temp = n;
        // 先用小质数试除，加速
        for (ull p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            while (temp % p == 0) {
                ++fac[p];
                temp /= p;
            }
        }
        ull p = 41;
        while (p * p <= temp && p <= 1000000) {
            while (temp % p == 0) {
                ++fac[p];
                temp /= p;
            }
            p += 2;
        }
        if (temp > 1) {
            if (is_prime(temp)) {
                ++fac[temp];
            } else {
                map<ull, int> large;
                factorize(temp, large);
                for (auto& kv : large) fac[kv.first] += kv.second;
            }
        }

        // 2) 对每个素数幂计算 B_t
        vector<pair<ull, vector<ull>>> info;
        for (auto& kv : fac) {
            ull p = kv.first;
            int e = kv.second;
            info.emplace_back(p, calc_B(p, e));
        }

        // 3) 搜索所有因数并贡献答案
        ans = 0;
        dfs(0, 1, 1, info, m);

        cout << ans << '\n';
    }
    return 0;
}