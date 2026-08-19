#include <iostream>
#include <string>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        // 最小可能长度 ceil(n/122)，最大可能长度 floor(n/97)
        int L = (n + 121) / 122;  // 向上取整
        int R = n / 97;           // 向下取整
        // 判断是否存在长度 k 满足 97k <= n <= 122k
        if (n < 97 || L > R) {
            cout << "No\n";
        } else {
            int k = L;                // 选择最小的可能长度，使构造的字符串尽可能短
            int rem = n - 97 * k;     // 需要在 97k 的基础上增加的总和
            int full_z = rem / 25;    // 可以完全增加为 'z' 的个数
            int remainder = rem % 25; // 剩余不足 25 的部分
            int rest_a = k - full_z - (remainder > 0 ? 1 : 0);
            
            string s;
            s.reserve(k);
            if (full_z > 0) s.append(full_z, 'z');
            if (remainder > 0) s.push_back('a' + remainder);
            if (rest_a > 0) s.append(rest_a, 'a');
            
            cout << "Yes\n" << s << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}