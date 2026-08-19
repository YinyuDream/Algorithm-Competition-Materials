#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;

const double EPS = 1e-9;
const double INF = 1e20;

inline int sgn(double x) {
    if (fabs(x) < EPS) return 0;
    return x > 0 ? 1 : -1;
}

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x_, double y_) : x(x_), y(y_) {}
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    double dot(const Point& p) const { return x * p.x + y * p.y; }
    double cross(const Point& p) const { return x * p.y - y * p.x; }
    double len2() const { return x * x + y * y; }
    double len() const { return sqrt(len2()); }
    Point normalize() const { double l = len(); return Point(x / l, y / l); }
    bool operator==(const Point& p) const { return sgn(x - p.x) == 0 && sgn(y - p.y) == 0; }
};

typedef vector<Point> Polygon;
typedef vector<Polygon> PolygonSet;

// 多边形方向: 逆时针返回>0
double polygonArea(const Polygon& poly) {
    double area = 0;
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        area += poly[i].cross(poly[(i + 1) % n]);
    }
    return area / 2;
}

// 保证逆时针
void makeCCW(Polygon& poly) {
    if (polygonArea(poly) < 0) reverse(poly.begin(), poly.end());
}

// 点是否在凸多边形内部（包括边界）
bool pointInConvex(const Point& p, const Polygon& poly) {
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        const Point& a = poly[i];
        const Point& b = poly[(i + 1) % n];
        double cross = (b - a).cross(p - a);
        if (cross < -EPS) return false;
    }
    return true;
}

// 点到凸多边形最近距离（若点在内部，返回指向外部的向量）
Point closestPointOnConvex(const Point& p, const Polygon& poly, bool& inside) {
    int n = poly.size();
    inside = pointInConvex(p, poly);
    double bestDist2 = INF;
    Point bestPoint;
    // 边
    for (int i = 0; i < n; ++i) {
        const Point& a = poly[i];
        const Point& b = poly[(i + 1) % n];
        Point ab = b - a;
        double t = (p - a).dot(ab) / ab.len2();
        Point q;
        if (t <= 0) q = a;
        else if (t >= 1) q = b;
        else q = a + ab * t;
        double d2 = (q - p).len2();
        if (d2 < bestDist2) {
            bestDist2 = d2;
            bestPoint = q;
        }
    }
    // 顶点
    for (int i = 0; i < n; ++i) {
        double d2 = (poly[i] - p).len2();
        if (d2 < bestDist2) {
            bestDist2 = d2;
            bestPoint = poly[i];
        }
    }
    return bestPoint - p;
}

// 凸包 (Andrew算法)
Polygon convexHull(vector<Point> pts) {
    if (pts.size() <= 1) return pts;
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
    });
    vector<Point> hull;
    for (int step = 0; step < 2; ++step) {
        int start = hull.size();
        for (auto& p : pts) {
            while (hull.size() >= start + 2 && sgn((hull.back() - hull[hull.size()-2]).cross(p - hull.back())) <= 0)
                hull.pop_back();
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(pts.begin(), pts.end());
    }
    return hull;
}

// 两个凸多边形的Minkowski和 (凸)
Polygon convexMinkowskiSum(const Polygon& A, const Polygon& B) {
    vector<Point> pts;
    for (auto& a : A)
        for (auto& b : B)
            pts.push_back(a + b);
    return convexHull(pts);
}

// 耳剪裁三角剖分 (返回三角形列表，每个三角形逆时针)
vector<Polygon> triangulate(const Polygon& poly) {
    vector<Polygon> tris;
    int n = poly.size();
    if (n < 3) return tris;
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;
    auto isEar = [&](int i, int j, int k) {
        const Point& pi = poly[indices[i]];
        const Point& pj = poly[indices[j]];
        const Point& pk = poly[indices[k]];
        // 检查是否为凸顶点
        if (sgn((pj - pi).cross(pk - pj)) <= 0) return false;
        // 检查其他顶点是否在三角形内
        for (int t = 0; t < n; ++t) {
            if (t == i || t == j || t == k) continue;
            const Point& pt = poly[indices[t]];
            double d1 = (pj - pi).cross(pt - pi);
            double d2 = (pk - pj).cross(pt - pj);
            double d3 = (pi - pk).cross(pt - pk);
            if (sgn(d1) >= 0 && sgn(d2) >= 0 && sgn(d3) >= 0) return false;
        }
        return true;
    };
    int cnt = n;
    while (cnt > 3) {
        bool found = false;
        for (int i = 0; i < cnt; ++i) {
            int j = (i + 1) % cnt;
            int k = (i + 2) % cnt;
            if (isEar(i, j, k)) {
                tris.push_back({poly[indices[i]], poly[indices[j]], poly[indices[k]]});
                indices.erase(indices.begin() + j);
                cnt--;
                found = true;
                break;
            }
        }
        if (!found) break; // 理论上有耳
    }
    tris.push_back({poly[indices[0]], poly[indices[1]], poly[indices[2]]});
    for (auto& tri : tris) makeCCW(tri);
    return tris;
}

// 合并相邻三角形为凸多边形 (贪心)
void mergeTriangles(vector<Polygon>& convexParts) {
    bool merged = true;
    while (merged) {
        merged = false;
        for (size_t i = 0; i < convexParts.size(); ++i) {
            for (size_t j = i + 1; j < convexParts.size(); ++j) {
                // 检查两个凸多边形是否共享一条边
                bool shareEdge = false;
                Polygon mergedPoly;
                // 简单合并: 取并集的凸包
                vector<Point> allPts;
                for (auto& p : convexParts[i]) allPts.push_back(p);
                for (auto& p : convexParts[j]) allPts.push_back(p);
                Polygon hull = convexHull(allPts);
                // 检查合并后是否凸且面积接近
                double areaSum = polygonArea(convexParts[i]) + polygonArea(convexParts[j]);
                if (sgn(polygonArea(hull) - areaSum) == 0 && hull.size() == allPts.size()) {
                    // 可以合并
                    convexParts[i] = hull;
                    convexParts.erase(convexParts.begin() + j);
                    merged = true;
                    break;
                }
            }
            if (merged) break;
        }
    }
}

// 分解多边形为凸多边形集
vector<Polygon> decomposeToConvex(const Polygon& poly) {
    auto tris = triangulate(poly);
    vector<Polygon> convexParts;
    for (auto& tri : tris) convexParts.push_back(tri);
    mergeTriangles(convexParts);
    return convexParts;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(5);

    // 初始化
    int nA, nB;
    cin >> nA >> nB;
    Polygon A(nA), B(nB);
    for (int i = 0; i < nA; ++i) cin >> A[i].x >> A[i].y;
    for (int i = 0; i < nB; ++i) cin >> B[i].x >> B[i].y;
    string ok;
    cin >> ok; // 读入 OK
    makeCCW(A);
    makeCCW(B);

    // 凸分解
    vector<Polygon> convexA = decomposeToConvex(A);
    vector<Polygon> convexB = decomposeToConvex(B);
    // 对 convexB 取反 ( -B )
    for (auto& poly : convexB) {
        for (auto& p : poly) p = p * (-1);
        makeCCW(poly); // 取反后方向会反转，重新调整为逆时针
    }

    // 计算 Minkowski 和凸多边形列表
    vector<Polygon> MList;
    for (auto& ca : convexA) {
        for (auto& cb : convexB) {
            Polygon sum = convexMinkowskiSum(ca, cb);
            if (sum.size() >= 3) MList.push_back(sum);
        }
    }

    // 预处理完成
    cout << "OK" << endl;

    // 读入测试样本点数
    int K;
    cin >> K;
    vector<Point> deltas(K);
    for (int i = 0; i < K; ++i) {
        cin >> deltas[i].x >> deltas[i].y;
    }

    // 处理每个测试点
    vector<Point> results;
    for (const Point& delta : deltas) {
        // 判断是否重叠: 是否存在凸多边形包含delta（严格内部）
        bool overlap = false;
        for (auto& poly : MList) {
            if (pointInConvex(delta, poly)) {
                // 需要排除边界情况: 边界上不算重叠
                // 检查是否在内部（不在边界上）
                bool onBoundary = false;
                int n = poly.size();
                for (int i = 0; i < n; ++i) {
                    const Point& a = poly[i];
                    const Point& b = poly[(i+1)%n];
                    double cross = (b-a).cross(delta-a);
                    if (sgn(cross) == 0) {
                        double dot = (delta-a).dot(b-a);
                        if (sgn(dot) >= 0 && sgn(dot - (b-a).len2()) <= 0) {
                            onBoundary = true;
                            break;
                        }
                    }
                }
                if (!onBoundary) {
                    overlap = true;
                    break;
                }
            }
        }
        if (!overlap) {
            results.emplace_back(0, 0);
            continue;
        }

        // 收集候选分离向量
        vector<Point> candidates;
        for (auto& poly : MList) {
            if (pointInConvex(delta, poly)) {
                bool inside;
                Point v = closestPointOnConvex(delta, poly, inside);
                if (inside) candidates.push_back(v);
            }
        }
        // 按长度排序
        sort(candidates.begin(), candidates.end(), [](const Point& a, const Point& b) {
            return a.len2() < b.len2();
        });
        // 依次验证可行性
        Point best;
        for (auto& v : candidates) {
            Point newPos = delta + v;
            bool valid = true;
            for (auto& poly : MList) {
                if (pointInConvex(newPos, poly)) {
                    // 边界允许
                    bool onBoundary = false;
                    int n = poly.size();
                    for (int i = 0; i < n; ++i) {
                        const Point& a = poly[i];
                        const Point& b = poly[(i+1)%n];
                        double cross = (b-a).cross(newPos-a);
                        if (sgn(cross) == 0) {
                            double dot = (newPos-a).dot(b-a);
                            if (sgn(dot) >= 0 && sgn(dot - (b-a).len2()) <= 0) {
                                onBoundary = true;
                                break;
                            }
                        }
                    }
                    if (!onBoundary) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
                best = v;
                break;
            }
        }
        results.push_back(best);
    }

    // 输出结果
    cout << results.size() << "\n";
    for (auto& v : results) {
        cout << v.x << " " << v.y << "\n";
    }
    cout << "OK" << endl;

    return 0;
}