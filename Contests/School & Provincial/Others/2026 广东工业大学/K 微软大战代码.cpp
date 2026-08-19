#include <bits/stdc++.h>
using namespace std;
 
struct TrieNode {
    int nxt[26];
    vector<int> nodes;
    TrieNode() {
        memset(nxt, -1, sizeof(nxt));
    }
};
 
void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, char>>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        char ch;
        cin >> x >> ch;
        children[x].emplace_back(i, ch);
    }
 
    // 构建Trie树
    vector<TrieNode> trie;
    trie.emplace_back(); // 根节点索引0
    // 栈用于DFS原树，元素为(原树节点编号, 对应Trie节点索引)
    stack<pair<int, int>> stk;
    stk.emplace(1, 0);
    trie[0].nodes.push_back(1); // 根节点对应的原树节点1
    while (!stk.empty()) {
        auto [u, trieIdx] = stk.top();
        stk.pop();
        for (auto [v, ch] : children[u]) {
            int c = ch - 'a';
            int& nxt = trie[trieIdx].nxt[c];
            if (nxt == -1) {
                nxt = trie.size();
                trie.emplace_back();
            }
            int childTrieIdx = nxt;
            trie[childTrieIdx].nodes.push_back(v);
            stk.emplace(v, childTrieIdx);
        }
    }
 
    // 对每个Trie节点的节点列表排序
    for (auto& node : trie) {
        sort(node.nodes.begin(), node.nodes.end());
    }
 
    // 先序遍历Trie树输出
    vector<int> ans;
    stack<int> stk2;
    stk2.push(0);
    while (!stk2.empty()) {
        int idx = stk2.top();
        stk2.pop();
        // 输出当前节点对应的所有原树节点
        for (int v : trie[idx].nodes) {
            ans.push_back(v);
        }
        // 子节点按字母逆序入栈，以保证正序输出
        for (int c = 25; c >= 0; --c) {
            if (trie[idx].nxt[c] != -1) {
                stk2.push(trie[idx].nxt[c]);
            }
        }
    }
 
    // 输出答案
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}