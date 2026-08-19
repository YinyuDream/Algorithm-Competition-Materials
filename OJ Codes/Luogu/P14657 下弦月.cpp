#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Use a large enough infinity that won't overflow when added
const long long INF = 1e16; 

struct Matrix {
    long long m[2][2];
    Matrix() {
        m[0][0] = m[0][1] = m[1][0] = m[1][1] = -INF;
    }
};

// (max, +) matrix multiplication
// C[i][j] = max_k (A[i][k] + B[k][j])
Matrix multiply(const Matrix &A, const Matrix &B) {
    Matrix C;
    C.m[0][0] = max(A.m[0][0] + B.m[0][0], A.m[0][1] + B.m[1][0]);
    C.m[0][1] = max(A.m[0][0] + B.m[0][1], A.m[0][1] + B.m[1][1]);
    C.m[1][0] = max(A.m[1][0] + B.m[0][0], A.m[1][1] + B.m[1][0]);
    C.m[1][1] = max(A.m[1][0] + B.m[0][1], A.m[1][1] + B.m[1][1]);
    return C;
}

struct Node {
    int ch[2];
    int p;
    long long g0, g1; // Aggregated values from light children
    long long w;
    bool active;
    Matrix val;  // Local matrix based on g0, g1, w, active
    Matrix prod; // Product of matrices in the splay subtree

    Node() {
        ch[0] = ch[1] = 0;
        p = 0;
        g0 = 0; 
        g1 = 0;
        w = 0;
        active = false;
        // Initial state: Absent, no children contribution
        val.m[0][0] = val.m[0][1] = 0;
        val.m[1][0] = val.m[1][1] = -INF;
        prod = val;
    }
} tree[100005];

int n, q;
vector<int> adj[100005];
int weights[100005];

void push_up(int x) {
    Matrix temp = tree[x].val;
    if (tree[x].ch[0]) {
        temp = multiply(tree[tree[x].ch[0]].prod, temp);
    }
    if (tree[x].ch[1]) {
        temp = multiply(temp, tree[tree[x].ch[1]].prod);
    }
    tree[x].prod = temp;
}

bool is_root(int x) {
    int p = tree[x].p;
    return tree[p].ch[0] != x && tree[p].ch[1] != x;
}

void rotate(int x) {
    int y = tree[x].p;
    int z = tree[y].p;
    int k = (tree[y].ch[1] == x);
    if (!is_root(y)) {
        tree[z].ch[tree[z].ch[1] == y] = x;
    }
    tree[x].p = z;
    tree[y].ch[k] = tree[x].ch[k ^ 1];
    if (tree[x].ch[k ^ 1]) tree[tree[x].ch[k ^ 1]].p = y;
    tree[x].ch[k ^ 1] = y;
    tree[y].p = x;
    push_up(y);
    push_up(x);
}

void splay(int x) {
    while (!is_root(x)) {
        int y = tree[x].p;
        int z = tree[y].p;
        if (!is_root(y)) {
            ((tree[y].ch[0] == x) ^ (tree[z].ch[0] == y)) ? rotate(x) : rotate(y);
        }
        rotate(x);
    }
}

// Extract f values from a subtree's product matrix
pair<long long, long long> get_f(int x) {
    // The result is M * [0, 0]^T
    long long f0 = max(tree[x].prod.m[0][0], tree[x].prod.m[0][1]);
    long long f1 = max(tree[x].prod.m[1][0], tree[x].prod.m[1][1]);
    return {f0, f1};
}

void access(int x) {
    int t = 0;
    while (x) {
        splay(x);
        
        // When changing right child, update g values
        // Remove old right child contribution (it becomes dashed)
        if (tree[x].ch[1]) {
            pair<long long, long long> f = get_f(tree[x].ch[1]);
            tree[x].g0 += max(f.first, f.second);
            tree[x].g1 += f.first;
        }
        
        // Add new right child contribution (it was dashed, now solid/removed from g)
        // Wait! t is becoming solid, so we REMOVE its contribution from g
        if (t) {
            pair<long long, long long> f = get_f(t);
            tree[x].g0 -= max(f.first, f.second);
            tree[x].g1 -= f.first;
        }
        
        tree[x].ch[1] = t;
        
        // Recompute local matrix
        tree[x].val.m[0][0] = tree[x].val.m[0][1] = tree[x].g0;
        if (tree[x].active) {
            tree[x].val.m[1][0] = tree[x].g1 + tree[x].w;
            tree[x].val.m[1][1] = -INF;
        } else {
            tree[x].val.m[1][0] = -INF;
            tree[x].val.m[1][1] = -INF;
        }
        
        push_up(x);
        t = x;
        x = tree[x].p;
    }
}

void toggle(int x) {
    access(x);
    splay(x);
    tree[x].active = !tree[x].active;
    
    // Update matrix
    tree[x].val.m[0][0] = tree[x].val.m[0][1] = tree[x].g0;
    if (tree[x].active) {
        tree[x].val.m[1][0] = tree[x].g1 + tree[x].w;
        tree[x].val.m[1][1] = -INF;
    } else {
        tree[x].val.m[1][0] = -INF;
        tree[x].val.m[1][1] = -INF;
    }
    push_up(x);
}

struct Query {
    int l, r, id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
        tree[i].w = weights[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Build parent pointers using BFS
    vector<int> q_bfs;
    q_bfs.reserve(n);
    q_bfs.push_back(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    int head = 0;
    while(head < q_bfs.size()){
        int u = q_bfs[head++];
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                tree[v].p = u;
                q_bfs.push_back(v);
            }
        }
    }

    cin >> q;
    vector<Query> queries(q);
    int block_size = max(1, (int)(n / sqrt(q)));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }

    sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b) {
        int ba = a.l / block_size;
        int bb = b.l / block_size;
        if (ba != bb) return ba < bb;
        return (ba & 1) ? (a.r < b.r) : (a.r > b.r);
    });

    vector<long long> results(q);
    int L = 1, R = 0;
    
    auto update_node = [&](int u) {
        toggle(u);
    };

    for (const auto &qry : queries) {
        while (L > qry.l) update_node(--L);
        while (R < qry.r) update_node(++R);
        while (L < qry.l) update_node(L++);
        while (R > qry.r) update_node(R--);
        
        // The answer is the MWIS of the entire tree with nodes outside [L, R] marked absent.
        // We query the root (node 1).
        access(1);
        splay(1);
        pair<long long, long long> f = get_f(1);
        results[qry.id] = max(f.first, f.second);
    }

    for (int i = 0; i < q; ++i) {
        cout << results[i] << "\n";
    }

    return 0;
}