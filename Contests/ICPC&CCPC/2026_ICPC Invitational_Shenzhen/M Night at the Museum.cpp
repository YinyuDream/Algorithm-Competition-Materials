#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    double len() const {
        return sqrt(x * x + y * y);
    }
    double dot(const Point& other) const {
        return x * other.x + y * other.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, r, a_deg;
    cin >> n >> m >> r >> a_deg;
    
    double a_rad = a_deg * PI / 180.0;
    double sin_a = sin(a_rad);
    double cos_a = cos(a_rad);
    double cot_a = cos_a / sin_a;   // a_deg ∈ (0,90) ⇒ sin_a > 0
    
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }
    pts.push_back(pts[0]); // 方便取边
    
    vector<Point> exhibits(m);
    for (int i = 0; i < m; ++i) {
        cin >> exhibits[i].x >> exhibits[i].y;
    }
    
    vector<double> ans(m + 1, 0.0);
    
    for (int i = 0; i < n; ++i) {
        Point A = pts[i];
        Point B = pts[i + 1];
        Point d = B - A;
        double L = d.len();
        if (L < eps) continue;   // 输入保证相邻点不重合
        
        Point u = Point(d.x / L, d.y / L);   // 前进方向的单位向量
        
        vector<pair<double, int>> events;
        for (const Point& Q : exhibits) {
            Point v = Q - A;
            double S = v.dot(u);
            double D2 = v.dot(v) - S * S;
            if (D2 < 0) D2 = 0;
            double D = sqrt(D2);
            if (D > r + eps) continue;      // 直线与圆无交
            
            double sqrt_term = sqrt(max(0.0, r * r - D * D));
            double t1 = S - sqrt_term;
            double t2 = S + sqrt_term;
            double t_ang = S - D * cot_a;
            
            double Lc = max(0.0, t1);
            double Rc = min({L, t2, t_ang});
            if (Rc > Lc + eps) {
                events.emplace_back(Lc, 1);
                events.emplace_back(Rc, -1);
            }
        }
        
        if (events.empty()) {
            ans[0] += L;
            continue;
        }
        
        sort(events.begin(), events.end(),
             [](const pair<double,int>& a, const pair<double,int>& b) {
                 return a.first < b.first;
             });
        
        double prev = 0.0;
        int cur = 0;
        for (size_t j = 0; j < events.size(); ) {
            double pos = events[j].first;
            if (pos > prev + eps) {
                ans[cur] += pos - prev;
                prev = pos;
            }
            int delta = 0;
            while (j < events.size() && fabs(events[j].first - pos) <= eps) {
                delta += events[j].second;
                ++j;
            }
            cur += delta;
        }
        if (L > prev + eps) {
            ans[cur] += L - prev;
        }
    }
    
    cout << fixed << setprecision(10);
    for (int k = 0; k <= m; ++k) {
        cout << ans[k] << "\n";
    }
    
    return 0;
}