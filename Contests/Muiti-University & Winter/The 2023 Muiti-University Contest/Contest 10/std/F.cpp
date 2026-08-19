#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 13;
const int T = 305;
const int MOD = 1e9 + 7;

int n, t, k, m, cnt[T];
LL f[T][N + 5][1 << N];

int main() {
    cin >> n >> t >> k >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }

    int U = (1 << k) - 1;
    f[0][0][0] = 1;
    for (int i = 0; i <= t; i++) {
        for (int j = 0; j <= n; j++) {
            for (int mask = 0; mask < (1 << k); mask++) {
                int m1 = (mask << 1) & U;
                (f[i + 1][j + cnt[i + 1]][m1] += f[i][j][mask]) %= MOD;
                if (j) {
                    int m2 = (mask << 1 | 1) & U;
                    if (__builtin_popcount(m2) > m) continue;
                    (f[i + 1][j - 1 + cnt[i + 1]][m2] += f[i][j][mask] * j % MOD) %= MOD; 
                }
            }
        }
    }

    LL ans = 0;
    for (int mask = 0; mask < (1 << k); mask++)
        (ans += f[t + 1][0][mask]) %= MOD;
    
    cout << ans << endl;
    return 0;
}