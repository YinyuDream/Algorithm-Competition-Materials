#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> G(n);
        for (int i = 0; i < n; ++i) cin >> G[i];

        // Answer initialized to 0 meaning "no rectangle covers this cell yet".
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // We'll choose to iterate pairs on the smaller dimension (rows or columns).
        if (n <= m) {
            // Precompute for each row the indices of columns with 1.
            vector<vector<int>> ones_row(n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) if (G[i][j] == '1') ones_row[i].push_back(j);
            }

            // For every pair of rows u < d
            for (int u = 0; u < n; ++u) {
                for (int d = u + 1; d < n; ++d) {
                    // compute intersection columns where both rows have 1
                    // do a merge of two sorted lists ones_row[u] and ones_row[d]
                    const vi &A = ones_row[u];
                    const vi &B = ones_row[d];
                    vi inter;
                    inter.reserve(min(A.size(), B.size()));
                    size_t ia = 0, ib = 0;
                    while (ia < A.size() && ib < B.size()) {
                        if (A[ia] == B[ib]) { inter.push_back(A[ia]); ++ia; ++ib; }
                        else if (A[ia] < B[ib]) ++ia;
                        else ++ib;
                    }
                    if (inter.size() < 2) continue; // need at least two distinct columns

                    int height = d - u + 1;
                    // for each consecutive pair in inter, update ans for rectangle u..d by cols inter[p]..inter[p+1]
                    for (size_t p = 0; p + 1 < inter.size(); ++p) {
                        int L = inter[p];
                        int R = inter[p+1];
                        int width = R - L + 1;
                        int area = height * width;
                        // update ans[i][j] for i in [u..d], j in [L..R]
                        for (int i = u; i <= d; ++i) {
                            // update contiguous columns L..R on row i
                            for (int j = L; j <= R; ++j) {
                                if (ans[i][j] == 0) ans[i][j] = area;
                                else ans[i][j] = min(ans[i][j], area);
                            }
                        }
                    }
                }
            }
        } else {
            // m < n : symmetrical handling by transposing the problem roles (pair columns).
            // Precompute for each column the list of rows with 1.
            vector<vector<int>> ones_col(m);
            for (int j = 0; j < m; ++j) {
                for (int i = 0; i < n; ++i) if (G[i][j] == '1') ones_col[j].push_back(i);
            }

            // For every pair of columns l < r
            for (int l = 0; l < m; ++l) {
                for (int r = l + 1; r < m; ++r) {
                    // intersection rows where both columns have 1
                    const vi &A = ones_col[l];
                    const vi &B = ones_col[r];
                    vi inter;
                    inter.reserve(min(A.size(), B.size()));
                    size_t ia = 0, ib = 0;
                    while (ia < A.size() && ib < B.size()) {
                        if (A[ia] == B[ib]) { inter.push_back(A[ia]); ++ia; ++ib; }
                        else if (A[ia] < B[ib]) ++ia;
                        else ++ib;
                    }
                    if (inter.size() < 2) continue;

                    int width = r - l + 1;
                    // for each consecutive pair of rows in inter, update ans for rows inter[p]..inter[p+1], cols l..r
                    for (size_t p = 0; p + 1 < inter.size(); ++p) {
                        int U = inter[p];
                        int D = inter[p+1];
                        int height = D - U + 1;
                        int area = height * width;
                        for (int i = U; i <= D; ++i) {
                            for (int j = l; j <= r; ++j) {
                                if (ans[i][j] == 0) ans[i][j] = area;
                                else ans[i][j] = min(ans[i][j], area);
                            }
                        }
                    }
                }
            }
        }

        // Print answer grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j] << (j + 1 == m ? '\n' : ' ');
            }
        }
    }
    return 0;
}
