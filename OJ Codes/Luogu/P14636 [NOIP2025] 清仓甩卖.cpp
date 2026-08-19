#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate (base^exp) % mod
long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c_id, t_cases;
    if (!(cin >> c_id >> t_cases)) return 0;

    while (t_cases--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        // Sort a in descending order
        sort(a.begin(), a.end(), greater<int>());

        // Precompute DP table
        // dp[i][j] stores the number of ways to assign weights to the first i items
        // such that their total cost is exactly j.
        // Since i only depends on i-1, we can use a full table or optimize.
        // Given constraints N=5000, O(N^2) space (~100MB) is acceptable.
        
        // Ensure m limit handles the max possible cost needed (at most m is sufficient for query, 
        // but we might need up to m+2 logic check? No, max budget we care about is m).
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                long long val = 0;
                // Option 1: w_i = 1
                if (j >= 1) val += dp[i-1][j-1];
                // Option 2: w_i = 2
                if (j >= 2) val += dp[i-1][j-2];
                dp[i][j] = val % 998244353;
            }
        }
        
        // Precompute Binomial Coefficients
        vector<vector<int>> C(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % 998244353;
            }
        }

        long long bad_count = 0;
        
        // Iterate over k, which represents the index (1-based) of the candidate "unchosen weight-2 item".
        // In the sorted array, this is a[k-1].
        for (int k = 1; k <= n; k++) {
            // Case 1: Greedy stops at budget m-1.
            // Failure condition: min(Chosen 1s) < a[k-1].
            
            // Subcase 1.1: There exists at least one chosen 1 after k (in k+1...n).
            // Since a is descending, any such item has value < a[k-1], satisfying the failure condition.
            // We sum over the number of such items S2 from 1 to n-k.
            for (int S2 = 1; S2 <= n - k; S2++) {
                int rem = m - 1 - S2; // Remaining budget for prefix 1...k-1
                if (rem >= 0 && rem <= m) {
                    // Ways to set prefix cost * Ways to choose S2 items as 1s in suffix
                    long long ways = (long long)dp[k-1][rem] * C[n-k][S2] % 998244353;
                    bad_count = (bad_count + ways) % 998244353;
                }
            }
            
            // Subcase 1.2: No chosen 1s after k (S2 = 0).
            // The "bad" chosen 1 must be in the prefix 1...k-1.
            // We iterate over y < k, assuming y is the LAST chosen 1.
            // This implies items y+1...k-1 are chosen as 2s.
            // Failure condition: a[y-1] < a[k-1].
            for (int y = 1; y < k; y++) {
                if (a[y-1] < a[k-1]) {
                    // Cost contribution: y is 1, y+1...k-1 are 2s.
                    // Cost = 1 + 2 * (number of items between y and k)
                    int cost_fixed = 1 + 2 * (k - 1 - y);
                    int rem = m - 1 - cost_fixed; // Remaining budget for 1...y-1
                    if (rem >= 0 && rem <= m) {
                        bad_count = (bad_count + dp[y-1][rem]) % 998244353;
                    }
                }
            }
            
            // Case 2: Budget fills m.
            // Failure condition: a[k-1] > sum of two smallest chosen 1s.
            // The smallest chosen 1s will be the ones with largest indices.
            // We assume S2 (ones in suffix) determine the candidates.
            // Actually, we iterate over pairs x, y > k which are chosen 1s.
            // Since a is descending, a[k] is > a[x], a[y], so a[k] > a[x]+a[y] is possible.
            // If x, y are in suffix, they are definitely the smallest 1s if no 1s exist further down.
            // We simply count pairs in suffix because any pair satisfying sum < a[k] causes failure.
            // The cost structure for Case 2 is fixed relative to k (assuming all prefix chosen, suffix 2s except pair).
            // Actually, simplified logic:
            // We fix the prefix configuration cost to leave space exactly for the suffix 2s (minus the pair converted to 1s? No).
            // Wait, the logic used in thought process:
            // Suffix cost is fixed as "All 2s".
            // Prefix 1...k-1 must be chosen.
            // We count pairs x, y in suffix such that a[x]+a[y] < a[k].
            
            int rem_case2 = m - 2 * (n - k);
            if (rem_case2 >= 0 && rem_case2 <= m) {
                long long factor = dp[k-1][rem_case2];
                if (factor > 0) {
                    // Count pairs (i, j) in a[k...n-1] such that a[i] + a[j] < a[k-1]
                    // To do this in O(N), we use two pointers.
                    // Subarray of interest
                    vector<int> sub; 
                    for(int i = k; i < n; i++) sub.push_back(a[i]);
                    // sub is descending. Two pointers for "sum < limit".
                    // L points to start (large), R points to end (small).
                    long long cnt = 0;
                    int left = 0, right = sub.size() - 1;
                    int limit = a[k-1];
                    while (left < right) {
                        if (sub[left] + sub[right] < limit) {
                            // sub[right] is small enough to pair with sub[left].
                            // It can also pair with any element between left and right.
                            // Actually, logic for descending:
                            // If Large + Small < Limit, then Small + (Anything smaller than Large) < Limit.
                            // Elements to the right of Left are smaller.
                            // So (left, right), (left+1, right)... are valid.
                            // Count is (right - left).
                            // Then we move right pointer? No.
                            // Standard logic on Ascending:
                            // Small + Large < Limit -> Small pairs with all up to Large.
                            // Here: Large + Small < Limit -> Small pairs with all Larger ones up to Large.
                            // Count += (right - left).
                            // Move Small pointer (right) to next small (leftwards? No, sub is desc).
                            // Move right index down (larger value)?
                            // Let's stick to reversing it to Ascending to be safe.
                            cnt += (right - left);
                            right--; // Move to larger value (since sub is descending, right-1 is larger)
                        } else {
                            // Sum too large. Decrease Large value.
                            left++; // Move to smaller value
                        }
                    }
                    bad_count = (bad_count + factor * (cnt % 998244353)) % 998244353;
                }
            }
        }
        
        long long total = power(2, n);
        long long ans = (total - bad_count + 998244353) % 998244353;
        cout << ans << "\n";
    }
    return 0;
}