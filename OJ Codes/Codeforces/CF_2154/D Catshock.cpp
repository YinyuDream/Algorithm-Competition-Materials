#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // 1) 以 n 为根做 BFS 计算深度
        vector<int> depth(n + 1, -1);
        queue<int> q;
        depth[n] = 0;
        q.push(n);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        // 2) 预先计算叶子删除顺序（不删除 n）
        vector<int> deg(n + 1);
        for (int i = 1; i <= n; ++i) deg[i] = (int)g[i].size();
        vector<char> removed(n + 1, 0);
        queue<int> leaves;
        for (int i = 1; i <= n; ++i) {
            if (i != n && deg[i] == 1) leaves.push(i);
        }

        vector<int> order;
        order.reserve(n - 1);
        while (!leaves.empty()) {
            int u = leaves.front(); leaves.pop();
            if (removed[u]) continue;
            removed[u] = 1;
            order.push_back(u);
            // u 为叶子，未被删除的邻居只有一个
            for (int v : g[u]) if (!removed[v]) {
                deg[v]--;
                if (v != n && deg[v] == 1) leaves.push(v);
            }
        }
        // 到这里 order 长度应为 n-1，剩下的节点就是 n

        // 3) 生成操作：对每个待删叶子 u，先发 1 次或 2 次“1”，再“2 u”
        vector<pair<int,int>> ops;  // (type, u)；type=1 => "1"; type=2 => "2 u"
        int curParity = depth[1] & 1; // 当前猫所在点的深度奇偶；初始在 1 上

        for (int u : order) {
            // 必须确保在删除 u 前，猫的奇偶 != depth[u]%2
            // 先发一个“1”，猫一定移动（剩余至少 2 个点时图连通）
            ops.emplace_back(1, 0);
            curParity ^= 1;
            if (curParity == (depth[u] & 1)) {
                // 再发一次“1”翻转奇偶，确保不与 u 同奇偶
                ops.emplace_back(1, 0);
                curParity ^= 1;
            }
            // 此时猫不可能在 u 上，安全删除
            ops.emplace_back(2, u);
        }

        cout << ops.size() << '\n';
        for (auto [t, u] : ops) {
            if (t == 1) cout << 1 << '\n';
            else cout << 2 << ' ' << u << '\n';
        }
    }
    return 0;
}