#include <bits/stdc++.h>
#define int long long
using i64 = long long;
constexpr int N = 1e6 + 10, L = 20;
i64 ans[N];
int n, m, ts, dfn[N], dep[N], siz[N], st[L][N];
std::vector<int> G[N];
namespace cactus  {
	std::vector<int> T[N];
	int dfn[N], low[N], ts, num;
	std::vector<int> cir[N], stk;
	void tarjan(int u, int par) {
		dfn[u] = low[u] = ++ ts;
		stk.emplace_back(u);
		for(auto v : T[u]) if(v != par) {
			if(!dfn[v]) {
				tarjan(v, u);
				low[u] = std::min(low[u], low[v]);
				if(low[v] >= dfn[u]) {
					int x;
					num ++;
					do {
						x = stk.back();
						stk.pop_back();
						cir[num].emplace_back(x);
					}while(x != v);
					if(cir[num].size() != 1) {
						cir[num].emplace_back(u);
					} else{
						cir[num].clear();
						num --;
					}
				}
			} else {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
	}
}
void dfs(int u, int par) {
	st[0][ts] = par;
	dfn[u] = ++ ts; siz[u] = 1;
	for(auto v : G[u]) {
		dep[v] = dep[u] + 1;
		G[v].erase(find(G[v].begin(), G[v].end(), u));
		dfs(v, u);
		siz[u] += siz[v];
	}
} 
int merge(int u, int v) {
	return dep[u] < dep[v] ? u : v;
}
int lca(int u, int v) {
	if(u == v) return u;
	int l = dfn[u], r = dfn[v];
	if(l > r) std::swap(l, r);
	int k = std::__lg(r - l);
	return merge(st[k][l], st[k][r - (1 << k)]);
}
signed main() {
// 	freopen("in.txt", "r", stdin);
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	std::set<std::pair<int, int>> s;
	for(int i = 1; i < n; i ++) {
		int u, v;
		std::cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	std::vector<std::pair<int, int>> edge;
	for(int i = 0; i < m; i ++) {
		int u, v;
		std::cin >> u >> v;
		if(u > v) std::swap(u, v);
		assert(!s.count(std::make_pair(u, v)));
		assert(u != v);
		s.emplace(u, v);
		cactus::T[u].emplace_back(v);
		cactus::T[v].emplace_back(u);
		edge.emplace_back(u, v);
	}
	cactus::tarjan(1, 1);
	assert(m == n- 1 + cactus::num);
	dfs(1, 1);
	for(int i = 1; i < L; i ++) {
		for(int j = 1; j <= n - (1 << i); j ++) {
			st[i][j] = merge(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	static i64 f[N], g[N], h[N], up[N], ans[N];
	auto insubtree = [&] (int x, int y) {
		return dfn[x] <= dfn[y] && dfn[y] < dfn[x] + siz[x];
	};
	auto online = [&] (int x, int u, int v) {
		return insubtree(u, x) && insubtree(x, v);
	};
	auto onseg = [&] (int x, int u, int v) {
		int w = lca(u, v);
		return online(x, w, u) || online(x, w, v);
	};
	auto calc = [&] (int  u, int v, int o) {
		int w = lca(u, v);
		if(dfn[u] > dfn[v]) std::swap(u, v);
		if(u == w) {
			int x = *prev(std::upper_bound(G[u].begin(), G[u].end(), v, [&] (int x, int y) {
				return dfn[x] < dfn[y];
			}));
			g[x] += siz[v] * o;
			assert(insubtree(x, v));
		} else {
			f[w] += 1ll * siz[u] * siz[v] * o;
		}
	};
	for(auto [u, v] : edge) {
		calc(u, v, -1);
	}
	for(int i = 1; i <= cactus::num; i ++) {
		using cactus::cir;
		assert(cir[i].size() >= 3);
		int u = cir[i][0], v = cir[i][1], flag = 1;
		for(int j = 2; j < cir[i].size(); j ++) {
			int x = cir[i][j];
			if(onseg(x, u, v)) ;
			else if(onseg(u, x, v)) u = x;
			else if(onseg(v, x, u)) v = x;
			else {
				flag = 0;
				break;
			}
		}
		if(flag) calc(u, v, 1);
	}
	std::function<void(int, int)> dfs = [&] (int u, int par) {
		int cursiz = 1;
		up[u] = h[u] = 1;
		for(auto v : G[u]) {
			dfs(v, u);
			f[u] += f[v];
			g[u] += g[v];
			h[u] += up[v] * cursiz;
			h[u] += up[u] * siz[v];
			h[u] += h[v];
			up[u] += up[v] + siz[v];
			cursiz += siz[v];
			f[u] += g[v] * (siz[u] - siz[v]);
		}
		ans[u] += f[u];
		ans[u] += h[u];
		// std::cout << u <<":" << f[u] << ' ' << g[u] << ' ' << ans[u] << std::endl;
	};
	dfs(1, 1);
	for(int i = 1; i <= n; i ++) {
		std::cout << ans[i] << '\n';
	}
	return 0;
}