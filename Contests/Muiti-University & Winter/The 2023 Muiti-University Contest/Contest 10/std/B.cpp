#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

enum Color {
    FOUR,
    FOUR_ADJ_TWO_THREE,
    THREE
};

Color col[N];

struct Hole {
    vector<int> edge[4];
    // pos[id] = edgeID
    map<int, int> pos;
    // opposites[{u, v}] = {edgeLength, oppo_u, oppo_v}
    map<pair<int, int>, tuple<int, int, int>> opposites;

    void add(int eid, int x) {
        pos[x] = eid;
        edge[eid].push_back(x);
    }
    void init() {
        for (int eid = 0; eid < 4; eid++) {
            edge[eid].push_back(edge[(eid + 1) % 4][0]);
        }
        for (int eid = 0; eid < 4; eid++) {
            int sz = edge[eid].size();
            int len = edge[(eid + 1) % 4].size() - 2;
            for (int j = 0; j + 1 < sz; j++) {
                auto u = edge[eid][j];
                auto v = edge[eid][j + 1];
                auto oppo_u = edge[(eid + 2) % 4][sz - j - 1];
                auto oppo_v = edge[(eid + 2) % 4][sz - j - 2];
                opposites[{u, v}] = {len, oppo_u, oppo_v};
                opposites[{v, u}] = {len, oppo_v, oppo_u};
            }
        }
    }
    vector<int> getVerticesBetween(int x, int y) {
        auto ex = pos[x];
        auto ey = pos[y];
        if (x == edge[ex].front() && y == edge[ex].back()) {
            vector<int> ret;
            for (int i = 1; i + 1 < (int)edge[ex].size(); i++) {
                ret.push_back(edge[ex][i]);
            }
            return ret;
        }
        if (x == edge[ey].back() && y == edge[ey].front()) {
            vector<int> ret;
            for (int i = 1; i + 1 < (int)edge[ey].size(); i++) {
                ret.push_back(edge[ey][i]);
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
        return {};
    }
} holes[N];

int n, m, r, c;
int holecnt, holeID[N];
bool vis[N];
vector<int> G[N];

bool is_adjacent(int u, int v) {
    // deg <= 4, brute force is faster
    return find(G[u].begin(), G[u].end(), v) != G[u].end();
}

template<typename T>
int next3(int x, T* vis) {
    for (auto y : G[x]) {
        if (col[y] == THREE && !vis[y]) return y;
    }
    return -1;
}
template<typename T>
int next4(int x, T* vis) {
    for (auto y : G[x]) {
        if (col[y] == FOUR_ADJ_TWO_THREE && !vis[y]) return y;
    }
    return -1;
}
template<typename T>
vector<vector<T>> transpose(const vector<vector<T>>& mat) {
    auto n = mat.size();
    auto m = mat[0].size();
    vector<vector<T>> ret(m, vector<T>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            ret[j][i] = mat[i][j];
        }
    return ret;
}
template<typename T>
vector<vector<T>> reverse_rows(const vector<vector<T>>& mat) {
    vector<vector<T>> ret = mat;
    for (auto & row : ret) {
        reverse(row.begin() + 1, row.end());
    }
    return ret;
}

// returns {length_of_brokens, next_x, next_y}
tuple<int, int, int> get_next_edge(int x, int y) {
    for (int xx : G[x]) {
        if (vis[xx]) continue;
        for (int yy : G[y]) {
            if (vis[yy]) continue;
            if (is_adjacent(xx, yy)) {
                return {0, xx, yy};
            }
        }
    }
    return {-1, -1, -1};
}

int main() {
    cin >> n >> m >> r >> c;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 3) {
            col[i] = THREE;
            continue;
        }
        int cnt3 = 0;
        for (auto j : G[i]) cnt3 += (G[j].size() == 3);
        col[i] = cnt3 == 2 ? FOUR_ADJ_TWO_THREE : FOUR;
    }

    // find holes
    for (int i = 1; i <= n; i++) {
        if (col[i] == FOUR_ADJ_TWO_THREE && !holeID[i]) {
            holecnt++;
            int cur = i;
            for (int j = 0; j < 4; j++) {
                while (true) {
                    holes[holecnt].add(j, cur);
                    holeID[cur] = holecnt;
                    int nxt = next3(cur, holeID);
                    if (nxt == -1) break;
                    cur = nxt;
                }
                cur = next4(cur, holeID);
            }
        }
    }
    for (int i = 1; i <= holecnt; i++) holes[i].init();

    // find one matrix that meets problem requirements.
    vector<vector<int>> matrix;
    
    // first, find a row/colume that contains 1, and the next row/colume
    vector<int> vec1, vec2;
    int x = 1, y = G[1][0];
    while (true) {
        if (holeID[x] && holeID[y]) {
            assert(holeID[x] == holeID[y]);
            vis[x] = vis[y] = true;
            vec1.push_back(x);
            vec2.push_back(y);

            auto hid = holeID[x];
            auto [len, next_x, next_y] = holes[hid].opposites[{x, y}];

            auto vecx = holes[hid].getVerticesBetween(x, next_x);
            if (vecx.empty()) vecx = vector<int>(len, -1);
            for (auto i : vecx) {
                vec1.push_back(i);
                if (i > 0) vis[i] = true;
            }
            auto vecy = holes[hid].getVerticesBetween(y, next_y);
            if (vecy.empty()) vecy = vector<int>(len, -1);
            for (auto i : vecy) {
                vec2.push_back(i);
                if (i > 0) vis[i] = true;
            }

            if (vis[next_x]) {
                assert(vis[next_y]);
                break;
            }
            x = next_x, y = next_y;
        }
        
        vis[x] = vis[y] = true;
        vec1.push_back(x);
        vec2.push_back(y);
        auto [len, next_x, next_y] = get_next_edge(x, y);
        if (len == -1) break;
        x = next_x, y = next_y;
    }
    matrix.push_back(vec1);
    matrix.push_back(vec2);

    // then we can get all the remaining rows/columns
    vector<int> last_vec = vec2;
    bool is_vec2 = true;
    while (is_vec2 || !is_adjacent(last_vec[0], 1)) {
        is_vec2 = false;
        int sz = last_vec.size();
        vector<int> vec(sz, -1);
        for (int i = 0; i < sz; i++) {
            int last_u = last_vec[i];
            if (last_u == -1) continue;
            
            vec[i] = -1;
            for (auto v : G[last_u]) {
                if (!vis[v]) {
                    vec[i] = v;
                    vis[v] = true;
                    break;
                }
            }
        }

        vector<int> starts;
        for (int i = 0; i < sz; i++) {
            if (last_vec[i] == -1 && last_vec[(i - 1 + sz) % sz] != -1) {
                starts.push_back((i - 1 + sz) % sz);
            }
        }
        for (int st : starts) {
            int en = (st + 1) % sz;
            while (last_vec[en] == -1) en = (en + 1) % sz;
            assert(vec[st] != -1 && vec[en] != -1 && holeID[vec[st]] && holeID[vec[st]] == holeID[vec[en]]);
            
            if (col[vec[st]] == FOUR_ADJ_TWO_THREE) {
                assert(col[vec[st]] == col[vec[en]]);
                auto hid = holeID[vec[st]];
                auto between = holes[hid].getVerticesBetween(vec[st], vec[en]);
                if (!between.empty()) {
                    int i = (st + 1) % sz;
                    for (auto x : between) {
                        vec[i] = x;
                        vis[x] = true;
                        i = (i + 1) % sz;
                    }
                }
            }
        }

        matrix.push_back(vec);
        swap(vec, last_vec);
    }

    for (auto & row : matrix)
        for (auto & item : row)
            if (item == -1) item = n + 1;
    auto R = reverse_rows(matrix);
    auto T = transpose(matrix);
    auto TR = reverse_rows(T);
    auto RT = transpose(R);
    auto TRT = transpose(TR);
    auto RTR = reverse_rows(RT);
    auto RTRT = transpose(RTR); // equals TRTR
    auto print = [](const vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == n + 1) cout << "-1 ";
                else cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    };
    if (r == c) print(min({matrix, R, T, TR, RT, TRT, RTR, RTRT}));
    else if ((int)matrix.size() == r) print(min({matrix, R, TRT, RTRT}));
    else print(min({T, TR, RT, RTR}));

    return 0;
}