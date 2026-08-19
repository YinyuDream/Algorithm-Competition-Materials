#include<bits/stdc++.h>
using namespace std;
int n , k;
int a[1000005];
int b[35];
vector<int> vt;
bool Find(int x)
{
    auto it = lower_bound(vt.begin() , vt.end() , x);
    if(it == vt.end() || (*it) != x) return 0;
    return 1;
}
void solve()
{
    cin >> n >> k; vt.clear();
    vt.resize(n);
    for(int i = 1;i <= n;i++) {
        cin >> a[i] ; vt[i - 1] = a[i];
    }
    sort(vt.begin() , vt.end());
    vt.erase(unique(vt.begin() , vt.end()) , vt.end());
    for(int i = 1;i <= n;i++) {
        if(Find(a[i] ^ k)) {
            cout << "Alice\n" ; return ;
        }
    }
    memset(b,0,sizeof(b));
    for(int i = 0 ; i < vt.size();i++) {
        vt[i] ^= k;
        for(int j = 29;j >= 0;j--) {
            if((vt[i] >> j) & 1) {
                if(!b[j]) {b[j] = vt[i] ; break ;}
                vt[i] ^= b[j];
            }
        }
    }
    int c = 0;
    for(int i = 0;i <= 29;i++) {
        if(b[i]) {c++;}
    }
    if((1 << c) == vt.size()) {
        cout << "Bob\n";
    }
    else{
        cout << "Draw\n" ; return ;
    }
}
int main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);
    int t;cin >> t;
    while(t--) solve();
}
