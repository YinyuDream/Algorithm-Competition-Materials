#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct Point {
    long long x, y;
    int id;  // 原始编号 1-based
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].id = i + 1;  // 编号从1开始
    }
 
    // 枚举所有无序点对作为直线
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int left = 0, right = 0;
            vector<int> left_ids, right_ids;
            long long dx = pts[j].x - pts[i].x;
            long long dy = pts[j].y - pts[i].y;
 
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                // 叉积判断方向
                long long cross = dx * (pts[k].y - pts[i].y) - dy * (pts[k].x - pts[i].x);
                if (cross > 0) {
                    ++left;
                    left_ids.push_back(pts[k].id);
                } else if (cross < 0) {
                    ++right;
                    right_ids.push_back(pts[k].id);
                }
                // 若共线则忽略（题目可能不会共线或我们不关心）
            }
 
            if (left >= 2 && right >= 2) {
                // 取左侧两个点
                vector<int> A = left_ids;
                A.resize(2);
                // 取右侧两个点
                vector<int> B = right_ids;
                B.resize(2);
                // 将直线上的两个点分别加入
                A.push_back(pts[i].id);
                B.push_back(pts[j].id);
                // 排序输出（编号顺序无强制要求，但通常从小到大）
                sort(A.begin(), A.end());
                sort(B.begin(), B.end());
 
                // 输出结果
                cout << "3 3\n";
                for (int idx = 0; idx < 3; ++idx) {
                    cout << A[idx] << (idx == 2 ? "\n" : " ");
                }
                for (int idx = 0; idx < 3; ++idx) {
                    cout << B[idx] << (idx == 2 ? "\n" : " ");
                }
                return 0;  // 找到一组即退出
            }
        }
    }
 
    // 理论上题目保证有解，不会执行到此
    cout << "0 0\n";
    return 0;
}