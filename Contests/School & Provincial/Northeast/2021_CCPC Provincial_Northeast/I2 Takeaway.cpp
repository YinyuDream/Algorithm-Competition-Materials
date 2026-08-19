#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n;
    std::cin >> n;
    int a[8] = {0,7,27,41,49,63,78,108};
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        sum += a[tmp];
    }
    if (sum >= 69 && sum < 89) {
        std::cout << sum - 15 << "\n";
    }
    else if (sum >= 89 && sum < 120) {
        std::cout << sum - 30 << "\n";
    }
    else if (sum >= 120) {
        std::cout << sum - 50 << "\n";
    }
    else {
        std::cout << sum << "\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
 	 	 		 	     					     		  	 	