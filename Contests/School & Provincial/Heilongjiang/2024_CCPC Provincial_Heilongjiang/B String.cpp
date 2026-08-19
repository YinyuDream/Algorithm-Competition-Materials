#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    std::string s;
    std::cin >> s;
    std::deque<char> l;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        l.push_back(s[i]);
        if (l.size() >= 3) {
            int ll = l.size();  
            bool check = true;
            for (int j = ll - 1; j >= ll - 2; j--) {
                if (l[j] != l[j - 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                int t = 3;
                while (t--) {
                    l.pop_back();
                }
            }
        }
    }
    if (l.size() == 0) {
        std::cout << "NAN";
    }
    else {
        int llen = l.size();
        for (int i = 0; i < llen; i++) {
            std::cout << l[i];
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}