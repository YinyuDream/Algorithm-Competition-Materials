#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// 快速输入输出
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int n, m_limit;
vector<vector<int>> adj;
vector<int> sz;

// 合并两个DP数组：C[k] = max(A[i] + B[j])
// 优化：只计算索引和不超过 limit 的部分
vector<long long> merge(const vector<long long>& A, const vector<long long>& B, int limit) {
    if (A.empty()) return B;
    if (B.empty()) return A;
    int nA = A.size();
    int nB = B.size();
    // 结果的大小不需要超过 limit + 1
    int nC = min((long long)limit + 1, (long long)nA + nB - 1);
    vector<long long> C(nC, -1);
    
    for (int i = 0; i < nA; ++i) {
        if (A[i] == -1) continue;
        if (i > limit) break; // 超过limit的部分无需计算
        for (int j = 0; j < nB; ++j) {
            if (B[j] == -1) continue;
            if (i + j > limit) break; // 超过limit的部分无需计算
            long long val = A[i] + B[j];
            if (val > C[i + j]) {
                C[i + j] = val;
            }
        }
    }
    return C;
}

// 分治合并子结点的 DP 数组
vector<long long> merge_all(int l, int r, const vector<vector<long long>>& children_dps, int limit) {
    if (l > r) return {0}; // 空状态：权重0，价值0
    if (l == r) return children_dps[l];
    
    int mid = l;
    int tot = 0;
    for(int i = l; i <= r; ++i) tot += children_dps[i].size();
    
    int cur = 0;
    for(int i = l; i < r; ++i) {
        cur += children_dps[i].size();
        mid = i;
        if (cur * 2 >= tot) break;
    }
    
    // 递归合并，并传递 limit
    return merge(merge_all(l, mid, children_dps, limit), merge_all(mid + 1, r, children_dps, limit), limit);
}

// 分治计算 global_ans
// global_ans[w] 存储去除某个最大贡献子结点后，其余子结点权重和为 w 时的最大价值
void dac(int l, int r, const vector<vector<long long>>& children_dps, const vector<long long>& current_dp, vector<long long>& global_ans, int limit) {
    if (l == r) {
        // children_dps[l] 是选定的最大 mex 提供者 p
        // 我们只需要 p 的最大价值，具体的 k_p 会被公式中的 max k 抵消
        long long max_val = 0;
        for (long long x : children_dps[l]) if (x > max_val) max_val = x;
        
        // 更新 global_ans
        for (int i = 0; i < current_dp.size(); ++i) {
            if (current_dp[i] != -1) {
                if (i < global_ans.size()) {
                    long long total = current_dp[i] + max_val;
                    if (total > global_ans[i]) {
                        global_ans[i] = total;
                    }
                }
            }
        }
        return;
    }
    
    int mid = l;
    int tot = 0;
    for(int i = l; i <= r; ++i) tot += children_dps[i].size();
    
    int cur = 0;
    for(int i = l; i < r; ++i) {
        cur += children_dps[i].size();
        mid = i;
        if (cur * 2 >= tot) break;
    }
    
    // 向左递归：将右半部分子结点合并入 current_dp
    vector<long long> right_merged = merge_all(mid + 1, r, children_dps, limit);
    vector<long long> next_dp_left = merge(current_dp, right_merged, limit);
    dac(l, mid, children_dps, next_dp_left, global_ans, limit);
    
    // 向右递归：将左半部分子结点合并入 current_dp
    vector<long long> left_merged = merge_all(l, mid, children_dps, limit);
    vector<long long> next_dp_right = merge(current_dp, left_merged, limit);
    dac(mid + 1, r, children_dps, next_dp_right, global_ans, limit);
}

vector<long long> dfs(int u) {
    sz[u] = 1;
    vector<vector<long long>> children_dps;
    
    for (int v : adj[u]) {
        children_dps.push_back(dfs(v));
        sz[u] += sz[v];
    }
    
    // 叶子结点情况
    if (children_dps.empty()) {
        return {0, 1}; // dp[0]=0, dp[1]=1
    }
    
    // 按 DP 大小排序，保证分治平衡
    sort(children_dps.begin(), children_dps.end(), [](const vector<long long>& a, const vector<long long>& b){
        return a.size() < b.size();
    });
    
    // 计算除去最大子树后的背包问题
    // global_ans[w] 表示其他子树消耗 w 个名额时的最大收益
    vector<long long> global_ans(sz[u] + 1, -1);
    dac(0, children_dps.size() - 1, children_dps, {0}, global_ans, sz[u]);
    
    // 前缀最大值优化：因为约束是 <=，所以更小的重量也是合法的
    for (int k = 1; k < global_ans.size(); ++k) {
        if (global_ans[k-1] > global_ans[k]) global_ans[k] = global_ans[k-1];
    }
    
    vector<long long> dp_u(sz[u] + 1, -1);
    
    // 单独计算 j = 0 的情况
    // mex = 0 意味着集合中不含 0。这要求所有子树也不含 0 (即子树 mex = 0)。
    long long sum_zero = 0;
    bool possible_zero = true;
    for (const auto& c_dp : children_dps) {
        if (c_dp.empty() || c_dp[0] == -1) {
            possible_zero = false;
            break;
        }
        sum_zero += c_dp[0];
    }
    if (possible_zero) dp_u[0] = sum_zero;
    
    // 计算 j > 0 的情况
    // 约束: sum(k_others) <= sz[u] - j
    for (int j = 1; j <= sz[u]; ++j) {
        int rem = sz[u] - j;
        if (rem >= 0 && rem < global_ans.size() && global_ans[rem] != -1) {
            dp_u[j] = j + global_ans[rem];
        }
    }
    
    return dp_u;
}

void solve() {
    if (!(cin >> n >> m_limit)) return;
    adj.assign(n + 1, vector<int>());
    sz.assign(n + 1, 0);
    
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    vector<long long> root_dp = dfs(1);
    
    long long ans = 0;
    for (long long x : root_dp) {
        if (x > ans) ans = x;
    }
    cout << ans << "\n";
}

int main() {
    fast_io();
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}