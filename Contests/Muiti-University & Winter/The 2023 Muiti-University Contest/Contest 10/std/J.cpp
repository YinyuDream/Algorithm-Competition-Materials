#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

struct Edge {
    int v; char c;
};

int n, m, k;
char self_loop[N];
bool acc[N];
vector<Edge> G[N];

int stp, dfn[N], low[N], stk[N], top, comp[N], comps;
vector<int> scc[N];
bool has_loop[N];
void tarjan(int u) {
    dfn[u] = low[u] = ++stp;
    stk[top++] = u;
    for (auto [v, c] : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!comp[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        comps++;
        do {
            int v = stk[--top];
            comp[v] = comps;
            scc[comps].push_back(v);
        } while (stk[top] != u);
    }
}

string cur;
int id, pos;
bool vis[N][2];
bool dfs1(int u, int loop_id, int loop_pos) {
    bool loop = (loop_id != 0);

    vis[u][loop] = true;
    if (acc[u] && loop) {
        id = loop_id, pos = loop_pos;
        return true;
    }
    for (auto [v, c] : G[u]) {
        int nxtid = loop_id, nxtpos = loop_pos;
        if (!nxtid && has_loop[v]) {
            nxtid = v, nxtpos = cur.size() + 1;
        }
        if (vis[v][nxtid != 0]) continue;
        cur.push_back(c);
        bool found = dfs1(v, nxtid, nxtpos);
        if (found) return true;
        cur.pop_back();
    }
    return false;
}

string loop_str;
bool vis2[N];
bool dfs2(int u, int init_u) {
    vis2[u] = true;
    for (auto [v, c] : G[u]) {
        if (v == init_u) {
            loop_str.push_back(c);
            return true;
        }

        if (vis2[v]) continue;
        loop_str.push_back(c);
        bool found = dfs2(v, init_u);
        if (found) return true;
        loop_str.pop_back();
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1, x; i <= k; i++) {
        cin >> x; acc[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        if (v != u) G[u].push_back({v, c});
        else self_loop[u] = c;
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= n; i++) {
        has_loop[i]  = (self_loop[i] || scc[comp[i]].size() > 1);
    }

    if (!dfs1(1, (has_loop[1] ? 1 : 0), 0)) {
        cout << -1 << endl;
        return 0;
    }
    if (self_loop[id]) loop_str += self_loop[id];
    else assert(dfs2(id, id));

    cur.insert(pos, loop_str);
    cout << cur << endl;
    return 0;
}