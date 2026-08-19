#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAX_N_SUM = 500005;
// Sum of N over test cases is 5e5. log2(5e5) is ~19. 
// A safer upper bound for nodes is Sum(N) * (log(max N) + C)
// Total nodes needed is sum(n_i * log n_i).
// A single pool for all test cases is fine. Sum of N * 24 should be safe.
const int MAX_NODES = MAX_N_SUM * 24;

struct Node {
    long long sum;
    int left;
    int right;
};

Node tree[MAX_NODES];
int roots[MAX_N_SUM];
int node_count;
int max_val; // The maximum possible value in array a, used for segment tree range

// Optimized query to find the sum of intersection between two sets represented by PSTs
long long query_intersect(int u, int v, int l, int r) {
    // If either subtree is empty, intersection is empty
    if (!u || !v) {
        return 0;
    }
    // If the nodes are the same, the sets are identical in this value range.
    // The intersection sum is the sum of the subtree.
    if (u == v) {
        return tree[u].sum;
    }
    // Base case: leaf node
    if (l == r) {
        // Both must contain the value for it to be in the intersection
        return (tree[u].sum > 0 && tree[v].sum > 0) ? l : 0;
    }

    int mid = l + (r - l) / 2;
    // Recursively compute intersection sum, with pruning
    return query_intersect(tree[u].left, tree[v].left, l, mid) +
           query_intersect(tree[u].right, tree[v].right, mid + 1, r);
}


void update(int& cur, int pre, int l, int r, int pos, int val) {
    cur = ++node_count;
    tree[cur] = tree[pre];
    tree[cur].sum += val;
    if (l == r) {
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) {
        update(tree[cur].left, tree[pre].left, l, mid, pos, val);
    } else {
        update(tree[cur].right, tree[pre].right, mid + 1, r, pos, val);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    max_val = n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<long long> prefix_beauty(n + 1, 0);
    vector<int> parity(n + 1, 0);

    // Node 0 represents the empty tree
    roots[0] = 0; 
    tree[0] = {0, 0, 0};

    for (int i = 1; i <= n; ++i) {
        int val = a[i];
        if (parity[val] == 0) { // a[i] now appears an odd number of times
            update(roots[i], roots[i - 1], 1, max_val, val, val);
            prefix_beauty[i] = prefix_beauty[i - 1] + val;
            parity[val] = 1;
        } else { // a[i] now appears an even number of times
            update(roots[i], roots[i - 1], 1, max_val, val, -val);
            prefix_beauty[i] = prefix_beauty[i - 1] - val;
            parity[val] = 0;
        }
    }

    long long last_ans = 0;
    for (int i = 0; i < q; ++i) {
        int l_encoded, r_encoded;
        cin >> l_encoded >> r_encoded;

        int x = ((l_encoded - 1 + last_ans) % n) + 1;
        int y = ((r_encoded - 1 + last_ans) % n) + 1;
        
        int l = min(x, y);
        int r = max(x, y);

        long long sum_r = prefix_beauty[r];
        long long sum_l_minus_1 = prefix_beauty[l - 1];
        
        long long intersect_sum = query_intersect(roots[r], roots[l - 1], 1, max_val);

        last_ans = sum_r + sum_l_minus_1 - 2 * intersect_sum;
        cout << last_ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    node_count = 0; // Use a single memory pool for the tree across all test cases
    while (t--) {
        solve();
    }
    return 0;
}