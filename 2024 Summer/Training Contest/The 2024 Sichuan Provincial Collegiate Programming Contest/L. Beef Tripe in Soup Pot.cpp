#include<bits/stdc++.h>
using ll = long long;
using namespace std;

struct node {
    int a, b;
};

bool cmp(node a, node b) {
    return a.a < b.a;
}

void solve() {
    ll n;
    cin >> n;
    vector<node> v, w;
    for (int i = 0; i < n; ++i) {
        int a, b;
        ll aa, bb;
        cin >> a >> b >> aa >> bb;
        if (aa + bb == 2) {
            if (a < b) {
                v.push_back({a, i + 1});
            } else {
                w.push_back({b, i + 1});
            }
        } else {
            if (aa == 1) {
                v.push_back({a, i + 1});
            } else if (bb == 1) {
                w.push_back({b, i + 1});
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    sort(w.begin(), w.end(), cmp);
    cout << v.size() << " ";
    for (auto x : v) {
        cout << x.b << " ";
    }
    cout << "\n";
    cout << w.size() << " ";
    for (auto x : w) {
        cout << x.b << " ";
    }
    cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}