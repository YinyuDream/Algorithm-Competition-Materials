#include<bits/stdc++.h>
#define N 6009
using namespace std;
typedef long long ll;
int n, q, a[N], siz[N], tot, head[N], f[N];
ll dp[N][3009], g[N], val[N];
struct node {
    int u, v, w;
    inline bool operator <(const node& b)const {
        return w < b.w;
    }
} b[N];
struct edge {
    int n, to;
} e[N << 1];

inline void add(int u, int v) {
    e[++tot].n = head[u];
    e[tot].to = v;
    head[u] = tot;
}
int find(int x) {
    return f[x] = f[x] == x ? x : find(f[x]);
}
void dfs(int u) {
    siz[u] = (u <= n);
    if (u <= n) {
        dp[u][a[u]] = 0;
        dp[u][a[u] ^ 1] = -val[u];
    }

    for (int i = head[u]; i; i = e[i].n) {
        int v = e[i].to;
        dfs(v);
        for (int j = 0; j <= siz[u] + siz[v]; ++j)g[j] = -1e9;
        for (int j = 0; j <= siz[u]; ++j)
            for (int k = 0; k <= siz[v]; ++k) {
                g[j + k] = max(g[j + k],
                               dp[u][j] + dp[v][k] + 1ll * val[u] * (j * (siz[v] - k) + k * (siz[u] - j)));
            }
        siz[u] += siz[v];
        for (int j = 0; j <= siz[u]; ++j)dp[u][j] = g[j];

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for (int i = 1; i <= n * 2; ++i)f[i] = i;
    for (int i = 1; i < n; ++i) {
        cin >> b[i].u >> b[i].v >> b[i].w;
    }
    sort(b + 1, b + n);
    for (int i = 1; i < n; ++i) {
        int xx = find(b[i].u), yy = find(b[i].v);
        f[xx] = i + n;
        f[yy] = i + n;
        val[i + n] = b[i].w;
        add(i + n, xx);
        add(i + n, yy);
    }
    dfs(2 * n - 1);
    ll ans = -1e9;
    for (int i = 0; i <= n; ++i)ans = max(ans, dp[2 * n - 1][i]);
    cout << ans;
    return 0;
}
