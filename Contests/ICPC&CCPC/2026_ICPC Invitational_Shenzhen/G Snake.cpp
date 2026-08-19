#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int n, m;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dir_char[4] = {'U', 'D', 'L', 'R'};

// 当蛇长度为1时，直接生成最短合法路径（先水平后垂直，保证不提前进入苹果）
string get_path_L1(int hr, int hc, int tr, int tc) {
    string path;
    int dc = tc - hc;
    char move_c = (dc > 0) ? 'R' : 'L';
    for (int i = 0; i < abs(dc); ++i) path.push_back(move_c);
    int dr_ = tr - hr;
    char move_r = (dr_ > 0) ? 'D' : 'U';
    for (int i = 0; i < abs(dr_); ++i) path.push_back(move_r);
    return path;
}

// 用于 std::unordered_map 的自定义哈希
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = 0;
        for (int x : v) {
            h = h * 1000003 + hash<int>()(x);
        }
        return h;
    }
};

// A* 搜索，用于蛇长度 >= 2 的情况
string astar_search(const deque<pair<int,int>>& body, int target_r, int target_c) {
    // 将身体序列转为 id 向量（id = r * m + c）
    vector<int> init_body;
    int head_r = -1, head_c = -1, tail_r = -1, tail_c = -1;
    for (auto& p : body) {
        int id = p.first * m + p.second;
        init_body.push_back(id);
        if (head_r == -1) { head_r = p.first; head_c = p.second; }
        tail_r = p.first; tail_c = p.second;
    }

    // 忽略蛇身体的 BFS 距离，用作启发式
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> dist_q;
    dist[target_r][target_c] = 0;
    dist_q.push({target_r, target_c});
    while (!dist_q.empty()) {
        int r = dist_q.front().first;
        int c = dist_q.front().second;
        dist_q.pop();
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                dist_q.push({nr, nc});
            }
        }
    }

    int max_steps = n * m;   // 序列长度上限

    struct State {
        vector<int> body;
        int head_r, head_c, tail_r, tail_c;
        int g, h;
        int parent;
        char move;
        bool expanded;
        State() : head_r(0), head_c(0), tail_r(0), tail_c(0), g(0), h(0), parent(-1), move(' '), expanded(false) {}
    };

    vector<State> states;
    unordered_map<vector<int>, int, VectorHash> closed;

    State init_state;
    init_state.body = init_body;
    init_state.head_r = head_r; init_state.head_c = head_c;
    init_state.tail_r = tail_r; init_state.tail_c = tail_c;
    init_state.g = 0;
    init_state.h = dist[head_r][head_c];
    init_state.parent = -1;
    init_state.move = ' ';
    init_state.expanded = false;

    closed[init_state.body] = 0;
    states.push_back(init_state);

    using pf = pair<int,int>;
    priority_queue<pf, vector<pf>, greater<pf>> pq;
    pq.push({init_state.g + init_state.h, 0});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int id = top.second;
        if (states[id].expanded) continue;
        states[id].expanded = true;
        State cur = states[id];   // 拷贝当前状态，避免 vector 重分配引起引用失效

        for (int d = 0; d < 4; ++d) {
            int nr = cur.head_r + dr[d];
            int nc = cur.head_c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            char cmd = dir_char[d];
            int new_id = nr * m + nc;

            if (nr == target_r && nc == target_c) {
                // 尝试作为最后一步（吃苹果）
                bool in_body = false;
                for (int x : cur.body) if (x == new_id) { in_body = true; break; }
                if (!in_body) {
                    if (cur.g + 1 > max_steps) continue;
                    // 回溯构造命令序列
                    string path;
                    int iid = id;
                    while (states[iid].parent != -1) {
                        path.push_back(states[iid].move);
                        iid = states[iid].parent;
                    }
                    reverse(path.begin(), path.end());
                    path.push_back(cmd);
                    return path;
                }
            } else {
                // 正常移动
                int L = cur.body.size();
                bool legal = false;
                if (new_id == cur.body.back()) {
                    legal = true;   // 允许进入尾巴即将离开的格子
                } else {
                    legal = true;
                    for (int i = 0; i < L - 1; ++i) {
                        if (cur.body[i] == new_id) { legal = false; break; }
                    }
                }
                if (!legal) continue;
                // 剪枝：正常移动后至少还需一步吃苹果
                if (cur.g + 2 > max_steps) continue;

                vector<int> new_body;
                new_body.reserve(L);
                new_body.push_back(new_id);
                for (int i = 0; i < L - 1; ++i) new_body.push_back(cur.body[i]);

                int new_tail_id = cur.body[L - 2];
                int new_tail_r = new_tail_id / m;
                int new_tail_c = new_tail_id % m;

                int new_g = cur.g + 1;
                int new_h = dist[nr][nc];
                if (new_g + new_h > max_steps) continue;

                if (closed.find(new_body) != closed.end()) continue;

                State new_state;
                new_state.body = new_body;
                new_state.head_r = nr; new_state.head_c = nc;
                new_state.tail_r = new_tail_r; new_state.tail_c = new_tail_c;
                new_state.g = new_g;
                new_state.h = new_h;
                new_state.parent = id;
                new_state.move = cmd;
                new_state.expanded = false;

                int new_id_idx = states.size();
                closed[new_body] = new_id_idx;
                states.push_back(new_state);
                pq.push({new_g + new_h, new_id_idx});
            }
        }
    }

    return "";   // 按照题目保证不会执行到这里
}

// 在真实蛇身上执行序列，更新身体
void apply_path(deque<pair<int,int>>& body, const string& path) {
    for (size_t i = 0; i + 1 < path.size(); ++i) {
        char cmd = path[i];
        int nr = body[0].first, nc = body[0].second;
        if (cmd == 'U') nr--;
        else if (cmd == 'D') nr++;
        else if (cmd == 'L') nc--;
        else if (cmd == 'R') nc++;
        body.push_front({nr, nc});
        body.pop_back();
    }
    // 最后一步为吃苹果，尾巴不移动
    if (!path.empty()) {
        char cmd = path.back();
        int nr = body[0].first, nc = body[0].second;
        if (cmd == 'U') nr--;
        else if (cmd == 'D') nr++;
        else if (cmd == 'L') nc--;
        else if (cmd == 'R') nc++;
        body.push_front({nr, nc});
    }
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int rs, cs;
        cin >> n >> m >> rs >> cs;
        rs--; cs--;
        deque<pair<int,int>> body;
        body.push_back({rs, cs});
        int total_apples = n * m - 1;
        for (int i = 0; i < total_apples; ++i) {
            int r, c;
            cin >> r >> c;
            r--; c--;
            string path;
            if (body.size() == 1) {
                path = get_path_L1(body[0].first, body[0].second, r, c);
            } else {
                path = astar_search(body, r, c);
            }
            cout << path << endl;   // 输出并刷新
            apply_path(body, path);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}