#include <bits/stdc++.h>
using namespace std;
int dx[5] = {-1, 1, 0, 0, 0};
int dy[5] = {0, 0, -1, 1, 0};
int bfs() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[j][i];
        }
    }
    int x, y;
    cin >> x >> y;
    int g;
    cin >> g;
    vector<int> v;
    vector<vector<pair<int, int>>> gr(g);
    for (int i = 0; i < g; ++i) {
        int k;
        cin >> k;
        gr[i].resize(k);
        v.push_back(k);
        for (int j = 0; j < k; ++j) {
            int x, y;
            cin >> x >> y;
            gr[i][j] = {x, y};
        }
    }
    queue<tuple<int, int, int>> q;
    map<tuple<int, int, int>, int> mp;
    q.push(make_tuple(x, y, 0));
    mp[{x, y, 0}] = 1;
    int al = 0;
    map<pair<int, int>, int> mgq[841];
    map<pair<int, int>, int> gp[841];
    for (int t = 0; t <= 840; t++) {
        for (auto& route : gr) {
            pair<int, int> pos = route[(t + 1) % route.size()];
            mgq[t][pos] = 1;
        }
        for (auto& route : gr) {
            pair<int, int> pos = route[t % route.size()];
            gp[t][pos] = 1;
        }
    }
    while (!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();
        al++;
        if (t >= 840) return -1;
        if (grid[x][y] == 0) {
            return t;
        }
        for (int i = 0; i < 5; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] <= grid[x][y] && !mgq[t][{nx, ny}] && !gp[t][{nx, ny}] && mp[{nx, ny, t + 1}] == 0) {
                q.push(make_tuple(nx, ny, t + 1));
                mp[{nx, ny, t + 1}] = 1;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        cout << bfs() << "\n";
    }
    return 0;
}