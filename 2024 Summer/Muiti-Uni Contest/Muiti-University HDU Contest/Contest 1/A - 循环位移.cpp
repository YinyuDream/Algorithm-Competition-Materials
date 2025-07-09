#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p1=131,p2=133,mod=998244353;
void solve(){
    
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s=" "+s+s;
    t=" "+t;
    vector<ll> hash_s_1(n*2+1),hash_t_1(m+1),p_pow_1(max(n*2+1,m+1));
    vector<ll> hash_s_2(n*2+1),hash_t_2(m+1),p_pow_2(max(n*2+1,m+1));
    p_pow_1[0]=p_pow_2[0]=1;
    set<pair<ll,ll>> st;
    for(int i=1;i<=max(n*2,m);i++){
        p_pow_1[i]=p_pow_1[i-1]*p1%mod;
        p_pow_2[i]=p_pow_2[i-1]*p2%mod;
    }
    for(int i=1;i<=n*2;i++){
        hash_s_1[i]=(hash_s_1[i-1]*p1+s[i])%mod;
        hash_s_2[i]=(hash_s_2[i-1]*p2+s[i])%mod;
    }
    for(int i=1;i<=m;i++){
        hash_t_1[i]=(hash_t_1[i-1]*p1+t[i])%mod;
        hash_t_2[i]=(hash_t_2[i-1]*p2+t[i])%mod;
    }
    for(int i=1;i<=n;i++){
        ll h1=(hash_s_1[i+n-1]-hash_s_1[i-1]*p_pow_1[n])%mod;
        if(h1<0) h1+=mod;
        ll h2=(hash_s_2[i+n-1]-hash_s_2[i-1]*p_pow_2[n])%mod;
        if(h2<0) h2+=mod;
        st.insert({h1,h2});
    }
    int ans=0;
    for(int i=1;i+n-1<=m;i++){
        ll h1=(hash_t_1[i+n-1]-hash_t_1[i-1]*p_pow_1[n])%mod;
        if(h1<0) h1+=mod;
        ll h2=(hash_t_2[i+n-1]-hash_t_2[i-1]*p_pow_2[n])%mod;
        if(h2<0) h2+=mod;
        if(st.count({h1,h2})) ans++;
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}