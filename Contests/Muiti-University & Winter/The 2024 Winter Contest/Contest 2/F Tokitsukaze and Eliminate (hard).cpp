#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<int>> pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    set<int> st;
    for(int i=1;i<=n;i++){
        if(pos[i].size()){
            st.insert(pos[i].back());
        }
    }
    int ans=0,now=n;
    while(st.size()){
        ans++;
        int p=*st.begin();
        while(now>=p){
            pos[a[now]].pop_back();
            if(st.find(now)!=st.end()){
                st.erase(now);
                if(pos[a[now]].size()){
                    st.insert(pos[a[now]].back());
                }
            }
            now--;
        }
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