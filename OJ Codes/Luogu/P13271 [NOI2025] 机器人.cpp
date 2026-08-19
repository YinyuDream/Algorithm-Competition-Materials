#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> v(k + 1, 0); 
    vector<ll> w(k + 1, 0); 
    if (k > 1) {
        for (int i = 1; i <= k - 1; i++) {
            cin >> v[i];
        }
        for (int i = 2; i <= k; i++) {
            cin >> w[i];
        }
    }

    vector<ll> pre_dec(k + 1, 0);
    for (int i = 2; i <= k; i++) {
        pre_dec[i] = pre_dec[i - 1] + w[i];
    }

    vector<int> d(n + 1, 0);
    vector<vector<pair<int, ll>>> out_edges(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        for (int j = 0; j < d[i]; j++) {
            int y;
            ll z;
            cin >> y >> z;
            out_edges[i].push_back({y, z});
        }
    }

    vector<ll> ans_node(n + 1, LLONG_MAX);
    ans_node[1] = (d[1] == 0) ? 0 : LLONG_MAX;

    vector<int> state_start(n + 1, -1);
    vector<int> state_num(n + 1, 0);

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] >= 1) {
            state_start[i] = tot;
            state_num[i] = d[i];
            tot += d[i];
        }
    }

    vector<vector<pli>> graph(tot);
    vector<vector<pli>> extra(tot);

    for (int i = 1; i <= n; i++) {
        if (d[i] < 1) continue;
        for (int p = 1; p <= d[i]; p++) {
            int id1 = state_start[i] + (p - 1);
            if (p < d[i]) {
                int id2 = state_start[i] + p;
                graph[id1].push_back({id2, v[p]});
                graph[id2].push_back({id1, w[p + 1]});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] < 1) continue;
        for (int j = 1; j <= d[i]; j++) {
            auto [y, z] = out_edges[i][j - 1];
            int from_id = state_start[i] + (j - 1);
            if (d[y] >= 1) {
                if (j <= d[y]) {
                    int to_id = state_start[y] + (j - 1);
                    graph[from_id].push_back({to_id, z});
                } else {
                    int to_id = state_start[y] + (d[y] - 1);
                    ll adjust_cost = pre_dec[j] - pre_dec[d[y]];
                    graph[from_id].push_back({to_id, z + adjust_cost});
                }
            } else {
                extra[from_id].push_back({y, z});
            }
        }
    }

    vector<ll> dist(tot, LLONG_MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    if (d[1] >= 1) {
        int start_id = state_start[1];
        dist[start_id] = 0;
        pq.push({0, start_id});
    }

    while (!pq.empty()) {
        auto [d_val, u] = pq.top();
        pq.pop();
        if (d_val != dist[u]) continue;

        for (auto [y, z] : extra[u]) {
            if (d_val + z < ans_node[y]) {
                ans_node[y] = d_val + z;
            }
        }

        for (auto [v_id, weight] : graph[u]) {
            if (dist[v_id] > d_val + weight) {
                dist[v_id] = d_val + weight;
                pq.push({dist[v_id], v_id});
            }
        }
    }

    cout << 0;
    for (int i = 2; i <= n; i++) {
        if (d[i] >= 1) {
            ll min_val = LLONG_MAX;
            for (int j = 0; j < state_num[i]; j++) {
                int id = state_start[i] + j;
                if (dist[id] < min_val) {
                    min_val = dist[id];
                }
            }
            if (min_val == LLONG_MAX) {
                cout << " -1";
            } else {
                cout << " " << min_val;
            }
        } else {
            if (ans_node[i] == LLONG_MAX) {
                cout << " -1";
            } else {
                cout << " " << ans_node[i];
            }
        }
    }
    cout << endl;

    return 0;
}