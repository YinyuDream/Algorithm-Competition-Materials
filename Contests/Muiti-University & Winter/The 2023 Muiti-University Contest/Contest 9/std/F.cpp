#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 16;
const int M = 30;
bool ok1[N+5][M+5];
bool ok2[M+5][N+5];
int num[M+5];
int Bnum[N+5];
vector<pair<int,int> > B;
int wz[8];
int c[45][45];
ll f[45][100];
int w[10];
int n , m , a, b;
void upd(ll &x,ll y)
{
    x += y;
}
void solve()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    memset(ok1 , 1 , sizeof(ok1)) ; memset(ok2 , 1 , sizeof(ok2)) ;
    memset(Bnum , 0 , sizeof(Bnum));
    for(int i = 1;i <= m;i++) {
        int d;scanf("%d",&d); Bnum[d]++;
    }
    for(int i = 1;i <= a;i++) {
        int u , v;scanf("%d%d",&u,&v) ; ok1[u][v] = 0;
    }
    for(int i = 1;i <= b;i++) {
        int u , v;scanf("%d%d",&u,&v) ; ok2[u][v] = 0;
    }


    B.clear();
    for(int i = 1;i <= n;i++) {
        if(Bnum[i]) B.push_back(pair<int,int>{i , Bnum[i]});
    }
    for(int i = 0;i < B.size();i++) {
        if(i == 0) wz[i] = 1;
        else wz[i] = wz[i - 1]*(B[i - 1].second + 1);
    }
    int sz = wz[B.size() - 1] * (B.back().second + 1);
    int BS = B.size();
    int ans = 0;
    for(int i = 0;i < (1<<n);i++) {
        for(int j = 1;j <= m;j++) {
            num[j] = 0;
            for(int k = 1;k <= n;k++) {
                if(((i >> k - 1) & 1) && ok1[k][j]) num[j]++;
            }
        }
        memset(f,0,sizeof(f)) ;
        f[0][0] = 1;
        for(int j = 0;j < m;j++) {
            memset(w,0,sizeof(w));
            for(int k = 0;k < sz;k++) {
                if(f[j][k]) {
                    f[j][k] %= mod;
                    if(ok2[j + 1][0]) {upd(f[j + 1][k] , f[j][k]) ; }
                    for(int l = 0;l < BS && B[l].first <= num[j + 1];l++) {
                        if(w[l] < B[l].second && ok2[j + 1][B[l].first] ) {
                            upd(f[j + 1][k + wz[l]] , f[j][k]*c[num[j + 1]][B[l].first]) ;
                        }
                    }
                }
                for(int l = 0;l < BS;l++) {
                    if(w[l] == B[l].second) w[l] = 0;
                    else {w[l]++ ; break;}
                }
            }
        }
        int d = 0;
        for(int j = 1;j <= n;j++) {
            if((i >> j - 1) & 1) d++;
        }
        f[m][sz - 1] %= mod;
        if((n - d) & 1) ans = (ans - f[m][sz - 1] + mod) % mod;
        else ans = (ans + f[m][sz - 1])%mod;
    }
    printf("%d\n",ans); return;
}
int main()
{
    c[0][0] = 1;
    for(int i = 1;i <= 40;i++) {
        c[i][0] = 1;
        for(int j = 1;j <= i;j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    int t;scanf("%d",&t);
    while(t--) solve();
    return 0;
}
