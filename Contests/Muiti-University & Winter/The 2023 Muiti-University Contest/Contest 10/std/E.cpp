#include <bits/stdc++.h>
using namespace std;

using LD = long double;
using LL = long long;

const int N = 50005;
const LD pi = acos(-1.L);
const LD eps = 1e-10L;

template<typename T>
constexpr int sgn(T x) { return (x > eps) - (x < -eps); }

template<typename T>
constexpr T sqr(T x) { return x * x; }

struct Func {
    // f(x) = a*sin(x) + b*cos(x) + r
    int a, b, r;
    constexpr Func operator+(Func f) const {
        return {a + f.a, b + f.b, r + f.r};
    }
    constexpr Func operator-(Func f) const {
        return {a - f.a, b - f.b, r - f.r};
    }
    constexpr bool operator!=(Func f) const {
        return a != f.a || b != f.b || r != f.r;
    }
    
    constexpr Func trans180() const {
        // f(x + π) = -a*sin(x) - b*cos(x) + r
        return {-a, -b, r};
    }
    constexpr Func trans90() const {
        // f(x + π/2) = a*cos(x) - b*sin(x) + r
        return {-b, a, r};
    }

    LD eval(LD x) {
        return sin(x) * a + cos(x) * b + r;
    }
};
Func f[N];

struct Interval {
    LD lo, hi;
    Func f;
};

vector<Interval> calc(Func p, Func q, LD l, LD r) {
    if (sgn(r - l) <= 0) return {};
    // calculate intervals of max(*p(x), *q(x)) for x ∈ [l, r].
    Func delta = p - q;
    if (!delta.a && !delta.b) {
        if (delta.r >= 0) return {{l, r, p}};
        else return {{l, r, q}};
    }
    LD t = -LD(delta.r) / sqrt(sqr(LL(delta.a)) + sqr(LL(delta.b)));
    if (t >= 1) return {{l, r, q}};
    if (t <= -1) return {{l, r, p}};
    
    // sin(x + phi) = t
    LD phi = atan2l(delta.b, delta.a);
    auto adjust = [](LD x) {
        if (x < 0) return x + pi*2;
        if (x >= pi*2) return x - pi*2;
        return x;
    };
    LD x1, x2;
    if (t >= 0) {
        x1 = asin(t);
        x2 = pi - x1;
    } else {
        x1 = pi + asin(-t);
        x2 = 3*pi - x1;
    }
    x1 = adjust(x1 - phi);
    x2 = adjust(x2 - phi);
    if (x1 > x2) swap(x1, x2);

    vector<Interval> vec;
    if (p.eval((x1 + x2)/ 2) < q.eval((x1 + x2) / 2)) {
        vec = {{0.L, x1, p}, {x1, x2, q}, {x2, pi*2, p}};
    } else {
        vec = {{0.L, x1, q}, {x1, x2, p}, {x2, pi*2, q}};
    }

    vector<Interval> ret;
    for (auto [lo, hi, f] : vec) {
        lo = max(lo, l);
        hi = min(hi, r);
        if (sgn(hi - lo) <= 0) continue;
        ret.push_back({lo, hi, f});
    }
    return ret;
}

vector<Interval> merge(const vector<Interval>& v1, const vector<Interval>& v2) {
    auto i = v1.begin(), j = v2.begin();
    LD cur = 0;
    vector<Interval> ret;
    while (i != v1.end() && j != v2.end()) {
        vector<Interval> tmp;
        if (i->hi < j->hi) {
            tmp = calc(i->f, j->f, cur, i->hi);
            cur = i->hi;
            ++i;
        } else {
            tmp = calc(i->f, j->f, cur, j->hi);
            cur = j->hi;
            ++j;
        }
        for (auto t : tmp) ret.push_back(t);
    }
    vector<Interval> r;
    LD cur_lo = 0;
    for (int i = 0; i < (int)ret.size(); i++) {
        if (i + 1 == (int)ret.size() || ret[i + 1].f != ret[i].f)
            r.push_back({cur_lo, ret[i].hi, ret[i].f}),
            cur_lo = ret[i].hi;
    }
    return r;
}
vector<Interval> divide(int l, int r) {
    if (l == r) return {{0, 2*pi, f[l]}};
    int m = (l + r) / 2;
    auto vl = divide(l, m);
    auto vr = divide(m + 1, r);
    return merge(vl, vr);
}

LD getmin(Func p, Func q, LD l, LD r) {
    if (sgn(r - l) <= 0) return max(p.eval(l), q.eval(l));
    auto vec = calc(p, q, l, r);
    LD ret = 1e10;
    for (auto [lo, hi, f] : vec) {
        ret = min(ret, f.eval(lo));
        ret = min(ret, f.eval(hi));
        LD phi = atan2l(f.b, f.a);
        // f(x) = Asin(x + phi) + r
        lo += phi, hi += phi;
        if (lo <= -pi/2 && -pi/2 <= hi) ret = min(ret, f.eval(-pi/2 - phi));
        if (lo <= pi/2 && pi/2 <= hi) ret = min(ret, f.eval(pi/2 - phi));
        if (lo <= pi*3/2 && pi*3/2 <= hi) ret = min(ret, f.eval(pi*3/2 - phi));
    }
    return ret;
}

int n;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1, x, y, r; i <= n; i++) {
        cin >> x >> y >> r;
        f[i] = {y, x, r};
    }
    auto vec = divide(1, n);
    
    auto cut_intervals = [&](LD l, LD r){
        vector<Interval> ret;
        for (auto it = vec.begin(); it != vec.end(); it++) {
            auto [lo, hi, f] = *it;
            if (hi <= l) continue;
            if (lo >= r) break;
            ret.push_back({max(lo, l) - l, min(hi, r) - l, f});
        }
        return ret;
    };
    vector<Interval> v[4] = {cut_intervals(0, pi / 2),
                             cut_intervals(pi / 2, pi),
                             cut_intervals(pi, pi * 3 / 2),
                             cut_intervals(pi * 3 / 2, pi * 2)};
    vector<Interval>::iterator iter[4] = {v[0].begin(), v[1].begin(),
                                          v[2].begin(), v[3].begin()};

    vector<pair<LD, int>> events;
    for (int i = 0; i < 4; i++) {
        for (auto [lo, hi, f]: v[i]) {
            events.push_back({hi, i});
        }
    }
    sort(events.begin(), events.end());
    LD ans = 1e10;
    LD cur_lo = 0;
    for (auto [hi, i] : events) {
        auto f1 = (*iter[0]).f + (*iter[2]).f.trans180();
        auto f2 = (*iter[1]).f.trans90() + (*iter[3]).f.trans90().trans180();
        ans = min(ans, getmin(f1, f2, cur_lo, hi));
        cur_lo = hi;
        if (++iter[i] == v[i].end())
            break;
    }
    
    cout << setiosflags(ios::fixed) << setprecision(10) << ans << endl;
    return 0;
}