#include <bits/stdc++.h>
#define LD double
#define LL long long
#define pb push_back
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;
const LL INF = 4e18;
const int inf = 1e9;
const LD PI = acos(-1.0);
LL M = 998244353;
// LL M=1000000007;
// LL M=1004535809;
// const LL P=998244353;
const int N = 1e6 + 100;
const LD eps = 1e-6;
const LD eps2 = 1e-10;

std::mt19937 rnd(time(0));

int rnd_int(int L, int R) {
    int x = rnd();
    // cout<<x<<endl;
    return (x % (R - L + 1) + R - L + 1) % (R - L + 1) + L;
}

struct edge {
    LL a, b;
    LL at(LL x) { return a * x + b; }
};

#define ls id << 1
#define rs id << 1 | 1
struct Seg {
    LL n;
    vector<edge> d;
    void init(LL n) {
        d.resize(n * 4);
        for (int i = 0; i < n * 4; ++i) {
            d[i].a = 0;
            d[i].b = -INF;
        }
    }
    void add_edge(int id, LL l, LL r, LL ql, LL qr, edge E) {
        if (ql > r || qr < l) {
            return;
        }
        if (l == r) {
            if (E.at(l) > d[id].at(l)) {
                swap(E, d[id]);
            }
            return;
        }
        int mid = (l + r) / 2;
        if (ql <= l && r <= qr) {
            if (E.at(mid) > d[id].at(mid)) {
                swap(E, d[id]);
            }
            if (E.at(l) <= d[id].at(l) && E.at(r) <= d[id].at(r)) {
                return;
            }
            if (E.at(l) > d[id].at(l)) {
                add_edge(ls, l, mid, ql, qr, E);
            }
            if (E.at(r) > d[id].at(r)) {
                add_edge(rs, mid + 1, r, ql, qr, E);
            }
        } else {
            add_edge(ls, l, mid, ql, qr, E);
            add_edge(rs, mid + 1, r, ql, qr, E);
        }
        return;
    }
    LL ask(int id, LL l, LL r, LL ql) {
        if (ql < l || ql > r) {
            return -INF;
        }
        LL re = d[id].at(ql);
        if (l == r) {
            return re;
        }
        int mid = (l + r) / 2;
        re = max(re, ask(ls, l, mid, ql));
        re = max(re, ask(rs, mid + 1, r, ql));
        return re;
    }
} S[4];

int n, T;

struct date {
    LL id, l, r, a, b;
};
date dat[N];
vector<date> V[N];

int B = 0;
int dfn = 0;
int vis[N], F[N], Fe[N], fa[N], w[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int x) {
    //	cout<<x<<" "<<F[x]<<endl;
    vis[x] = ++dfn;
    for (auto ed : V[x]) {
        if (ed.id == Fe[x]) continue;

        if (vis[ed.r] == 0) {
            F[ed.r] = x;
            Fe[ed.r] = ed.id;
            dfs(ed.r);
        } else if (vis[ed.r] < vis[x]) {
            B++;
            w[ed.id] += B;
            int u = x;
            while (u != ed.r) {
                //            	cout<<"! "<<u<<" "<<ed.r<<endl;
                w[Fe[u]] += B;
                u = F[u];
            }
        }
    }
}

void MAIN() {
    int cnt = 0, whatever;
    cin >> n >> T;
    LL AA = 0, BB = 0;
    for (int i = 1; i <= n + 1; ++i) {
        LL u, v, a, b;
        cin >> u >> v >> a >> b;
        AA += a;
        BB += b;
        V[u].push_back(date {(LL)i, u, v, a, b});
        V[v].push_back(date {(LL)i, v, u, a, b});
        dat[i] = date {(LL)i, u, v, a, b};
    }
    //    cout<<"? "<<endl;
    Fe[1] = F[1] = 0;
    dfs(1);
    //    cout<<"??"<<endl;
    for (int i = 1; i <= 3; ++i) {
        S[i].init(T);
    }
    int cols = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (w[i] > 0) {
            S[w[i]].add_edge(1, 0, T, 0, T, edge {dat[i].a, dat[i].b});
            cols = max(cols, w[i]);
        }
    }
    LL ans, re[5];
    for (LL i = 0; i <= T; ++i) {
        ans = AA * i + BB;
        if (cols == 2) {
            re[1] = S[1].ask(1, 0, T, i);
            re[2] = S[2].ask(1, 0, T, i);
            ans -= re[1] + re[2];
        } else {
            re[1] = S[1].ask(1, 0, T, i);
            re[2] = S[2].ask(1, 0, T, i);
            re[3] = S[3].ask(1, 0, T, i);
            ans -= re[1] + re[2] + re[3];
            ans += min(re[1], min(re[2], re[3]));
        }
        cout << ans << "\n";
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    // init();
    // init_pri();
    // initS2();

    int ttt = 1;
    // cin >> ttt;
    for (int i = 1; i <= ttt; ++i) {
        // printf("Case %d: ",i);
        // printf("Case #%d: ",i);
        MAIN();
    }
    return 0;
}
/*
5 3
1 2 3 1
1 3 1 2
2 3 1 3
3 4 1 1
3 5 1 2
4 5 1 3

6
12
16
20
*/
