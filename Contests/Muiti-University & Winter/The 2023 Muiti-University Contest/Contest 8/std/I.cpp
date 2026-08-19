// Created by calabash_boy
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif
#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)
#define range(x) x.begin(),x.end()
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
mt19937 wdy(time(0));
/************* header ******************/
const int maxn = 1e6 + 5;
const int mod = 998244353;
int x;
int ans[maxn];
struct KMP{
    int nxt[maxn];int len;
    void clear(){
        len = nxt[0] = nxt[1] =0;
    }
    KMP(){clear();}
    /* 1-bas */
    void init(char* ss, int n){
        len = n;
        for (int i=2;i<=len;i++){
            nxt[i] = nxt[i-1];
            while (nxt[i]&&ss[i]!=ss[nxt[i]+1]) nxt[i] = nxt[nxt[i]];
            nxt[i]+=(ss[i]==ss[nxt[i]+1]);
        }
    }
    void debug(){
        for (int i=0;i<=len;i++){
            printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
        }
    }
}kmper;

// 1-base, |S| > |T|, psqt
void work1(char *s, int n, char *t, int m){
    int delta = (n - m) >> 1;
    bool subcheck = true;
    for (int i = 1; i <= m; i ++){
        subcheck &= t[i] == s[n - m - delta + i];
    }
    if (subcheck){
        // 1. |p| < delta
        kmper.init(s, n);
        for (int border = n; border >= 1; border = kmper.nxt[border]){
            if (border < delta){
                ans[delta - border]++;
            }
        }

        // 2. |p| >= delta
        int ans_t = 1;
        for (int i = delta ; i <= x; i ++){
            ans[i] = ans_t;
            ans_t = 26ll * ans_t % mod;
        }
    }
}

// 1-base |S| < |T|, psqt
void work2(char *s, int n, char *t, int m){
    int delta = (m - n) >> 1;
    bool subcheck = true;
    for (int i = 1; i  <= n; i ++){
        subcheck &= s[i] == t[delta + i];
    }
    if (subcheck){
        // 1. |p| < delta
        kmper.init(t, m);
        for (int border = m; border >= 1; border = kmper.nxt[border]){
            if (border < delta){
                ans[delta - border]++;
            }
        }

        // 2. |p| >= delta
        int ans_t = 1;
        for (int i = delta ; i <= x; i ++){
            ans[i] = ans_t;
            ans_t = 26ll * ans_t % mod;
        }
    }
}
char s[maxn];
char t[maxn];
int main(){
    scanf("%d",&x);
    scanf("%s",s + 1);
    scanf("%s", t + 1);
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    if (n == m && strcmp(s + 1, t + 1) == 0){
        int ans = 1;
        for (int i = 1; i <= x; i ++){
            ans = 26ll * ans % mod;
            printf("%d%c", ans, " \n"[i == x]);
        }
        return 0;
    }

    if (n == m || abs(n - m) % 2 != 0){
        for (int i = 1; i <= x; i ++){
            printf("0%c", " \n"[i == x]);
        }
        return 0;
    }

    if (n < m){
        work2(s, n, t, m);
    }else{
        work1(s, n, t, m);
    }

    for (int i =1; i <= x; i ++){
        printf("%d%c", ans[i], " \n"[i == x]);
    }
    return 0;
}