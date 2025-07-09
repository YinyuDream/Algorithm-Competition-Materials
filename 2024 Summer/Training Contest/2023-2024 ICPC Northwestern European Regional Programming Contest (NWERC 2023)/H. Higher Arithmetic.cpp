#include<bits/stdc++.h>
using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    int n1 = 0, n2 = 0;
    if (n == 1) {
        int a;
        std::cin >> a;
        std::cout << a;
    } else {
        std::vector<int> a;
        for (int i = 0; i < n; i++) {
            int tmp;
            std::cin >> tmp;
            if (tmp == 1) {
                n1 ++;
            } else if (tmp == 2) {
                n2 ++;
            } else {
                a.push_back(tmp);
            }
        }
        if (n1 == 0 && n2 == 0) {
            int len = a.size();
            for (int i = 0; i < len; i++) {
                std::cout << a[i];
                if (i != len - 1) {
                    std::cout << "*";
                }
            }
            return;
        }
        if (n1 == 2 && n2 == 1) {
            std::cout << "(1+2)*";
            int len = a.size();
            for (int i = 0; i < len; i++) {
                std::cout << "*" << a[i];
            }
            return;
        }
        std::sort(a.begin(), a.end());
        while (n2 > 0 && n1 > 0) {
            std::cout << "(1+2)*";
            n2 --;
            n1 --;
            if (n2 == 0 && n1 == 0) {
                break;
            } else {
                std::cout << "*";
            }
            if (n1 == 2 && n2 == 1) {
                std::cout << "(1+2)*";
                int len = a.size();
                for (int i = 0; i < len; i++) {
                    std::cout << "*" << a[i];
                }
                return;
            }
        }
        if (n1 == 0) {
            while (n2--) {
                std::cout << "2";
                if (n2 != 0) {
                    std::cout << "*";
                }
            }
            int len = a.size();
            for (int i = 0; i < len; i++) {
                std::cout << "*" << a[i];
            }
        } else {
            if (n1 == 1) {
                std::cout << "(1*" << a[0] << ")";
                int len = a.size();
                for (int i = 1; i < len; i++) {
                    std::cout << "*" << a[i];
                }
            } else {
                while (n1 - 3 >= 0) {
                    if (n1 - 4 == 0) {
                        std::cout << "(1+1+1+1)";
                        n1 -= 4;
                        break;
                    }
                    std::cout << "(1+1+1)";
                    n1 -= 3;
                    if (n1 != 0) {
                        std::cout << "*";
                    }
                }
                if (n1 == 2) {
                    std::cout << "(1+1)";
                }
                int len = a.size();
                for (int i = 0; i < len; i++) {
                    std::cout << "*" << a[i];
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}