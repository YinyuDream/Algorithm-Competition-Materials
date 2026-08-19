#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;
using ll = long long;
using ld = long double;

i128 abs(i128 x) { return x < 0 ? -x : x; }

struct Rational {
    i128 p, q;
    void reduce() {
        auto g = __gcd(abs(p), abs(q));
        p /= g, q /= g;
    }
    Rational operator+(const Rational& o) const {
        Rational ret{p * o.q + o.p * q, q * o.q};
        ret.reduce();
        return ret;
    }
    Rational operator-(const Rational& o) const {
        Rational ret{p * o.q - o.p * q, q * o.q};
        ret.reduce();
        return ret;
    }
    Rational operator*(const Rational& o) const {
        Rational ret{p * o.p, q * o.q};
        ret.reduce();
        return ret;
    }
    Rational operator/(const Rational& o) const {
        Rational ret{p * o.q, q * o.p};
        if (ret.q < 0) { ret.p = -ret.p; ret.q = -ret.q; }
        ret.reduce();
        return ret;
    }
    bool operator==(const Rational& o) const {
        return p == o.p && q == o.q;
    }
    bool operator<(const Rational& o) const {
        return p * o.q < o.p * q;
    }

    static Rational new_int(ll x) {
        return Rational{x, 1};
    }

    long double eval() const {
        return ld(p) / ld(q);
    }
};

Rational cur_x;
const Rational kNan = Rational{0, 0};
const Rational kOne = Rational{1, 1};
const Rational kHalf = Rational{1, 2};

struct Point {
    Rational x, y;
    int id;
    bool operator==(const Point& o) const {
        return x == o.x && y == o.y;
    }
    bool operator<(const Point& o) const {
        if (x < o.x) return true;
        if (x == o.x && y < o.y) return true;
        return false;
    }
};

struct Edge {
    Point s, t;
    int id;
    Rational get_y() const {
        return get_y_by(cur_x);
    }
    Rational get_y_unwrap() const {
        auto ret = get_y();
        if (ret == kNan) {
            return (s.y + t.y) * kHalf;
        }
        return ret;
    }

    Rational get_y_by(const Rational& x) const {
        if (s.x == t.x) return kNan;
        else {
            // k * s.x + (1 - k) * t.x == x
            Rational k = (x - t.x) / (s.x - t.x);
            return k * s.y + (kOne - k) * t.y;
        }
    }

    bool operator<(const Edge& o) const {
        if (id == o.id) return false;
        if (s == o.s) {
            auto sy = get_y_by(o.t.x);
            if (sy == kNan) {
                return false;
            }
            return sy < o.t.y;
        }
        if (t == o.t) {
            auto sy = get_y_by(o.s.x);
            if (sy == kNan) {
                return true;
            }
            return sy < o.s.y;
        }
        return get_y_unwrap() < o.get_y_unwrap();
    }

    bool operator==(const Edge& o) const {
        return id == o.id;
    }
};

int compare_edge_point(const Edge& e, const Point& p) {
    auto y = e.get_y();
    if (y == kNan) {
        if (p.y < e.s.y) {
            return 1;
        } else if (e.t.y < p.y) {
            return -1;
        } else return 0;
    } else if (y < p.y) {
        return -1;
    } else if (p.y < y) {
        return 1;
    } else return 0;
}
struct EdgeOrPoint {
    int type; // 0: Edge, 1: Point
    void* ptr;
    bool operator<(const EdgeOrPoint& o) const {
        if (type == 0) { // Edge
            auto e = *((Edge*) ptr);
            if (o.type == 0) { // Edge
                return e < *((Edge*) o.ptr);
            } else { // Point
                return compare_edge_point(e, *((Point*) o.ptr)) == -1;
            }
        } else { // Point
            auto e = *((Point*) ptr);
            if (o.type == 0) { // Edge
                assert(false);
                return compare_edge_point(*((Edge*) o.ptr), e) == 1;
            } else {
                assert(false);
            }
        }
    }
};

const int N = 400005;
const int kRoot = 1;

int n, m, tot_n;
Point p[N];
Edge e[N];

vector<int> point_on_edges[N];
pair<int, int> route[N];

struct Event {
    int type; // 0: remove, 1: add, 2: query
    int id;
    
    Point get_point() const {
        if (type == 0) return e[id].t;
        else if (type == 1) return e[id].s;
        else if (type == 2) return p[id];
        assert(false);
    }
    bool operator<(const Event& o) const {
        return make_pair(get_point(), type) < make_pair(o.get_point(), o.type);
    }
};

vector<int> G[N];
int ancestor[N][20], dep[N];
void dfs(int u, int fa) {
    ancestor[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (auto v : G[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int j = __lg(tot_n); j >= 0; j--) {
        if (dep[ancestor[u][j]] >= dep[v]) {
            u = ancestor[u][j];
        }
    }
    if (u == v) return u;
    for (int j = __lg(tot_n); j >= 0; j--) {
        if (ancestor[u][j] != ancestor[v][j]) {
            u = ancestor[u][j];
            v = ancestor[v][j];
        }
    }
    return ancestor[u][0];
}

int ptag[N], stag[N], psum[N], ssum[N], lca_cnt[N];
void dp(int u, int fa) {
    ssum[u] = stag[u];
    psum[u] += ptag[u];
    for (auto v : G[u]) {
        if (v == fa) continue;
        psum[v] = psum[u];
        dp(v, u);
        ssum[u] += ssum[v];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    tot_n = n;
    map<Point, int> indices;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        p[i] = Point{Rational::new_int(x), Rational::new_int(y), i};
        indices.insert({p[i], i});
    }

    vector<Event> events;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (p[u] < p[v]) {
            e[i] = Edge{p[u], p[v], i};
            events.push_back(Event{1, i});
            events.push_back(Event{0, i});
        } else {
            e[i] = Edge{p[v], p[u], i};
            events.push_back(Event{1, i});
            events.push_back(Event{0, i});
        }
    }
    auto fuckp = Point { Rational{-508505, 1}, Rational{44537978998, 89129}, 1 };

    for (int i = 1; i <= m; i++) {
        auto read_one = [&]() {
            ll px, qx, py, qy;
            cin >> px >> qx >> py >> qy;
            Point pt = Point{Rational{px, qx}, Rational{py, qy}, tot_n + 1};
            auto it = indices.find(pt);

            if (it == indices.end()) {
                tot_n++;
                p[tot_n] = pt;
                indices.insert({pt, tot_n});
                events.push_back(Event{2, tot_n});

                return tot_n;
            } else {
                return it->second;
            }
        };
        auto u = read_one();
        auto v = read_one();
        route[i] = {u, v};
    }

    sort(events.begin(), events.end());

    set<EdgeOrPoint> current_edges;
    for (auto event: events) {
        cur_x = event.get_point().x;
        if (event.type == 0) {
            current_edges.erase(EdgeOrPoint{0, (void*)(&e[event.id])});
        } else if (event.type == 1) {
            auto [it, ok] = current_edges.insert(EdgeOrPoint{0, (void*)(&e[event.id])});
        } else if (event.type == 2) {
            auto it = current_edges.lower_bound(EdgeOrPoint{1, (void*)(&p[event.id])});
            assert(it != current_edges.end());
            auto edge = *((Edge*) it->ptr);
            assert(compare_edge_point(edge, p[event.id]) == 0);

            point_on_edges[edge.id].push_back(event.id);
        }
    }

    for (int i = 1; i < n; i++) {
        point_on_edges[i].push_back(e[i].t.id);
        auto cur = e[i].s.id;
        for (auto u : point_on_edges[i]) {
            G[u].push_back(cur);
            G[cur].push_back(u);
            cur = u;
        }
    }

    auto log_n = __lg(tot_n);
    dfs(kRoot, kRoot);
    for (int j = 1; j <= log_n; j++) {
        for (int i = 1; i <= tot_n; i++) {
            ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= m; i++) {
        auto [u, v] = route[i];
        auto w = lca(u, v);
        lca_cnt[w] += 1;

        stag[u] += 1, stag[v] += 1;
        stag[w] -= 1;
        if (w != kRoot) stag[ancestor[w][0]] -= 1;

        ptag[w] += 1;
    }

    dp(kRoot, kRoot);
    
    for (int i = 1; i <= m; i++) {
        auto [u, v] = route[i];
        auto w = lca(u, v);
        auto lca_in_others = ssum[w];
        auto other_lca_in_self = psum[u] + psum[v] - psum[w];
        if (w != kRoot) other_lca_in_self -= psum[ancestor[w][0]];

        auto ans = lca_in_others + other_lca_in_self - lca_cnt[w] - 1;

        cout << ans << ' ';
    }
    return 0;
}