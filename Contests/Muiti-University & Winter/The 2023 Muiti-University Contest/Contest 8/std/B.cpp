#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const double eps = 1e-8;
const int mod = 998244353, gen = 3;

inline int add(int x, int y) 
{
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) 
{
    return x - y >= 0 ? x - y : x - y + mod;
}

inline int qpow(int x, int times)
{
    int res = 1;
    while(times)
    {
        if(times & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        times >>= 1;
    }
    return res;
}

namespace Combin 
{
    std::vector<int> inv, fac, invf;
    void getCombin(int n) 
    {
        if (inv.empty()) { inv = fac = invf = std::vector<int> (2, 1); }
        int m = inv.size(); n ++;
        if (m < n) 
        {
            inv.resize(n); fac.resize(n); invf.resize(n);
            for (int i = m; i < n; i ++) 
            {
                inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
                fac[i] = 1ll * fac[i - 1] * i % mod;
                invf[i] = 1ll * invf[i - 1] * inv[i] % mod;
            }
        }
    }
    inline int binom(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        getCombin(n);
        return 1ll * fac[n] * invf[m] % mod * invf[n - m] % mod; 
    }
}

using namespace Combin;

namespace Polynom 
{
    std::vector<int> rev, rt;

    void getRevRoot(int n) 
    {
        int m = log(n) / log(2) + eps;
        rev.resize(n);
        for (int i = 1; i < n; i ++)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << m - 1;
        static int len = 1;
        if (len < n) 
        {
            rt.resize(n);
            for (; len < n; len <<= 1) 
            {
                int uni = qpow(gen, (mod - 1) / (len * 2));
                rt[len] = 1;
                for (int i = 1; i < len; i ++) 
                    rt[i + len] = 1ll * rt[i + len - 1] * uni % mod;
            }
        }
    }
    void ntt(std::vector<int> &f, int n) 
    {
        f.resize(n);
        for (int i = 0; i < n; i ++) 
            if (i < rev[i]) std::swap(f[i], f[rev[i]]);
        for (int len = 1; len < n; len <<= 1) 
            for (int i = 0; i < n; i += len * 2) 
                for (int j = 0; j < len; j ++) 
                {
                    int x = f[i + j], y = 1ll * f[i + j + len] * rt[j + len] % mod;
                    f[i + j] = add(x, y); f[i + j + len] = sub(x, y);
                }
    }
    std::vector<int> operator *(std::vector<int> f, std::vector<int> g) 
    {
        int n = 1, m = f.size() + g.size(); 
        m --;
        while (n < m) n <<= 1;
        int invn = qpow(n, mod - 2);
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i ++) f[i] = 1ll * f[i] * g[i] % mod;
        std::reverse(f.begin() + 1, f.end()); ntt(f, n); f.resize(m);
        for (int i = 0; i < m; i ++) f[i] = 1ll * f[i] * invn % mod;
        return f;
    }

    std::vector<int> polyInv(std::vector<int> f, int n) 
    {
        if (n == 1) return std::vector<int>(1, qpow(f[0], mod - 2));
        f.resize(n);
        std::vector<int> g = polyInv(f, n / 2), h(n);
        g.resize(n);
        for (int i = 0; i < n / 2; i ++) h[i] = g[i];
        int invn = qpow(n, mod - 2);
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i ++) f[i] = 1ll * f[i] * g[i] % mod; 
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        for (int i = 1; i < n / 2; i ++) f[i] = 0;
        for (int i = n / 2; i < n; i ++) f[i] = 1ll * f[i] * invn % mod;
        f[0] = 1; ntt(f, n);
        for (int i = 0; i < n; i ++) f[i] = 1ll * f[i] * g[i] % mod;
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        for (int i = n / 2; i < n; i ++) h[i] = sub(0, 1ll * f[i] * invn % mod);
        return h;
    }
    std::vector<int> operator ~(std::vector<int> f) 
    {
        if (f.empty()) return f;
        int n = 1, m = f.size();
        while (n < m) n *= 2;
        f = polyInv(f, n); f.resize(m);
        return f;
    }
    
    std::vector<int> polyDeri(std::vector<int> f) 
    {
        if (f.empty()) return f;
        int m = f.size();
        for (int i = 1; i < m; i ++) f[i - 1] = 1ll * f[i] * i % mod;
        f.pop_back();
        return f;
    }
    std::vector<int> polyInte(std::vector<int> f) 
    {
        f.push_back(0);
        int m = f.size();
        getCombin(m);
        for (int i = m - 1; i >= 1; i--) { f[i] = 1ll * f[i - 1] * inv[i] % mod; }
        f[0] = 0;
        return f;
    }
    
    std::vector<int> polyLn(std::vector<int> f) 
    {
        if (f.empty()) { return f; }
        int m = f.size();
        f = (~f) * polyDeri(f);
        f.resize(m); f = polyInte(f); f.pop_back();
        return f;
    }
    std::vector<int> polyExp(std::vector<int> f, int n) 
    {
        if (n == 1) { return std::vector<int> (1, 1); }
        f.resize(n);
        std::vector<int> g = polyExp(f, n / 2), h(n), g0;
        g.resize(n); g0 = polyLn(g);
        for (int i = 0; i < n / 2; i++) { h[i] = g[i]; }
        for (int i = 0; i < n; i++) { f[i] = sub(g0[i], f[i]); }
        int invn = qpow(n, mod - 2);
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i++) { f[i] = 1ll * f[i] * g[i] % mod; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        for (int i = n / 2; i < n; i++) { h[i] = sub(0, 1ll * f[i] * invn % mod); }
        return h;
    }
    std::vector<int> polyExp(std::vector<int> f) 
    {
        if (f.empty()) { return f; }
        int n = 1, m = f.size();
        while (n < m) { n *= 2; }
        f = polyExp(f, n); f.resize(m);
        return f;
    }
}

using Polynom::operator ~;
using Polynom::operator *;

int n, k;
std::vector<int> f, g;

int main() 
{
    scanf("%d%d", &n, &k); 
    f.resize(n + 1); g.resize(n + 1); getCombin(n + 2);
    for (int i = 0; i <= n; i ++) g[i] = i ? 1ll * qpow(2, i * (i - 1ll) / 2 % (mod - 1)) * invf[i] % mod : 0, f[i] = g[i];
    g[0] = add(g[0], 1); f = f * ~g; g = f;
    f.resize(k + 1); f.resize(n + 1);
    g.resize(k); g.resize(n + 1);
    for (int i = 0; i <= n; i ++) { f[i] = sub(0, f[i]); g[i] = sub(0, g[i]); }
    f[0] = add(f[0], 1); g[0] = add(g[0], 1); f = ~f; g = ~g;
    printf("%lld\n", 1ll * sub(f[n], g[n]) * fac[n] % mod);
    return 0;
}