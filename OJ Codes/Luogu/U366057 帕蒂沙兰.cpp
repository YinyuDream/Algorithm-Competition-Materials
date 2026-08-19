#include <bits/stdc++.h>
using namespace std;
struct Node {
    vector<int> add;
    vector<int> nxt;
};
vector<Node> tree;
void build(int node, int l, int r, int d, vector<vector<int>>& first_arr) {
    if (l == r) {
        for (int t = 0; t < d; ++t) {
            int ft = first_arr[l][t];
            if (ft != -1) {
                tree[node].add[t] = 1;
                tree[node].nxt[t] = ft;
            } else {
                tree[node].add[t] = 0;
                tree[node].nxt[t] = 0;
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid, d, first_arr);
    build(2 * node + 1, mid + 1, r, d, first_arr);
    for (int t = 0; t < d; ++t) {
        int la = tree[2 * node].add[t];
        int ln = tree[2 * node].nxt[t];
        int ra = tree[2 * node + 1].add[ln];
        int rn = tree[2 * node + 1].nxt[ln];
        tree[node].add[t] = la + ra;
        tree[node].nxt[t] = rn;
    }
}
void update(int node, int l, int r, int b, int d, vector<vector<int>>& first_arr) {
    if (l == r) {
        for (int t = 0; t < d; ++t) {
            int ft = first_arr[b][t];
            if (ft != -1) {
                tree[node].add[t] = 1;
                tree[node].nxt[t] = ft;
            } else {
                tree[node].add[t] = 0;
                tree[node].nxt[t] = 0;
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    if (b <= mid) {
        update(2 * node, l, mid, b, d, first_arr);
    } else {
        update(2 * node + 1, mid + 1, r, b, d, first_arr);
    }
    for (int t = 0; t < d; ++t) {
        int la = tree[2 * node].add[t];
        int ln = tree[2 * node].nxt[t];
        int ra = tree[2 * node + 1].add[ln];
        int rn = tree[2 * node + 1].nxt[ln];
        tree[node].add[t] = la + ra;
        tree[node].nxt[t] = rn;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int d = k + 1;
    vector<int> a(n + 1);
    vector<vector<int>> color_pos(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        color_pos[a[i]].push_back(i);
    }
    int blocks = (n + d - 1) / d;
    const int threshold = 1000;
    vector<vector<char>> active(blocks, vector<char>(d, 0));
    vector<vector<int>> first_arr(blocks, vector<int>(d + 1, -1));
    for (int b = 0; b < blocks; ++b) {
        first_arr[b][d] = -1;
        for (int t = d - 1; t >= 0; --t) {
            first_arr[b][t] = active[b][t] ? t : first_arr[b][t + 1];
        }
    }
    int ans = 0;
    if (blocks <= threshold) {
        int left = 1;
        for (int curr = 1; curr <= n; ++curr) {
            for (int p : color_pos[curr]) {
                int b = (p - 1) / d;
                int p_prime = (p - 1) % d;
                active[b][p_prime] = 1;
                for (int t = p_prime; t >= 0; --t) {
                    first_arr[b][t] = active[b][t] ? t : first_arr[b][t + 1];
                }
            }
            while (curr - left + 1 > m) {
                for (int p : color_pos[left]) {
                    int b = (p - 1) / d;
                    int p_prime = (p - 1) % d;
                    active[b][p_prime] = 0;
                    for (int t = p_prime; t >= 0; --t) {
                        first_arr[b][t] = active[b][t] ? t : first_arr[b][t + 1];
                    }
                }
                ++left;
            }
            int current_t = 0, total = 0;
            for (int b = 0; b < blocks; ++b) {
                int ft = first_arr[b][current_t];
                if (ft != -1) {
                    ++total;
                    current_t = ft;
                } else {
                    current_t = 0;
                }
            }
            ans = max(ans, total);
        }
    } else {
        tree.resize(4 * blocks);
        for (int i = 0; i < 4 * blocks; ++i) {
            tree[i].add.resize(d);
            tree[i].nxt.resize(d);
        }
        build(1, 0, blocks - 1, d, first_arr);
        int left = 1;
        for (int curr = 1; curr <= n; ++curr) {
            for (int p : color_pos[curr]) {
                int b = (p - 1) / d;
                int p_prime = (p - 1) % d;
                active[b][p_prime] = 1;
                for (int t = p_prime; t >= 0; --t) {
                    first_arr[b][t] = active[b][t] ? t : first_arr[b][t + 1];
                }
                update(1, 0, blocks - 1, b, d, first_arr);
            }
            while (curr - left + 1 > m) {
                for (int p : color_pos[left]) {
                    int b = (p - 1) / d;
                    int p_prime = (p - 1) % d;
                    active[b][p_prime] = 0;
                    for (int t = p_prime; t >= 0; --t) {
                        first_arr[b][t] = active[b][t] ? t : first_arr[b][t + 1];
                    }
                    update(1, 0, blocks - 1, b, d, first_arr);
                }
                ++left;
            }
            ans = max(ans, tree[1].add[0]);
        }
    }
    cout << ans << endl;
    return 0;
}