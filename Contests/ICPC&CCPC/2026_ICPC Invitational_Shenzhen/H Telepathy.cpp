#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string role;
    cin >> role;
    int T;
    cin >> T;
    
    if (role == "Alice") {
        while (T--) {
            int n, k;
            cin >> n >> k;
            // present[i] == 1 if i is in Christina's set S
            vector<char> present(n + 1, 0);
            vector<int> S(k);
            ll sum_S = 0;
            for (int i = 0; i < k; ++i) {
                cin >> S[i];
                present[S[i]] = 1;
                sum_S += S[i];
            }
            int m = k + 1;
            int less = 0;          // number of elements in S strictly smaller than current x
            int chosen = -1;
            for (int x = 1; x <= n; ++x) {
                if (present[x]) {
                    ++less;
                } else {
                    // We need sum_S + x ≡ (rank of x in T) - 1 (mod m)
                    // (rank of x in T) - 1 is exactly 'less' here
                    if ((sum_S + x) % m == less) {
                        chosen = x;
                        break;
                    }
                }
            }
            // Output the original set S together with the chosen element
            for (int i = 0; i < k; ++i) {
                cout << S[i] << ' ';
            }
            cout << chosen << '\n';
        }
    } else { // Bob
        while (T--) {
            int n, k;
            cin >> n >> k;
            int m = k + 1;
            vector<int> T_set(m);
            for (int i = 0; i < m; ++i) {
                cin >> T_set[i];
            }
            sort(T_set.begin(), T_set.end());
            ll sum_T = 0;
            for (int v : T_set) sum_T += v;
            // The added element is exactly the (sum_T mod m) + 1 -th element in sorted order
            int idx = (sum_T % m) + 1;   // 1‑based index
            cout << T_set[idx - 1] << '\n';
        }
    }
    return 0;
}