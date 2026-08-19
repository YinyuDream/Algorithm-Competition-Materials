#include <bits/stdc++.h>

#define ull unsigned long long

const int MAX_N = 1e3 + 10 , MAX_K = 20 + 5 , MAX_P = 20 + 5 , mod = 998244353 ;

std::vector<int> l , r , totr , g ;

char sl[MAX_N] , sr[MAX_N] ;
int n , k , p , C[MAX_K][MAX_K] ;
ull h[3][2][MAX_P][MAX_K] , f[MAX_N][MAX_K][MAX_P][2] ;

void fixed(std::vector<int> &l) {
   for (int i = 0 ; i < l.size() - 1 ; ++i) if (l[i] > 9) l[i + 1] += l[i] / 10 , l[i] %= 10 ;
   while ((*l.rbegin()) > 9) {
      int x = (*l.rbegin()) / 10 ;
      *l.rbegin() %= 10 ;
      l.push_back(x) ;
   }
}

int solve(int K) {
   std::vector<int> offset ;
   if (K == 0) offset = l ;
   else {
      offset.resize(std::max(l.size() , r.size())) ;
      for (int i = 0 ; i < offset.size() ; ++i)
         offset[i] = (i < l.size() ? l[i] : 0) + (i < r.size() ? r[i] : 0) * K ;
      fixed(offset) ;
   }
   if (offset.size() > totr.size()) return 0 ;

   int mx = g.size() ;
   f[n][0][0][1] = 1 ;
   for (int i = n ; i ; --i) {
      int cap = totr[i - 1] , num = i - 1 < offset.size() ? offset[i - 1] : 0 ;

      for (int ty = 0 ; ty < 2 ; ++ty)
         for (int md = 0 ; md < p ; ++md) {
            for (int t = 0 ; t < 10 ; ++t) {
               int bias = (t + num) / 10 ;
               h[0][ty][md][t] = h[1][ty][md][t] = h[2][ty][md][t] = 0 ;
               for (int nt = t , step = 0 ; nt < mx ; nt += 10 , ++step) {
                  h[0][ty][md][t] += 1ll * g[nt] * f[i][bias + step][md][ty] ;
                  h[1][ty][md][t] += 1ll * g[nt] * f[i][bias + step + 1][md][ty] ;
                  h[2][ty][md][t] += 1ll * g[nt] * f[i][bias + step + 2][md][ty] ;
                  if (step == 10)
                     h[0][ty][md][t] %= mod , h[1][ty][md][t] %= mod , h[2][ty][md][t] %= mod ;
               }
               h[0][ty][md][t] %= mod ; h[1][ty][md][t] %= mod ; h[2][ty][md][t] %= mod ;
            }
         }

      for (int c = 0 ; c <= k ; ++c)
         for (int md = 0 ; md < p ; ++md) {
            int bias = c + num ;
            f[i - 1][c][md][0] = f[i - 1][c][md][1] = 0 ;

            for (int t = 0 ; t < 10 ; ++t) {
               int v = (t + bias) % 10 , step = (t + bias) / 10 - (t + num) / 10 , pmd = md - (v * v - v) ;
               pmd = (pmd % p + p) % p ;

               f[i - 1][c][md][0] += h[step][0][pmd][t] ;
               if (v == cap) f[i - 1][c][md][1] += h[step][1][pmd][t] ;
               else if (v < cap) f[i - 1][c][md][0] += h[step][1][pmd][t] ;

               if (t == 7) f[i - 1][c][md][0] %= mod ;
            }
            f[i - 1][c][md][0] %= mod ; f[i - 1][c][md][1] %= mod ;
         }
   }

   return (f[0][0][0][0] + f[0][0][0][1]) % mod ;
}

int main() {
   scanf("%d %d %s %s" , &k , &p , sl , sr) ;
   
   ///

   for (int i = 0 , len = strlen(sl) ; i < len ; ++i) l.push_back(sl[i] - '0') ;
   for (int i = 0 , len = strlen(sr) ; i < len ; ++i) r.push_back(sr[i] - '0') ;
   std::reverse(l.begin() , l.end()) ;
   std::reverse(r.begin() , r.end()) ;
   
   totr = r ;
   for (int i = 0 ; i < r.size() ; ++i) r[i] -= i < l.size() ? l[i] : 0 ;
   for (int i = 0 ; i < r.size() ; ++i) if (r[i] < 0) r[i] += 10 , --r[i + 1] ;
   while (r.size() > 1 && !(*r.rbegin())) r.pop_back() ;

   ++r[0] ;
   for (auto &x : l) x *= k ;
   for (auto &x : totr) x *= k ;
   fixed(l) ; fixed(r) ; fixed(totr) ;

   ///

   C[0][0] = 1 ;
   for (int i = 1 ; i <= k ; ++i) {
      C[i][0] = 1 ;
      for (int j = 1 ; j <= k ; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod ;
   }

   int mx = k * 9 ; g.resize(mx + 1) ;
   std::vector<int> sum(mx + 1 , 0) ;

   g[0] = 1 ;
   for (int t = 0 ; t < k ; ++t) {
      sum[0] = g[0] ;
      for (int p = 1 ; p <= mx ; ++p) sum[p] = (sum[p - 1] + g[p]) % mod ;
      for (int p = 0 ; p <= mx ; ++p) {
         int l = p - 10 ;
         g[p] = l >= 0 ? sum[p] - sum[l] : sum[p] ;
         g[p] = (g[p] + mod) % mod ;
      }
   }

   ///

   n = totr.size() ; int ans = 0 ;
   for (int i = 0 ; i <= k ; ++i) {
      int tmp = 1ll * solve(i) * C[k][i] % mod ;
      if (i & 1) tmp = mod - tmp ;
      (ans += tmp) %= mod ;
   }
   printf("%d\n" , ans) ;

   return 0 ;
}
