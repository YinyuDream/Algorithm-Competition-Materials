#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void dfs_size(int u, int p, const vector<vector<int>>& adj, vector<int>& size) {
    size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_size(v, u, adj, size);
            size[u] += size[v];
        }
    }
}

int find_centroid(int u, int p, int total, const vector<vector<int>>& adj, const set<int>& candidates, vector<int>& size) {
    bool is_centroid = true;
    for (int v : adj[u]) {
        if (v != p && candidates.count(v) && size[v] > total / 2) {
            is_centroid = false;
            int centroid = find_centroid(v, u, total, adj, candidates, size);
            if (centroid != -1) return centroid;
        }
    }
    if (is_centroid) return u;
    return -1;
}

void dfs_mark(int u, int p, const set<int>& candidates, const vector<vector<int>>& adj, set<int>& new_candidates) {
    if (candidates.count(u)) new_candidates.insert(u);
    for (int v : adj[u]) {
        if (v != p && candidates.count(v)) {
            dfs_mark(v, u, candidates, adj, new_candidates);
        }
    }
}

int floor_log2(int n) {
    return n >= 1 ? static_cast<int>(log2(n)) : 0;
}

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x != 0) adj[i].push_back(x);
            if (y != 0) adj[i].push_back(y);
        }
        vector<int> size(n+1, 0);
        dfs_size(1, -1, adj, size);
        set<int> current_candidates;
        for (int i = 1; i <= n; ++i) {
            current_candidates.insert(i);
        }
        int p = floor_log2(n);
        for (int q = 0; q < p; ++q) {
            int centroid = find_centroid(1, -1, size[1], adj, current_candidates, size);
            int v = -1;
            if (!adj[centroid].empty()) {
                for (int child : adj[centroid]) {
                    if (current_candidates.count(child)) {
                        v = child;
                        break;
                    }
                }
            }
            if (v == -1) {
                v = *current_candidates.begin();
            }
            if (v == centroid) {
                cout << "! " << centroid << endl;
                cout.flush();
                break;
            }
            cout << "? " << centroid << " " << v << endl;
            cout.flush();
            int t;
            cin >> t;
            set<int> new_candidates;
            if (t == 0) {
                dfs_mark(centroid, -1, current_candidates, adj, new_candidates);
            } else if (t == 2) {
                dfs_mark(v, centroid, current_candidates, adj, new_candidates);
            } else if (t == 1) {
                dfs_mark(centroid, -1, current_candidates, adj, new_candidates);
                dfs_mark(v, centroid, current_candidates, adj, new_candidates);
            }
            current_candidates = new_candidates;
            if (current_candidates.size() == 1) {
                int s = *current_candidates.begin();
                cout << "! " << s << endl;
                cout.flush();
                break;
            }
        }
        if (current_candidates.size() > 1) {
            int s = *current_candidates.begin();
            cout << "! " << s << endl;
            cout.flush();
        }
    }
    return 0;
}
