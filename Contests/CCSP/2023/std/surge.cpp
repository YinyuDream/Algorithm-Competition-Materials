#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;

constexpr int N = 5e5 + 10;
constexpr ll inf = 1e18;

int n, k, d, a[N];
ll ans, l, r, mid;

stack<pair<pli, int>> stk;
bool check(ll expcted) {
#define sum first
#define pos second
    pli bst = {0, 0}, cur = {inf, 0};
    ll sum = 0;
    int cnt = 0;
    while (!stk.empty())
        stk.pop();
    stk.push({pli{inf, 0}, 0});
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (sum - bst.sum > expcted) {
            // modify: i
            sum -= d;
            if (++cnt > k) return false;
            // update current slice
            if (sum < cur.sum)
                cur = pli{sum, i};
            while (sum - bst.sum > expcted) {
                auto top = stk.top();
                stk.pop();
                auto actual = top.second;
                if (actual <= bst.pos)
                    return false;
                // modify: actual
                sum -= d;
                if (++cnt > k) return false;
                // update current slice
                if (cur.pos >= actual)
                    cur.sum -= d;
                // merge previous slice into current slice
                cur = min(cur, top.first);
                // update best node
                bst = min(bst, cur);
            }
        } else {
            // merge [i] into current slice, and swap it out
            stk.push({min(pli{sum - d, i}, cur), i});
            cur = pli{inf, 0};
        }

        if (sum < bst.sum)
            bst = pli{sum, i}, cur = pli{inf, 0};
    }
#undef sum
#undef pos
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> d;
    l = r = -inf, mid = ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mid += a[i], ans += a[i] - d;
        r = max(r, mid);
        l = max(l, ans);
        if (mid < 0) mid = 0;
        if (ans < 0) ans = 0;
    }
    ans = r;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}