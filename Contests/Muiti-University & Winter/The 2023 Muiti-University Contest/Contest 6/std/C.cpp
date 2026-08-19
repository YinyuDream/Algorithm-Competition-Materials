#include<bits/stdc++.h>

using namespace std;
#define LL __int128
#define ll long long

LL solve(ll n) {
    LL ans = 0;
    if (n & 1) {
        LL k = 5;
        while (k <= n) {
            ans += ((n / k) + 1) / 2;
            k *= 5;
        }
        --n;
    }
    LL k = 5;
    while (k <= n) {
        LL m = n / k;
        ans += (m - 1) * m * (k / 2) / 2;
        ans += (2 * ((m - 1) / 2)) * ((m + 1) / 2) / 2;
        LL l = m * k, r = n;
        if (((l | r) & 1) == 0)++r;
        ans += m * (r - l + 1) / 2;
//        ans += (m - 1) * m * k / 2 + m * (n - m * k + 1);
        k *= 5;
    }
    return ans;
}

LL force(ll n) {
    LL ans = 0;
    if (n & 1) {
        for (LL i = 1; i <= n; i += 2) {
            LL j = i;
            while (j % 5 == 0) {
                ++ans;
                j /= 5;
            }
        }
        --n;
    }
    for (LL i = 2; i <= n; i += 2) {
        LL k = 5;
        while (k <= i) {
            ans += i / k;
            k *= 5;
        }
    }
    return ans;
}

void print(LL x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    ll n;
    cin >> n;
//    for (int i = 50000000; i <= 50000000; ++i) {
//        if (solve(i) != force(i)) {
//            cout << "solve(" << i;
//            cout << ") = ";
//            print(solve(i));
//            cout << ", force(" << i << ") = ";
//            print(force(i));
//            cout << endl;
//        }
//        assert(solve(i) == force(i));
//        if (i % 10000 == 0)cout << "i = " << i << ", ok" << endl;
//    }
//    puts("All performed");
    print(solve(n));
}