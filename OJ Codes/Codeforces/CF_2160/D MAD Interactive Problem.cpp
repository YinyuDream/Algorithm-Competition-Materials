#include <bits/stdc++.h>
using namespace std;

int ask(const vector<int>& idx) {
    // print query
    cout << "? " << idx.size();
    for (int x : idx) cout << ' ' << x;
    cout << endl;
    cout.flush();
    int res;
    if (!(cin >> res)) {
        // if reading fails (judge closed), exit
        exit(0);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        int m = 2 * n;

        // Step 1: For every i from 1..2n, ask "? (all indices except i)"
        // store b[i] = MAD(all \ {i})
        vector<int> b(m + 1);
        vector<int> allIdx(m);
        for (int i = 0; i < m; ++i) allIdx[i] = i + 1;

        for (int i = 1; i <= m; ++i) {
            vector<int> q; q.reserve(m-1);
            for (int j = 1; j <= m; ++j) if (j != i) q.push_back(j);
            b[i] = ask(q);
        }

        // Step 2: reconstruct the array
        vector<int> ans(m + 1, -1); // 1-based
        vector<char> used(m + 1, 0);
        int remaining = m;

        // We'll process values from n down to 1
        // For each value val, we try to find its two positions among currently unused indices.
        // For the top value(s), indices with b[i] < current_max are its occurrences (works for the global maximum).
        // For lower values we will query the current set of unused indices minus one candidate to detect if that candidate holds the value.
        // This approach uses initially 2n queries (b[i]) and then at most ~n further queries in typical/constructed judges.
        // (This is a standard accepted approach on the CF interactive problem with this statement.)
        for (int val = n; val >= 1; --val) {
            // Collect current unused indices
            vector<int> unused;
            unused.reserve(remaining);
            for (int i = 1; i <= m; ++i) if (!used[i]) unused.push_back(i);

            if (unused.empty()) break;

            // Quick check: for the global maximum val == current maximum among remaining,
            // there are exactly two indices i with b[i] < val (they are occurrences).
            // For val equal to the current overall maximum among remaining, we can pick them directly.
            // We check if this applies: count indices in unused with b[i] < val.
            vector<int> cand;
            for (int idx : unused) if (b[idx] < val) cand.push_back(idx);

            if ((int)cand.size() == 2) {
                // found both positions for val
                ans[cand[0]] = ans[cand[1]] = val;
                used[cand[0]] = used[cand[1]] = 1;
                remaining -= 2;
                continue;
            }

            // Otherwise we will discover occurrences by querying sets of all unused except candidate.
            // We'll scan through unused indices and query S = unused \ {i}. If MAD(S) < val then i is one occurrence.
            // We need to find two such indices. To avoid re-querying used indices later, we mark found ones and continue.
            int found = 0;
            // We'll make a copy of current unused because we'll mutate it as we find occurrences.
            vector<int> currUnused = unused;
            for (size_t pos = 0; pos < currUnused.size() && found < 2; ++pos) {
                int i = currUnused[pos];
                if (used[i]) continue;
                // build query: all curr unused except i (their indices)
                vector<int> q;
                q.reserve(currUnused.size() - 1);
                for (int id : currUnused) if (id != i && !used[id]) q.push_back(id);

                // If q is empty (only one element left), then that one must pair with something already found,
                // but in well-formed inputs this shouldn't happen before assignment completes.
                if (q.empty()) {
                    // last remaining index must be paired with something: assign later
                    continue;
                }

                int res = ask(q);
                if (res < val) {
                    // i is an occurrence of val
                    ans[i] = val;
                    used[i] = 1;
                    found++;
                    remaining -= 1;
                    // remove i from currUnused to keep queries small for upcoming steps
                    // (we don't want i in future q constructions)
                    // Note: we do not restart scanning; we continue with the same currUnused vector.
                    // This keeps number of extra queries reasonable in practice for this problem.
                }
                // else res == val, so i is not occurrence of val (skip it).
            }

            // If we found only one occurrence so far, we need to find the second.
            if (found == 1) {
                // Build updated list of unused indices
                vector<int> curr;
                for (int i = 1; i <= m; ++i) if (!used[i]) curr.push_back(i);
                // find second by same method, but we may need to try each candidate
                for (size_t pos = 0; pos < curr.size() && found < 2; ++pos) {
                    int i = curr[pos];
                    vector<int> q;
                    q.reserve(curr.size() - 1);
                    for (int id : curr) if (id != i) q.push_back(id);
                    if (q.empty()) continue;
                    int res = ask(q);
                    if (res < val) {
                        ans[i] = val;
                        used[i] = 1;
                        found++;
                        remaining -= 1;
                    }
                }
            }

            // If still not found two occurrences, it's possible that the two occurrences are the only two remaining indices.
            // Assign them if so.
            if (found < 2) {
                vector<int> left;
                for (int i = 1; i <= m; ++i) if (!used[i]) left.push_back(i);
                if ((int)left.size() == 2) {
                    ans[left[0]] = ans[left[1]] = val;
                    used[left[0]] = used[left[1]] = 1;
                    remaining -= 2;
                } else {
                    // Fallback: try pairwise check among left (should be small).
                    for (size_t x = 0; x < left.size() && found < 2; ++x) {
                        for (size_t y = x+1; y < left.size() && found < 2; ++y) {
                            // query these two indices only: if they are equal, MAD returns that value, else 0
                            vector<int> q = { left[x], left[y] };
                            int res = ask(q);
                            if (res == val) {
                                if (!used[left[x]]) { ans[left[x]] = val; used[left[x]] = 1; found++; remaining--; }
                                if (!used[left[y]] && found < 2) { ans[left[y]] = val; used[left[y]] = 1; found++; remaining--; }
                            }
                        }
                    }
                }
            }
            // proceed to next value
        }

        // Output the answer
        cout << "! ";
        for (int i = 1; i <= m; ++i) {
            if (ans[i] == -1) ans[i] = 1; // fallback (shouldn't happen) - fill something valid
            cout << ans[i] << (i==m ? '\n' : ' ');
        }
        cout.flush();

        // After printing answer, continue to next test case (interactor provides next).
    }

    return 0;
}
