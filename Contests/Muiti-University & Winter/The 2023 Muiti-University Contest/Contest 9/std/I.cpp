#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> seg;
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
seg s[N][2];
int n , m ;
int fpow(int a,int b)
{
    int ans = 1;
    while(b) {
        if(b & 1) ans = 1LL*ans*a%mod;
        a = 1LL*a*a%mod;b >>= 1;
    }
    return ans;
}
int dif[N][2];
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d%d%d%d",&s[i][0].first,&s[i][0].second,&s[i][1].first,&s[i][1].second);
    for(int i = 1;i <= n;i++) {
        if(s[i][0] > s[i][1]) swap(s[i][0] , s[i][1]);
        m = max(s[i][0].second , m);
        m = max(s[i][1].second , m);
    }
    for(int i = 1;i <= n;i++) {
        if(s[i][0].second >= s[i][1].first) dif[s[i][0].first][0]++ , dif[max(s[i][1].second,s[i][0].second) + 1][0]-- ,
            dif[s[i][1].first][1]++ , dif[min(s[i][0].second,s[i][1].second)+1][1]--;
        else {
            dif[s[i][0].first][0]++;dif[s[i][0].second + 1][0]--;
            dif[s[i][1].first][0]++;dif[s[i][1].second + 1][0]--;
        }
    }
    int ans = 0;
    for(int i = 1;i <= m;i++) {
        dif[i][0] += dif[i - 1][0];
        dif[i][1] += dif[i - 1][1];
        if(dif[i][0] == n) {ans = (ans + fpow(2 , dif[i][1])) % mod;}
    }
    memset(dif , 0 , sizeof(dif));
    for(int i = 1;i <= n;i++) {
        if(s[i][0].second  - 1 >= s[i][1].first) dif[s[i][0].first][0]++ , dif[max(s[i][1].second,s[i][0].second)][0]-- ,
            dif[s[i][1].first][1]++ , dif[min(s[i][0].second,s[i][1].second)][1]--;
        else {
            dif[s[i][0].first][0]++;dif[s[i][0].second][0]--;
            dif[s[i][1].first][0]++;dif[s[i][1].second][0]--;
        }
    }
    for(int i = 1;i < m;i++) {
        dif[i][0] += dif[i - 1][0];
        dif[i][1] += dif[i - 1][1];
        if(dif[i][0] == n) {ans = (ans - fpow(2 , dif[i][1]) + mod) % mod;}
    }
    printf("%d\n",ans);
    return 0;
}
