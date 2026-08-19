#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int addmod(int a,int b){ a+=b; if(a>=MOD) a-=MOD; return a;}
int submod(int a,int b){ a-=b; if(a<0) a+=MOD; return a;}
long long mulmod(long long a,long long b){ return (a*b)%MOD; }
long long modpow(long long a,long long e=MOD-2){
    long long r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD; e>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    int maxNsum = 400000; // problem constraint
    // Precompute factorials / invfacts and involution numbers up to maxNsum
    int MAX = maxNsum + 5;
    vector<long long> fact(MAX), invfact(MAX);
    fact[0]=1;
    for(int i=1;i<MAX;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAX-1]=modpow(fact[MAX-1]);
    for(int i=MAX-2;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%MOD;
    auto C = [&](int n,int k)->long long{
        if(k<0 || k>n) return 0;
        return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
    };
    // involution numbers I[n] with recurrence I[n]=I[n-1] + (n-1)*I[n-2]
    vector<long long> I(MAX);
    I[0]=1;
    if(MAX>1) I[1]=1;
    for(int i=2;i<MAX;i++){
        I[i] = ( I[i-1] + (long long)(i-1) * I[i-2] ) % MOD;
    }

    while(T--){
        int n; cin>>n;
        vector<long long> a(n+1);
        for(int i=0;i<=n;i++) cin>>a[i];
        bool bad=false;
        // Given guarantee a0 and a_n are -1 in input, but we'll still handle generically.
        // Check bounds
        for(int i=0;i<=n;i++){
            if(a[i]!=-1){
                if(a[i]<0 || a[i]>n) { bad=true; break; }
            }
        }
        if(bad){
            cout<<0<<"\n"; continue;
        }
        // propagate reciprocity: for any i with a[i]>0, enforce a[a[i]]==i
        queue<int>q;
        vector<long long> val = a; // working copy
        for(int i=0;i<=n;i++){
            if(val[i]>0){
                q.push(i);
            }
        }
        while(!q.empty() && !bad){
            int i=q.front(); q.pop();
            int j = (int)val[i];
            if(j<0 || j>n){ bad=true; break; }
            if(val[j]==-1){
                val[j]=i;
                if(val[j]>0) q.push(j);
            } else {
                if(val[j] != i){
                    bad=true; break;
                }
            }
        }
        if(bad){
            cout<<0<<"\n"; continue;
        }
        // After propagation ensure consistency: for any i with val[i]>0, val[val[i]]==i
        for(int i=0;i<=n;i++){
            if(val[i]>0){
                int j=(int)val[i];
                if(j<0 || j>n || val[j]!=i){ bad=true; break; }
            }
        }
        if(bad){
            cout<<0<<"\n"; continue;
        }
        // a_n must be >0 (degree n coefficient not 0)
        if(val[n]==0){
            cout<<0<<"\n"; continue;
        }
        // classify nodes 1..n
        vector<int> state(n+1,0);
        // states: 0=free (val==-1), 1=forced_zero (val==0), 2=forced_fixed (val==i), 3=forced_pair (val==j != i)
        for(int i=1;i<=n;i++){
            if(val[i]==-1) state[i]=0;
            else if(val[i]==0) state[i]=1;
            else if(val[i]==i) state[i]=2;
            else state[i]=3;
        }
        // verify forced_pair nodes are consistent (pairs appear twice). Already ensured by propagation.
        // Count free nodes
        int m = 0;
        for(int i=1;i<=n;i++) if(state[i]==0) m++;
        // Check whether n is already forced into P (i.e., state[n]==2 or 3)
        bool n_inP_forced = (state[n]==2 || state[n]==3);
        // if n is forced zero -> already returned 0 earlier
        long long ans = 0;
        if(n_inP_forced){
            // sum_{q=0..m} C(m,q) * I[q]
            for(int qcnt=0;qcnt<=m;qcnt++){
                long long ways = C(m, qcnt) * I[qcnt] % MOD;
                ans += ways; if(ans>=MOD) ans-=MOD;
            }
        } else {
            // n is free and must be included => choose subsets Q of free nodes that include n
            if(m==0){
                // No free nodes but n not in forced P -> impossible (can't include n). Shouldn't happen because n would be free but m==0 means none free -> contradiction.
                ans = 0;
            } else {
                // We can count by fixing n as chosen, then choose q-1 other chosen from m-1 free others.
                for(int qcnt=1;qcnt<=m;qcnt++){
                    // qcnt is number chosen in P among free nodes (including n)
                    long long waysChoose = C(m-1, qcnt-1);
                    long long waysInvol = I[qcnt]; // involutions on those qcnt chosen free nodes
                    long long add = waysChoose * waysInvol % MOD;
                    ans += add; if(ans>=MOD) ans-=MOD;
                }
            }
        }
        cout<<ans%MOD<<"\n";
    }
    return 0;
}
