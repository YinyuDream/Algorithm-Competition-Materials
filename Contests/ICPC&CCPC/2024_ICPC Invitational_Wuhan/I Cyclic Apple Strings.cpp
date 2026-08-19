#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    std::string s;
    std::cin >> s;
    int len = s.size(), num = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '1' && i + 1 < len && s[i + 1] == '0') {
            num++;
        }
    }
    std::cout << num;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
  	  		 		 	 			     	 		 	 			