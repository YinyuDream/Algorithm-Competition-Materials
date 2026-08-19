/*
 * O(alphabet * n^2 + n^3), pass all tests in 1s
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int alpha = 10;

int n, nxt[N][alpha], pre[N][alpha], next_fix[N], last_fix[N];
int sum[N], max_chr[N][N];
bool a[N], f[N][N];
string s;

int get_fix_num(int l, int r) {
    return l == 0 ? sum[r] : sum[r] - sum[l - 1];
}
bool get_f(int l, int r) {
    return r >= l ? f[l][r] : true;
}

struct TwiceTable {
    vector<pair<int, int>> vec;
    bool vis[N][N];
    void insert(const pair<int, int>& p) {
        if (!vis[p.first][p.second]) {
            vis[p.first][p.second] = true;
            vec.push_back(p);
        }
    }
    void clear() {
        for (const auto& [l, r] : vec)
            vis[l][r] = false;
        vec.clear();
    }
} twices;

struct Transition {
    int chr;
    vector<pair<int, int>> transitions;
} transtable[N][N];

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // initialization
    for (int i = 0; i < n; i++) {
        max_chr[i][i] = s[i] - 'a';
        for (int j = i + 1; j < n; j++) {
            max_chr[i][j] = max(max_chr[i][j - 1], s[j] - 'a');
        }
    }
    sum[0] = a[0];
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
    fill(nxt[n], nxt[n] + alpha, n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < alpha; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }
    fill(pre[0], pre[0] + alpha, -1);
    pre[0][s[0] - 'a'] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < alpha; j++)
            pre[i][j] = pre[i - 1][j];
        pre[i][s[i] - 'a'] = i;
    }
    next_fix[n] = n;
    for (int i = n - 1; i >= 0; i--) next_fix[i] = (a[i] ? i : next_fix[i + 1]);
    last_fix[0] = (a[0] ? 0 : -1);
    for (int i = 1; i < n; i++) last_fix[i] = (a[i] ? i : last_fix[i - 1]);

    // DP, f[i][j]: whether substring s[i..j] can yield a palindrome subsequence
    for (int i = n - 1; i >= 0; i--) {
        f[i][i] = true;
        for (int j = i + 1; j < n; j++) {
            if (get_fix_num(i, j) <= 1) {
                f[i][j] = true;
                continue;
            }
            f[i][j] = false;
            if (a[j]) {
                int t = nxt[i][s[j] - 'a'];
                if (t <= next_fix[i] && t <= j) f[i][j] |= get_f(t + 1, j - 1);
            } else {
                f[i][j] |= f[i][j - 1];
            }
            if (a[i]) {
                int t = pre[j][s[i] - 'a'];
                if (t >= last_fix[j] && t >= i) f[i][j] |= get_f(i + 1, t - 1);
            } else {
                f[i][j] |= f[i + 1][j];
            }
            int t = next_fix[i];
            if (s[t] == s[j]) f[i][j] |= get_f(t + 1, j - 1);
            t = last_fix[j];
            if (s[i] == s[t]) f[i][j] |= get_f(i + 1, t - 1);
        }
    }
    if (!f[0][n - 1]) {
        cout << "-1" << endl;
        return;
    }

    // precalculate transitions
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++) {
            transtable[l][r].chr = -1;
            for (int i = alpha - 1; i >= 0; i--) {
                int p = nxt[l][i];
                int q = pre[r][i];
                int nf = next_fix[l], lf = last_fix[r]; 
                // there is no two chr(i) in s[l..r]
                if (p >= q) continue;
                // some fixed position is skipped
                if (p > nf || q < lf) continue;

                vector<pair<int, int>> vec;
                if (get_f(p + 1, q - 1)) {
                    vec.push_back({p + 1, q - 1});
                }
                if (q > nf && s[nf] - 'a' == i && get_f(nf + 1, q - 1)) {
                    vec.push_back({nf + 1, q - 1});
                }
                if (p < lf && s[lf] - 'a' == i && get_f(p + 1, lf - 1)) {
                    vec.push_back({p + 1, lf - 1});
                }
                if (nf < lf && s[nf] - 'a' == i && s[lf] - 'a' == i && get_f(nf + 1, lf - 1)) {
                    vec.push_back({nf + 1, lf - 1});
                }
                // there is no palindrome subsequence in s[l..r]
                if (vec.empty()) continue;

                transtable[l][r].chr = i;
                transtable[l][r].transitions = vec;
                break;
            }
        }

    // greedy, O(n^3), but has a constant factor 1/32
    vector<pair<int, int>> intervals{{0, n - 1}};
    string ans, cur;
    while (!intervals.empty()) {
        twices.clear();

        int oncechr = -1, twicechr = -1;
        bool none = false;
        for (auto [l, r] : intervals) {
            if (l > r) {
                none = true;
                continue;
            }
            // find twices
            if (transtable[l][r].chr != -1) {
                if (transtable[l][r].chr > twicechr) {
                    twices.clear();
                    twicechr = transtable[l][r].chr;
                }
                if (transtable[l][r].chr >= twicechr) {
                    for (const auto & i : transtable[l][r].transitions)
                        twices.insert(i);
                }
            }

            // find once
            int fixnum = get_fix_num(l, r);
            if (fixnum == 1) {
                assert(next_fix[l] == last_fix[r]);
                int fix_id = next_fix[l];
                oncechr = max(oncechr, s[fix_id] - 'a');
            } else if (fixnum == 0) {
                oncechr = max(oncechr, max_chr[l][r]);
                none = true;
            }
        }
        // brute force to compare three schemes
        string tmprev = cur;
        reverse(tmprev.begin(), tmprev.end());
        bool found = false;

        if (none) ans = max(ans, cur + tmprev), found = true;
        if (oncechr >= 0) {
            ans = max(cur + char('a' + oncechr) + tmprev, ans);
            found = true;
        }
        if (twicechr >= 0) {
            cur += char(twicechr + 'a');
            found = true;
        }
        assert(found);
        intervals = twices.vec;
    }
    cout << ans << endl;
}
int main() {
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}