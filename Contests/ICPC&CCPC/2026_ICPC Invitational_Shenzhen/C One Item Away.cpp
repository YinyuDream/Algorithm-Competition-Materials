#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 物品集合，ID 0 表示空集
    vector<vector<int>> set_items;
    set_items.emplace_back(); // ID 0: 空集

    // 缓存: cache[人][集合ID] = 效用值，-1 表示未查询
    vector<vector<long long>> cache(n + 1, vector<long long>(m + 2, -1));
    for (int i = 1; i <= n; ++i) cache[i][0] = 0;

    // 每个人当前持有的集合 ID
    vector<int> assign(n + 1, 0);

    // 嫉妒矩阵: envy[i][j] 为真表示 i 嫉妒 j
    vector<vector<bool>> envy(n + 1, vector<bool>(n + 1, false));

    int next_item = 1;

    // 查询函数（带缓存）
    auto query = [&](int person, int setId) -> long long {
        if (setId == 0) return 0;
        if (cache[person][setId] != -1) return cache[person][setId];
        const auto& items = set_items[setId];
        cout << "? " << person << " " << items.size();
        for (int x : items) cout << " " << x;
        cout << "\n";
        cout.flush();
        long long v;
        cin >> v;
        cache[person][setId] = v;
        return v;
    };

    // 更新与 i 相关的所有嫉妒边
    auto update_person = [&](int i) {
        long long self_i = query(i, assign[i]);
        for (int j = 1; j <= n; ++j) {
            if (j == i) continue;
            long long val_j = query(i, assign[j]);
            envy[i][j] = (self_i < val_j);
        }
        for (int k = 1; k <= n; ++k) {
            if (k == i) continue;
            long long self_k = query(k, assign[k]);
            long long val_i = query(k, assign[i]);
            envy[k][i] = (self_k < val_i);
        }
    };

    // 在嫉妒图中寻找环
    auto find_cycle = [&]() -> vector<int> {
        vector<int> color(n + 1, 0), parent(n + 1, -1);
        vector<int> cycle;
        for (int i = 1; i <= n && cycle.empty(); ++i) {
            if (color[i] == 0) {
                function<void(int)> dfs = [&](int u) {
                    color[u] = 1;
                    for (int v = 1; v <= n; ++v) {
                        if (!envy[u][v]) continue;
                        if (color[v] == 0) {
                            parent[v] = u;
                            dfs(v);
                            if (!cycle.empty()) return;
                        } else if (color[v] == 1) {
                            // 找到环
                            int start = v, end = u;
                            vector<int> cyc;
                            for (int cur = end; cur != start; cur = parent[cur])
                                cyc.push_back(cur);
                            cyc.push_back(start);
                            reverse(cyc.begin(), cyc.end());
                            cycle = cyc;
                            return;
                        }
                    }
                    color[u] = 2;
                };
                dfs(i);
            }
        }
        return cycle;
    };

    // 选择入度为 0 的节点（无人嫉妒他）
    auto choose_source = [&]() -> int {
        for (int i = 1; i <= n; ++i) {
            bool ok = true;
            for (int j = 1; j <= n; ++j)
                if (envy[j][i]) { ok = false; break; }
            if (ok) return i;
        }
        return -1;
    };

    // 主循环
    while (true) {
        // 消去所有嫉妒环
        while (true) {
            vector<int> cycle = find_cycle();
            if (cycle.empty()) break;

            // 旋转：环上每个人获得下一个人的集合
            vector<int> new_assign = assign;
            int sz = cycle.size();
            for (int idx = 0; idx < sz; ++idx) {
                int cur = cycle[idx];
                int nxt = cycle[(idx + 1) % sz];
                new_assign[cur] = assign[nxt];
            }
            assign = new_assign;
            for (int idx = 0; idx < sz; ++idx)
                update_person(cycle[idx]);
        }

        // 所有物品已分配完毕
        if (next_item > m) break;

        // 选择一个无人嫉妒的人，把下一件物品给他
        int chosen = choose_source();
        if (chosen == -1) break; // 理论上不会发生

        int item = next_item++;
        vector<int> new_items = set_items[assign[chosen]];
        new_items.push_back(item);
        int new_id = set_items.size();
        set_items.push_back(new_items);
        assign[chosen] = new_id;

        // 新集合产生，更新相关嫉妒关系（此处会产生实际的查询）
        update_person(chosen);
    }

    // 根据最终的分配确定每件物品属于谁
    vector<int> owner(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int sid = assign[i];
        for (int x : set_items[sid]) owner[x] = i;
    }

    // 输出答案
    cout << "!";
    for (int j = 1; j <= m; ++j) cout << " " << owner[j];
    cout << "\n";
    cout.flush();

    return 0;
}