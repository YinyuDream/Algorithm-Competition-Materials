#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]-=i;
    }
    map<int,int>cnt;
    multiset<int> st;
    for(int i=1;i<=k;i++)
        cnt[a[i]]++;
    for(auto [x,y]:cnt){
        st.insert(y);
    }
    for(int i=k+1;i<=n;i++)
        if(cnt.find(a[i])==cnt.end())
            cnt.insert({a[i],0});
    vector<int> ans(n+1);
    ans[1]=k-*st.rbegin();
    for(int i=2;i+k-1<=n;i++){
        st.erase(st.find(cnt[a[i-1]]));
        cnt[a[i-1]]--;
        if(cnt[a[i-1]]>0)
            st.insert(cnt[a[i-1]]);
        if(cnt[a[i+k-1]]!=0)
            st.erase(st.find(cnt[a[i+k-1]]));
        cnt[a[i+k-1]]++;
        st.insert(cnt[a[i+k-1]]);
        ans[i]=k-*st.rbegin();
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<ans[l]<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}