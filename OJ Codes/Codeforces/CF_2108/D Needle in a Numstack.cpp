#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

// Cache for query results to avoid redundant queries
map<int, int> cache;
int query_count = 0;
const int MAX_QUERIES = 250; // Maximum allowed queries per test case

// Function to perform a query, using cache if possible
int query(int idx) {
    // Check if we are about to exceed the query limit
    if (query_count >= MAX_QUERIES) {
        // This case should ideally not be reached if logic is correct,
        // but as a safeguard, return a dummy value or handle error.
        // The judge will likely give Wrong Answer or Time Limit Exceeded anyway.
        return -1; // Or some other indicator
    }

    // Check cache first
    if (cache.count(idx)) {
        return cache[idx];
    }

    // Perform the query
    query_count++;
    cout << "? " << idx << endl;
    fflush(stdout); // IMPORTANT: Flush output buffer after query

    int value;
    cin >> value;
    // Check for potential input errors (e.g., judge sending -1)
    if (value == -1) {
        // Handle error case if necessary, maybe exit
        // exit(1);
    }

    // Store result in cache
    cache[idx] = value;
    return value;
}

void solve() {
    int n;
    long long k; // k can be up to 50, fits in int, but use long long for consistency with ranges
    cin >> n >> k;

    // Clear cache and reset query count for the new test case
    cache.clear();
    query_count = 0;

    // Initial possible range for the length of array A (|A| = a)
    // We know k <= a <= n - k
    long long current_l = k;
    long long current_r = n - k;
    bool collision_found = false; // Flag to track if any collision C[i] == C[i+k] was found

    // Setup random number generation
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    // Generate random index 'i' such that both i and i+k are valid indices (1 <= i <= n-k)
    uniform_int_distribution<int> distrib(1, n - (int)k);

    // Perform a fixed number of random checks (well within the query limit)
    // Each check requires 2 queries. 120 checks use <= 240 queries.
    int num_checks = 120;

    for (int c = 0; c < num_checks; ++c) {
        // Ensure we have budget for at least 2 more queries
        if (query_count >= MAX_QUERIES - 1) {
            break;
        }

        int i = distrib(rng);

        // Query C[i] and C[i+k]
        int val1 = query(i);
        // Check query count again before the second query in this pair
        if (query_count >= MAX_QUERIES) break;
        int val2 = query(i + (int)k);
         // Check query count after the second query
        if (query_count >= MAX_QUERIES) break;


        // If a collision is found
        if (val1 != -1 && val1 == val2) { // Check val1 != -1 in case query failed
            collision_found = true;
            // A collision C[i] == C[i+k] implies the boundary 'a' must be in [i+1, i+k-1]
            // Update the possible range [current_l, current_r] by taking the intersection
            current_l = max(current_l, (long long)i + 1);
            current_r = min(current_r, (long long)i + k - 1);

            // Optional optimization: if range becomes unique, we might stop early
            // if (current_l == current_r) break;
            // Optional check: if range becomes invalid (shouldn't happen with valid input)
            // if (current_l > current_r) break;
        }
    }

    // Determine the final answer based on the results
    if (!collision_found) {
        // If no collisions were found after random checks, it's highly likely ambiguous
        cout << "! -1" << endl;
    } else if (current_l > current_r) {
         // If the intersection became empty (should not happen if input guarantees a solution)
         cout << "! -1" << endl;
    }
    else if (current_l == current_r) {
        // If the range converged to a single value
        cout << "! " << current_l << " " << n - current_l << endl;
    } else { // current_l < current_r
        // If collisions were found but the range didn't converge to a single value
        cout << "! -1" << endl;
    }
    fflush(stdout); // IMPORTANT: Flush output buffer for the final answer
}

int main() {
    // Faster I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}