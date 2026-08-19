#include<bits/stdc++.h>
using i64 = long long;
constexpr int MAX = 1e6 + 1;
int a[MAX];
void solve()
{
    int n;
    std::cin >> n;
    int ans = a[n];
    // std::cout << ans << "\n";
    if (ans == 0) {
        std::cout << "Pinkie Pie";
    }
    else if ((ans ^ 1) == 0 || (ans ^ n) == 0) {
        std::cout << "Fluttershy";
    }
    else {
        if (n % 2 == 0) {
            std::cout << "Pinkie Pie";
        }
        else {
            std::cout << "Fluttershy";
        }
    }
    std::cout << "\n";
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 1; i <= MAX; i++) {
        a[i] = a[i - 1] ^ i;
    }
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
	 			 					 		 		  			 	 	