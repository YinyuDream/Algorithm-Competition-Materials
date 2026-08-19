#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<int> b(m);
        for (int &x : b) cin >> x;
        
        vector<int> min_and(m + 1, (1 << 30) - 1);
        for (int mask = 1; mask < (1 << m); ++mask) {
            int t_bits = __builtin_popcount(mask);
            if (t_bits > m) continue;
            int and_val = (1 << 30) - 1;
            for (int j = 0; j < m; ++j) {
                if (mask & (1 << j)) {
                    and_val &= b[j];
                }
            }
            if (and_val < min_and[t_bits]) {
                min_and[t_bits] = and_val;
            }
        }
        
        vector<int> deltas;
        long long original_sum = 0;
        for (int x : a) {
            original_sum += x;
            int prev_gain = 0;
            for (int t = 1; t <= m; ++t) {
                int s = min_and[t];
                int new_val = x & s;
                int curr_gain = x - new_val;
                int delta = curr_gain - prev_gain;
                if (delta > 0) {
                    deltas.push_back(delta);
                }
                prev_gain = curr_gain;
            }
        }
        
        sort(deltas.rbegin(), deltas.rend());
        int take = min(k, (int)deltas.size());
        long long total_gain = 0;
        for (int i = 0; i < take; ++i) {
            total_gain += deltas[i];
        }
        cout << original_sum - total_gain << '\n';
    }
    return 0;
}