#include <bits/stdc++.h>
using namespace std;
#define debug(fmt, ...) \
  fprintf(stderr, "[%d] : " fmt "\n", __LINE__, ##__VA_ARGS__)
bool Mbe;
using ll = long long;
constexpr int N = 5e4 + 10, Q = 1e5 + 10, S = 10;
int n, q, a[N], sz[N], mx[N], bel[N], qu[Q], qv[Q];
bool vis[N];
string str;
vector<int> g[N], qprf[N], qsuf[N];
struct dat {
  int8_t val, sum[S];
  dat() { val = 0, fill(sum, sum + S, -1); }
  void flush() {
    int msk = 0;
    for (int i = 0; i < S; ++i)
      if (~sum[i]) msk |= 1 << sum[i];
    val = __builtin_ctz(~msk);
  }
  void add_xor(int i, int x) {
    if (sum[i] == -1) sum[i] = 0;
    sum[i] ^= x;
  }
};
struct info_t {
  int len, lp[S], ls[S];
  dat f, gp[S], gs[S];
  info_t() { len = 0, fill(lp, lp + S, -1), fill(ls, ls + S, -1); }
  int value() const { return f.val; }
  info_t append_prf(int c) const {
    info_t t = *this;
    for (int i = 0; i < S; ++i)
      if (~lp[i]) ++t.lp[i];
    ++t.len, t.gp[c] = dat(), t.lp[c] = 0;
    static int id[S];
    iota(id, id + S, 0);
    sort(id, id + S, [&](int p, int q) { return lp[p] < lp[q]; });
    for (int i = 0; i < S; ++i) {
      if (id[i] == c || lp[id[i]] == -1) continue;
      for (int j = 0; j < i; ++j) {
        if (id[j] == c || lp[id[j]] == -1) continue;
        t.gp[id[i]].add_xor(id[j], gp[id[j]].val ^ t.gp[id[j]].val);
      }
      if (lp[c] == -1 || lp[c] > lp[id[i]])
        t.gp[id[i]].add_xor(c, gp[id[i]].val);
      t.gp[id[i]].flush();
      t.f.add_xor(id[i], gp[id[i]].val ^ t.gp[id[i]].val);
    }
    if (lp[c] == -1) t.f.add_xor(c, f.val), t.gs[c] = f, t.ls[c] = len;
    t.f.flush();
    return t;
  }
  info_t append_suf(int c) const {
    info_t t = *this;
    for (int i = 0; i < S; ++i)
      if (~ls[i]) ++t.ls[i];
    ++t.len, t.gs[c] = dat(), t.ls[c] = 0;
    static int id[S];
    iota(id, id + S, 0);
    sort(id, id + S, [&](int p, int q) { return ls[p] < ls[q]; });
    for (int i = 0; i < S; ++i) {
      if (id[i] == c || ls[id[i]] == -1) continue;
      for (int j = 0; j < i; ++j) {
        if (id[j] == c || ls[id[j]] == -1) continue;
        t.gs[id[i]].add_xor(id[j], gs[id[j]].val ^ t.gs[id[j]].val);
      }
      if (ls[c] == -1 || ls[c] > ls[id[i]])
        t.gs[id[i]].add_xor(c, gs[id[i]].val);
      t.gs[id[i]].flush();
      t.f.add_xor(id[i], gs[id[i]].val ^ t.gs[id[i]].val);
    }
    if (ls[c] == -1) t.f.add_xor(c, f.val), t.gp[c] = f, t.lp[c] = len;
    t.f.flush();
    return t;
  }
  friend info_t unite(const info_t& p, const info_t& q) {
    info_t t;
    static dat h[S + 1][S + 1];
    static int idp[S + 1], idq[S + 1];
    iota(idp, idp + S + 1, 0), iota(idq, idq + S + 1, 0);
    sort(idp, idp + S, [&](int x, int y) { return p.ls[x] < p.ls[y]; });
    sort(idq, idq + S, [&](int x, int y) { return q.lp[x] < q.lp[y]; });
    for (int i = 0; i <= S; ++i) {
      for (int j = 0; j <= S; ++j) {
        int pi = idp[i], pj = idq[j];
        h[pi][pj] = dat();
        if (i != S && p.ls[pi] == -1) continue;
        if (j != S && q.lp[pj] == -1) continue;
        const dat& lft = (i == S) ? p.f : p.gs[pi];
        const dat& rht = (j == S) ? q.f : q.gp[pj];
        for (int k = 0; k < S; ++k) {
          bool chp = (p.ls[k] != -1 && (i == S || p.ls[k] < p.ls[pi]));
          bool chq = (q.lp[k] != -1 && (j == S || q.lp[k] < q.lp[pj]));
          if (chp && chq) {
            h[pi][pj].add_xor(k, lft.sum[k] ^ p.gs[k].val);
            h[pi][pj].add_xor(k, rht.sum[k] ^ q.gp[k].val);
            h[pi][pj].add_xor(k, h[k][k].val);
          } else if (chp) {
            h[pi][pj].add_xor(k, lft.sum[k] ^ p.gs[k].val);
            h[pi][pj].add_xor(k, h[k][pj].val);
          } else if (chq) {
            h[pi][pj].add_xor(k, rht.sum[k] ^ q.gp[k].val);
            h[pi][pj].add_xor(k, h[pi][k].val);
          }
        }
        h[pi][pj].flush();
      }
    }
    for (int i = 0; i < S; ++i) {
      if (p.lp[i] != -1) {
        t.lp[i] = p.lp[i], t.gp[i] = p.gp[i];
      } else if (q.lp[i] != -1) {
        t.lp[i] = p.len + q.lp[i], t.gp[i] = h[S][i];
      }
      if (q.ls[i] != -1) {
        t.ls[i] = q.ls[i], t.gs[i] = q.gs[i];
      } else if (p.ls[i] != -1) {
        t.ls[i] = p.ls[i] + q.len, t.gs[i] = h[i][S];
      }
    }
    t.len = p.len + q.len, t.f = h[S][S];
    return t;
  }
} prf[Q], suf[Q];
int root(int u, int pre, int num) {
  int p = 0;
  sz[u] = 1, mx[u] = 0;
  for (auto v : g[u]) {
    if (v == pre || vis[v]) continue;
    int t = root(v, u, num);
    sz[u] += sz[v], mx[u] = max(mx[u], sz[v]);
    if (!p || mx[t] < mx[p]) p = t;
  }
  mx[u] = max(mx[u], num - sz[u]);
  if (!p || mx[u] < mx[p]) p = u;
  return p;
}
void dfs_ins(int u, int pre, int x) {
  bel[u] = x;
  for (auto v : g[u]) {
    if (v == pre || vis[v]) continue;
    dfs_ins(v, u, x);
  }
}
void dfs_qprf(int u, int pre, info_t t) {
  t = t.append_prf(a[u]);
  for (auto it : qprf[u])
    if (bel[qv[it]] && bel[qv[it]] != bel[u])
      prf[it] = t;
  for (auto v : g[u])
    if (v != pre && !vis[v]) dfs_qprf(v, u, t);
}
void dfs_qsuf(int u, int pre, info_t t) {
  t = t.append_suf(a[u]);
  for (auto it : qsuf[u])
    if (bel[qu[it]] && bel[qu[it]] != bel[u])
      suf[it] = t;
  for (auto v : g[u])
    if (v != pre && !vis[v]) dfs_qsuf(v, u, t);
}
void solve(int u, int num) {
  vis[u] = 1;
  int cnt = 0;
  bel[u] = ++cnt;
  for (auto v : g[u])
    if (!vis[v]) dfs_ins(v, u, ++cnt);
  dfs_qprf(u, 0, info_t());
  for (auto v : g[u])
    if (!vis[v]) dfs_qsuf(v, u, info_t());
  dfs_ins(u, 0, 0);
  for (auto v : g[u]) {
    if (vis[v]) continue;
    int s = sz[u] > sz[v] ? sz[v] : num - sz[u];
    solve(root(v, u, s), s);
  }
}
bool Med;
int main() {
  // freopen("game.in", "r", stdin);
  // freopen("game.out", "w", stdout);
  // debug("Mem: %.4lfMB.", fabs(&Med - &Mbe) / 1048576);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q >> str;
  for (int i = 1; i <= n; ++i) a[i] = str[i - 1] - '0';
  for (int i = 1, u, v; i < n; ++i)
    cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
  for (int i = 1; i <= q; ++i) {
    cin >> qu[i] >> qv[i];
    qprf[qu[i]].push_back(i), qsuf[qv[i]].push_back(i);
  }
  solve(root(1, 0, n), n);
  for (int i = 1; i <= q; ++i) {
    if (qu[i] == qv[i]) {
      cout << "Alice 1\n";
    } else {
      info_t t = unite(prf[i], suf[i]);
      if (t.value()) {
        int num = 0;
        for (int j = 0; j < S; ++j)
          if (~t.ls[j] && !t.f.sum[j]) ++num;
        cout << "Alice" << ' ' << num << '\n';
      } else {
        cout << "Bob\n";
      }
    }
  }
  return 0;
}