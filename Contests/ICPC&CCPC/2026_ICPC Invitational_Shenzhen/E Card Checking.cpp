#include <bits/stdc++.h>
using namespace std;

// A > B 的最大匹配数
int maxMatch(const vector<int>& A, const vector<int>& B) {
    int i = 0, n = A.size(), match = 0;
    for (int b : B) {
        while (i < n && A[i] <= b) ++i;
        if (i < n) {
            ++match;
            ++i;
        } else break;
    }
    return match;
}

struct Hand {
    vector<int> small; // < p_c
    vector<int> big;   // >= p_c
    vector<int> pair;  // 对子
};

bool canAWin(const Hand& A, const Hand& B) {
    int k = A.small.size();
    if (k <= 1) return true;            // 没有危险牌或只有一张，直接跑
    if ((int)B.big.size() < k - 1) return false; // 燃料不足

    // 最大匹配数
    int M_big  = maxMatch(A.big, B.big);
    int M_pair = maxMatch(A.pair, B.pair);

    int u_max = min({k - 1, M_big, (int)A.big.size()});
    int v_max = min({k - 1, M_pair, (int)A.pair.size(), (int)B.pair.size()});

    return (k - 1 - u_max) <= v_max;
}

bool canBWin(const Hand& A, const Hand& B) {
    if (B.small.size() > 1) return false;               // B 不能出多张危险单张
    if (!A.small.empty() && !B.big.empty()) return true; // 强制转移

    // 自愿转移：大单张
    if (!A.big.empty() && !B.big.empty() && B.big.back() > A.big[0])
        return true;
    // 自愿转移：对子
    if (!A.pair.empty() && !B.pair.empty() && B.pair.back() > A.pair[0])
        return true;

    return false;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string sa, sb;
        cin >> sa >> sb;
        int pc;
        cin >> pc;

        Hand A, B;
        for (int i = 1; i <= n; ++i) {
            if (sa[i - 1] == '1') {
                if (i < pc) A.small.push_back(i);
                else        A.big.push_back(i);
            } else if (sa[i - 1] == '2') {
                A.pair.push_back(i);
            }

            if (sb[i - 1] == '1') {
                if (i < pc) B.small.push_back(i);
                else        B.big.push_back(i);
            } else if (sb[i - 1] == '2') {
                B.pair.push_back(i);
            }
        }

        // 排序以便匹配
        sort(A.big.begin(), A.big.end());
        sort(A.pair.begin(), A.pair.end());
        sort(B.big.begin(), B.big.end());
        sort(B.pair.begin(), B.pair.end());

        if (canAWin(A, B) || canBWin(A, B)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    solve();
    return 0;
}