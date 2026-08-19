#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k,c;
    cin>>n>>c>>k;
    string s;
    cin>>s;
    s=" "+s;
    vector<int> cnt(c);
    int val=0;
    set<int>st;
    for(int i=0;i<(1<<c);i++)
        if(i&(1<<(s.back()-'A')))
            st.insert(i);
    for(int i=1;i<=k;i++){
        cnt[s[i]-'A']++;
        val|=(1<<(s[i]-'A'));
    }
    st.erase((~val)&((1<<c)-1));
    for(int i=k+1;i<=n;i++){
        cnt[s[i-k]-'A']--;
        if(cnt[s[i-k]-'A']==0)
            val^=(1<<(s[i-k]-'A'));
        cnt[s[i]-'A']++;
        val|=(1<<(s[i]-'A'));
        st.erase((~val)&((1<<c)-1));
    }
    int ans=c;
    for(auto it:st)
        ans=min(ans,__builtin_popcount(it)),cout<<it<<endl;
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