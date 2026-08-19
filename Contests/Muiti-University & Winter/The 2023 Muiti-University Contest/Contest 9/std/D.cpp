#include<bits/stdc++.h>
using namespace std;
int n;
int p[5005];
int s[5005][5005];
void add(int l,int ql,int qr)
{
    s[l][ql]++ ; s[l][qr + 1]--;
}
void solve()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> p[i];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) s[i][j] = 0;
    }
    for(int i = 1;i <= n;i++) {
        int nr = i , r = i , sum = 0;
        for(int l = i;l >= 1;l--) {
            if(p[l] <= p[i]) sum++ ;
            while(r < n && sum < i - l + 1) {
                r++ ; nr = r;
                if(p[r] <= p[l]) sum++;
            }
            if(sum == i - l + 1) {

                while(r < n && p[r + 1] > p[i]) r++;
                add(l , nr , r);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            s[i][j] += s[i][j - 1];
            if(!s[i][j] && i <= j) {ans++;}
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
}
