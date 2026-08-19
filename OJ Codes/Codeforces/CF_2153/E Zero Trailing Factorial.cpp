#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    vector<pair<int,int>> tests(T);
    int global_limit = 0, maxN = 0;
    for(int i=0;i<T;++i){
        int n,m; cin >> n >> m;
        tests[i] = {n,m};
        global_limit = max(global_limit, min(n,m));
        maxN = max(maxN, n);
    }

    int S = max(2, global_limit);
    // sieve primes up to S (we need for q and for factoring primes list)
    vector<char> isprime(S+1, true);
    isprime[0] = isprime[1] = false;
    for(int p=2; (int64)p*p<=S; ++p){
        if(isprime[p]){
            for(int q = p*p; q<=S; q += p) isprime[q] = false;
        }
    }
    vector<int> primes;
    primes.reserve(S/10);
    for(int i=2;i<=S;++i) if(isprime[i]) primes.push_back(i);

    // For factoring numbers up to maxN we only need primes up to sqrt(maxN)
    int sqrtN = (int)floor(sqrt((double)maxN)) + 1;
    vector<int> smallPrimes;
    for(int p: primes){
        if(p > sqrtN) break;
        smallPrimes.push_back(p);
    }

    auto v_p_factorial = [](int n, int p)->int {
        int cnt = 0;
        int64 pp = p;
        while(pp <= n){
            cnt += n / pp;
            if(pp > (int64)n / p) break;
            pp *= p;
        }
        return cnt;
    };

    for(auto &tm : tests){
        int n = tm.first;
        int m = tm.second;
        int limit = min(n, m);

        // find q = largest prime <= limit
        int qprime = 1;
        if(limit >= 2){
            auto it = upper_bound(primes.begin(), primes.end(), limit);
            if(it != primes.begin()){
                --it;
                qprime = *it;
            }
        }

        if(qprime > n-1){
            cout << 0 << '\n';
            continue;
        }

        // interval ys = qprime+1 ... n  (length L)
        int L = n - qprime;
        vector<int> ys(L);
        for(int i=0;i<L;++i) ys[i] = qprime + 1 + i;

        // Factor each y in ys, but only record prime factors p <= m (others irrelevant)
        // store per-index vector of (p,exp)
        vector<vector<pair<int,int>>> facs(L);
        for(int i=0;i<L;++i){
            int val = ys[i];
            int tmp = val;
            for(int p : smallPrimes){
                if((int64)p * p > tmp) break;
                if(tmp % p == 0){
                    int e = 0;
                    while(tmp % p == 0){
                        tmp /= p;
                        ++e;
                    }
                    if(p <= m) facs[i].emplace_back(p, e);
                }
            }
            if(tmp > 1){
                // tmp is prime
                if(tmp <= m) facs[i].emplace_back(tmp, 1);
            }
        }

        // Collect distinct primes that appear in facs
        unordered_map<int,int> p_to_idx;
        p_to_idx.reserve(L * 3 + 10);
        vector<int> plist;
        for(int i=0;i<L;++i){
            for(auto &pe : facs[i]){
                int p = pe.first;
                if(p_to_idx.find(p) == p_to_idx.end()){
                    int idx = (int)plist.size();
                    p_to_idx[p] = idx;
                    plist.push_back(p);
                }
            }
        }

        int D = (int)plist.size();
        // if no primes in interval, then all f_m(x,n)=0
        if(D == 0){
            cout << 0 << '\n';
            continue;
        }

        // add[d][i] will hold added exponent of prime d at position i (1..L)
        vector<vector<int>> add(D, vector<int>(L+1, 0));
        for(int i=0;i<L;++i){
            for(auto &pe : facs[i]){
                int p = pe.first, e = pe.second;
                int idx = p_to_idx[p];
                add[idx][i+1] += e; // position i+1 corresponds to ys[i]
            }
        }

        // build prefix sums for each prime: pref[d][k] = sum_{t=0..k-1} add[d][t+1]
        vector<vector<int>> pref(D, vector<int>(L+1, 0));
        for(int d=0; d<D; ++d){
            for(int i=0;i<L;++i){
                pref[d][i+1] = pref[d][i] + add[d][i+1];
            }
        }

        // compute Vn for each prime in plist
        vector<int> Vn(D);
        for(int d=0; d<D; ++d){
            int p = plist[d];
            Vn[d] = v_p_factorial(n, p);
        }

        // Now for each candidate x in [qprime, n-1], compute best value
        int64 total = 0;
        for(int x = qprime; x <= n-1; ++x){
            int idxX = x - qprime; // prefix index - sum over ys[idxX..L-1] = pref[L] - pref[idxX]
            int best = INT_MAX;
            for(int d=0; d<D; ++d){
                int p = plist[d];
                int Vn_p = Vn[d];
                int S = pref[d][L] - pref[d][idxX]; // sum v_p(t) for t in (x,n]
                int Vx = Vn_p - S;
                if(Vx == Vn_p) continue;

                // iterate exponents e while p^e <= m
                int64 powp = p;
                int e = 1;
                while(powp <= m){
                    int a = Vx / e;
                    int b = Vn_p / e;
                    if(a < b){
                        if(a < best) best = a;
                        if(best == 0) break;
                    }
                    ++e;
                    if(powp > (int64)m / p) break;
                    powp *= p;
                }
                if(best == 0) break;
            }
            if(best == INT_MAX) best = 0;
            total += best;
        }

        cout << total << '\n';
    }

    return 0;
}
