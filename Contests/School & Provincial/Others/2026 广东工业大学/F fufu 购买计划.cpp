#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        ll m;
        scanf("%d%lld", &n, &m);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
 
        // 使 a 单调不降
        for (int i = n - 1; i >= 1; --i) a[i] = min(a[i], a[i + 1]);
 
        // 计算 b[i] = i - a[i] 及其前缀最大值 c[i]
        vector<int> b(n + 1), c(n + 1);
        c[0] = 0;
        for (int i = 1; i <= n; ++i) {
            b[i] = i - a[i];
            c[i] = max(c[i - 1], b[i]);
        }
        int cn = c[n];                     // 最大下界
 
        // 计算 g[j] = min{ i | c[i] >= j }
        vector<int> g(cn + 1);             // 下标从 1 开始
        int ptr = 1;
        for (int j = 1; j <= cn; ++j) {
            while (ptr <= n && c[ptr] < j) ++ptr;
            g[j] = ptr;
        }
 
        // 前缀和
        vector<ll> pref(cn + 1, 0);
        for (int j = 1; j <= cn; ++j) pref[j] = pref[j - 1] + g[j];
 
        ll total = (ll)n * (n + 1) / 2;
        ll s_total = total - m;            // T 的目标和
 
        // 二分查找 k
        int l = cn, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            ll s_min = (ll)mid * (mid + 1) / 2;
            ll s_max;
            if (mid <= cn) s_max = pref[mid];
            else s_max = pref[cn] + (ll)(mid - cn) * n;
            if (s_max >= s_total) r = mid;
            else l = mid + 1;
        }
        int k = l;
        ll s_min = (ll)k * (k + 1) / 2;
        // 根据题目保证，一定有解，无需判错
        ll delta = s_total - s_min;
 
        // 构造 u[j] (非降，0 ≤ u[j] ≤ d[j])
        vector<int> u(k + 2, 0);
        int cur_limit = n + 1;             // 相当于 u[k+1] = +∞
        for (int j = k; j >= 1; --j) {
            int d;
            if (j <= cn) d = g[j] - j;
            else d = n - j;
            int add = min(d, (int)delta);
            add = min(add, cur_limit);
            u[j] = add;
            delta -= add;
            cur_limit = u[j];
        }
 
        // 标记 T 中的数字
        vector<bool> mark(n + 1, false);
        for (int j = 1; j <= k; ++j) {
            int t = j + u[j];
            mark[t] = true;
        }
 
        // 输出 S = [1..n] \ T
        vector<int> ans;
        for (int i = 1; i <= n; ++i)
            if (!mark[i]) ans.push_back(i);
        printf("%d\n", (int)ans.size());
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) putchar(' ');
            printf("%d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}