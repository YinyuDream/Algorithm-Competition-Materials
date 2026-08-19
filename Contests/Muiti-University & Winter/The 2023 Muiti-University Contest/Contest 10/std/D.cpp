#include <bits/stdc++.h>
using namespace std;

int n, m;
int calc_sg_even(int x, int y) {
    return (x + y) % 2;
}
int calc_sg_odd(int x, int mid, int y) {
    if (!mid) return calc_sg_even(x, y);
    if (x < y) swap(x, y);
    if (!y) return x % 2;
    if (y == 1) return x % 2 == 0 ? 3 : 2;
    return ((x + y) % 2) ^ 1;
}
int main() {
    cin >> n >> m;
    string s;
    int sg = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (m % 2 == 0) {
            int x = 0, y = 0;
            for (int j = 1; j <= m / 2; j++)
                x += s[j - 1] - '0';
            for (int j = m / 2 + 1; j <= m; j++)
                y += s[j - 1] - '0';
            sg ^= calc_sg_even(x, y);
        } else {
            int x = 0, y = 0, mid = s[m / 2] - '0';
            for (int j = 1; j <= m / 2; j++)
                x += s[j - 1] - '0';
            for (int j = m / 2 + 2; j <= m; j++)
                y += s[j - 1] - '0';
            sg ^= calc_sg_odd(x, mid, y);
        }
    }
    cout << (sg ? "Alice" : "Bob");
    return 0;
}