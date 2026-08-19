#include <bits/stdc++.h>
using namespace std;
const int N = 1005, MOD = 998244353;
inline void mo(int& x) { x >= MOD ? x -= MOD : 0; }
inline int mo1(int x) { return x >= MOD ? x - MOD : x; }
inline int fpow(int x, int n, int ret = 1) {
    if (n < 0)
        n += MOD - 1;
    for (; n; n >>= 1, x = 1ll * x * x % MOD) n& 1 ? ret = 1ll * ret * x % MOD : 0;
    return ret;
}
int top_node = 0, fac[N];
struct Initer {
    Initer() {
        fac[0] = 1;
        for (int i = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
} __initer;
struct DSF {
    int fa[N];
    void ms(int x) { fa[x] = x; }
    int fs(int x) {
        if (fa[x] != x)
            fa[x] = fs(fa[x]);
        return fa[x];
    }
    bool member(int x, int y) { return fs(x) == fs(y); }
    void merge(int x, int y) {
        if (member(x, y))
            return;
        fa[fs(x)] = fs(y);
    }
} dsf;
struct Res {
    int x, y, z;
};
bool cmp(Res x, Res y) { return x.z < y.z; }
vector<int> son[N];
int fa[N];
void build_tree(vector<Res> a, int n) {
    static vector<Res> g[N];
    for (auto x : a) g[x.z].push_back(x);
    for (int i = 1; i <= n; ++i) dsf.ms(i);
    top_node = n;
    for (int i = 1; i <= n; ++i) {
        vector<int> node;
        for (auto x : g[i]) {
            node.push_back(dsf.fs(x.x));
            node.push_back(dsf.fs(x.y));
        }
        sort(node.begin(), node.end());
        node.erase(unique(node.begin(), node.end()), node.end());
        for (auto x : g[i]) dsf.merge(x.x, x.y);
        for (auto x : node)
            if (dsf.fs(x) == x) {
                dsf.ms(++top_node);
                dsf.merge(x, top_node);
            }
        for (auto x : node) {
            son[dsf.fs(x)].push_back(x);
            fa[x] = dsf.fs(x);
        }
    }
}
vector<Res> b;
int f[N][N], f2[N], sz[N], flag[N], g[N][N][2], h[N][N][2], n, dep[N], u, v;
bool vis[N];
int flag_node = -1;
void dfs(int x, int pre) {
    dep[x] = dep[pre] + 1;
    flag[x] = vis[x];
    sz[x] = son[x].empty();
    int cnt = 0;
    for (auto y : son[x]) {
        dfs(y, x);
        flag[x] += flag[y];
        sz[x] += sz[y];
    }
}
void dfs1(int x) {
    if (son[x].empty()) {
        f[x][1] = 1;
        f2[x] = 1;
        return;
    }
    f2[x] = fpow(sz[x], (int)son[x].size() - 2);
    for (auto y : son[x]) {
        dfs1(y);
        f2[x] = 1ll * f2[x] * f2[y] % MOD * sz[y] % MOD;
    }
    for (int i = 0; i <= son[x].size(); ++i)
        for (int j = 0; j <= sz[x]; ++j) g[i][j][0] = g[i][j][1] = 0;
    int szx = 0, cnt = 0;
    g[0][0][0] = 1;
    for (auto y : son[x]) {
        ++cnt;
        for (int t = 0; t <= cnt; ++t)
            for (int j = 0; j <= szx + sz[y]; ++j) h[t][j][0] = h[t][j][1] = 0;
        if (flag[y] == 1) {
            for (int t = 0; t < cnt; ++t)
                for (int i = 0; i <= szx; ++i)
                    for (int j = 0; j <= sz[y]; ++j) {
                        h[t + 1][i + j][0] = (h[t + 1][i + j][0] + 1ll * g[t][i][0] * f[y][j]) % MOD;
                        h[t + 1][i + j][1] = (h[t + 1][i + j][1] + 1ll * g[t][i][1] * f[y][j] +
                                              1ll * g[t][i][0] * f[y][j] % MOD * sz[y]) %
                                             MOD;
                    }
        } else {
            for (int t = 0; t < cnt; ++t)
                for (int i = 0; i <= szx; ++i) {
                    for (int j = 0; j <= sz[y]; ++j) {
                        h[t + 1][i + j][0] = (h[t + 1][i + j][0] + 1ll * g[t][i][0] * f[y][j]) % MOD;
                        h[t + 1][i + j][1] = (h[t + 1][i + j][1] + 1ll * g[t][i][1] * f[y][j] +
                                              1ll * g[t][i][0] * f[y][j] % MOD * sz[y]) %
                                             MOD;
                    }
                    for (int k = 0; k < 2; ++k)
                        h[t][i][k] = (h[t][i][k] + 1ll * g[t][i][k] * f2[y] % MOD * sz[y]) % MOD;
                }
        }
        szx += sz[y];
        for (int t = 0; t <= cnt; ++t)
            for (int i = 0; i <= szx; ++i)
                for (int k = 0; k < 2; ++k) g[t][i][k] = h[t][i][k];
    }
    vector<int> pw(cnt + 1);
    pw[0] = 1;
    for (int i = 1; i < pw.size(); ++i) pw[i] = 1ll * pw[i - 1] * sz[x] % MOD;
    for (int t = flag[x]; t <= cnt; ++t)
        for (int i = 0; i <= szx; ++i) {
            //		if(g[t][i][1]>0) printf("[%d %d %d]",t,i,g[t][i][1]);
            f[x][i] = (f[x][i] + 1ll * g[t][i][1] * fac[t - flag[x]] % MOD * fpow(sz[x], cnt - t - 1)) % MOD;
        }
    //	for(int i=0;i<=szx;++i)
    //		printf("<%d %d>",i,f[x][i]);
}
void get_flag_node(int x, int y) {
    while (x != y) {
        if (dep[x] < dep[y])
            swap(x, y);
        x = fa[x];
    }
    flag_node = x;
}
int dfs2(int x, int i) {
    if (x == flag_node)
        return f[x][i];
    if (son[x].empty())
        return 1;
    int ans = fpow(sz[x], (int)son[x].size() - 2);
    for (auto y : son[x]) ans = 1ll * ans * sz[y] % MOD * dfs2(y, i) % MOD;
    return ans;
}
int main() {
    //	freopen("plant.in","r",stdin);
    //	freopen("plant.out","w",stdout);
    scanf("%d", &n);
    vector<Res> a(n - 1);
    for (int i = 0; i < n - 1; ++i) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    build_tree(a, n);
    /*	for(int i=1;i<=top_node;++i){
                    printf("\n[%d]",i);
                    for(auto x:son[i]) printf("{%d}",x);
            }
    */
    scanf("%d%d", &u, &v);
    vis[u] = vis[v] = 1;
    dfs(top_node, 0);
    get_flag_node(u, v);
    //	printf("<%d>",flag_node);
    dfs1(flag_node);
    for (int i = 1; i <= n; ++i) printf("%d ", dfs2(top_node, i));
    return 0;
}
